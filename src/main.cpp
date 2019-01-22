#include "Options.h"
#include "Chain.h"
#include "MyLDDT.h"

#include <vector>
#include <utility>

int main(int argc, char *argv[]) {

	//
	// (1) Initializations
	//
	OPTS opts = { "", "", "", "", 10.0, 1 };
	if (!GetOpts(argc, argv, opts)) {
		PrintOpts(opts);
		return 1;
	}

	Chain Model(opts.model);

	Chain *Ref = NULL;
	if (opts.ref != "") {
		Ref = new Chain;
		*Ref = Chain(opts.ref);
	}

	// make atom numbering in the Model sequential
	// and starting from zero
	// !!! very important !!!
	for (unsigned i = 0; i < Model.nAtoms; i++) {
		Model.atoms[i]->atomNum = i;
	}

	// additional data on the Model
	std::vector<std::pair<int, int> > bonds = Model.GetBonds();

	std::vector<std::tuple<int, int, double> > contacts = Model.GetContacts(opts.dmax);
/*
	if (opts.verb > 0) {
		printf("# %s\n", std::string(78, '-').c_str());
		printf("# %15s : %s\n", "model", opts.model.c_str());
		printf("# %s\n", std::string(78, '-').c_str());
		printf("# %15s   %9s %9s\n", "", "all", "missing");
		printf("# %15s : %9d %9d\n", "atoms", Model.nAtoms, Model.MaxAtoms() - Model.nAtoms);
		printf("# %15s : %9lu %9lu\n", "bonds", bonds.size(), Model.MaxBonds() - bonds.size());
		printf("# %15s : %9lu %9s   (%.1lfA)\n", "contacts", contacts.size(), "-", opts.dmax);
	}
*/
	//
	// (2) Run LDDT if Ref is set
	//
	MyLDDT::Result lddt_ts, lddt_ha;
	if (Ref != NULL) {
		MyLDDT lddt(Model, *Ref, opts.verb);
		lddt_ha = lddt.GetScore(MyLDDT::HA);
		lddt_ts = lddt.GetScore(MyLDDT::TS);
	}

	//
	// (3) Save results in JSON
	//
	if (opts.json != "") {

		FILE *F = fopen(opts.json.c_str(), "w");
		if (F == NULL) {
			fprintf(stderr, "ERROR: cannot open '%s' file for writing\n", 
				opts.json.c_str());
		}

		// atoms
		fprintf(F, "{\n\"atoms\":[");
		char buf[20];
		for (unsigned i = 0; i < Model.nAtoms; i++) {
			Atom *A = Model.atoms[i];
			sprintf(buf, "%s_%s", A->residue->name, A->name);
			if (i < Model.nAtoms - 1) {
				fprintf(F, "\"%s\",", buf);
			}
		}
		fprintf(F, "\"%s\"],\n\"bonds\":[", buf);

		// bonds
		for (unsigned i = 0; i < bonds.size() - 1; i++) {
			fprintf(F, "[%d,%d],", bonds[i].first, bonds[i].second);
		}
		fprintf(F,"[%d,%d]],\n\"contacts\":[",bonds.back().first, bonds.back().second);

		// contacts
		for (unsigned i = 0; i < contacts.size() - 1; i++) {
			int a = std::get<0>(contacts[i]);
			int b = std::get<1>(contacts[i]);
			double d = std::get<2>(contacts[i]);
			fprintf(F, "[%d,%d,%.3lf],", a, b, d);
		}
		fprintf(F, "[%d,%d,%.3lf]],\n\"scores\":[", std::get<0>(contacts.back()), std::get<1>(contacts.back()), std::get<2>(contacts.back()));

		// scores
		for (unsigned i = 0; i < lddt_ha.ascore.size() - 1; i++) {
			double ha = lddt_ha.ascore[i];
			double ts = lddt_ts.ascore[i];
			fprintf(F, "[%.5lf,%.5lf],", ha, ts);
		}
		fprintf(F, "[%.5lf,%.5lf]],\n", lddt_ha.ascore.back(), lddt_ts.ascore.back());
		fprintf(F, "\"lddt\":[%.5f,%.5f]\n}\n", lddt_ha.score, lddt_ts.score);

		fclose(F);
	}

	//
	// (4) Save cleaned PDB of the Model
	//
	if (opts.pdb != "") {

		// save LDDT atomic scores as B-factors
		if (Ref != NULL) {
			for (auto A : Model.atoms) {
				A->temp = lddt_ts.ascore[A->atomNum];
			}
		}
		Model.Save(opts.pdb);
	}

	//
	// clean up
	//
	if (Ref != NULL) {
		delete Ref;
	}

	return 0;

}

