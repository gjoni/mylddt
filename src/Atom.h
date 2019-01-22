#ifndef ATOM_H_
#define ATOM_H_

#include "AtomRecord.h"

class Residue;

class Atom {
private:

	char GetChemType(char name[]);

public:

	int atomNum; /* Atom serial number (PDB) */
	char name[5]; /* Atom name (PDB) */
	char altLoc; /* Alternate location indicator (PDB) */

	double x, y, z; /* Orthogonal coordinates for X, Y, Z (PDB) */

	double occup; /* Occupancy (PDB) */
	double temp; /* Temperature factor (PDB) */
	char element[3]; /* Element symbol, right-justified (PDB) */
	char charge[3]; /* Charge on the atom (PDB) */

	char chem_type; /* C, N, O, H, S, ... */

	Residue *residue; /* pointer to a Residue this atom belongs to */

	Atom();
	Atom(const Atom &source);
	Atom(const AtomRecord::Atom &source);

	~Atom();

	Atom& operator=(const Atom &source);
	Atom& operator=(const AtomRecord::Atom &source);

	static double Dist(const Atom &A, const Atom &B);

};

#endif /* ATOM_H_ */
