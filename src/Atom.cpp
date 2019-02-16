#include "Atom.h"
#include "Math.h"

#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>

Atom::Atom() :
		atomNum(1), altLoc(' '), x(0.0), y(0.0), z(0.0), occup(0.0), temp(0.0),
		chem_type(' '), residue(NULL) {

	name[0] = '\0';
	x = y = z = 0.0;
	element[0] = '\0';
	charge[0] = '\0';
	memset(lfr, 0, 9 * sizeof(double));
	lfr[0][0] = lfr[1][1] = lfr[2][2] = 1.0;

}

Atom::Atom(const Atom &source) :
		atomNum(source.atomNum), altLoc(source.altLoc),
		x(source.x), y(source.y), z(source.z), occup(source.occup), temp(source.temp), 
		chem_type(source.chem_type), residue(source.residue) {

	strcpy(name, source.name);
	strcpy(element, source.element);
	strcpy(charge, source.charge);
	memcpy(lfr, source.lfr, 9 * sizeof(double));

}

Atom::Atom(const AtomRecord::Atom &source) :
		atomNum(source.atomNum), altLoc(source.altLoc),
		x(source.x), y(source.y), z(source.z), occup(source.occup), temp(source.temp),
		chem_type(' '), residue(NULL) {

	strcpy(name, source.atomName);
	strcpy(element, source.element);
	strcpy(charge, source.charge);
	chem_type = GetChemType(name);
	memset(lfr, 0, 9 * sizeof(double));
	lfr[0][0] = lfr[1][1] = lfr[2][2] = 1.0;

}

Atom::~Atom() {

	/* nothing to do */

}

Atom& Atom::operator =(const Atom& source) {

	assert(this != &source);

	atomNum = source.atomNum;
	altLoc = source.altLoc;
	strcpy(name, source.name);
	x = source.x;
	y = source.y;
	z = source.z;
	occup = source.occup;
	temp = source.temp;
	strcpy(element, source.element);
	strcpy(charge, source.charge);
	residue = source.residue;
	chem_type = source.chem_type;
	memcpy(lfr, source.lfr, 9 * sizeof(double));

	return *this;

}

Atom& Atom::operator =(const AtomRecord::Atom& source) {

	atomNum = source.atomNum;
	altLoc = source.altLoc;
	strcpy(name, source.atomName);
	x = source.x;
	y = source.y;
	z = source.z;
	occup = source.occup;
	temp = source.temp;
	strcpy(element, source.element);
	strcpy(charge, source.charge);
	residue = NULL;
	chem_type = GetChemType(name);
	memset(lfr, 0, 9 * sizeof(double));
	lfr[0][0] = lfr[1][1] = lfr[2][2] = 1.0;

	return *this;

}

char Atom::GetChemType(char name[]) {

	if (name[0] == '0' || name[0] == '1' || name[0] == '2' || name[0] == '3'
			|| name[0] == '4' || name[0] == '5' || name[0] == '6'
			|| name[0] == '7' || name[0] == '8' || name[0] == '9') {

		/* first letter is a number */
		return name[1];

	} else {

		/* all other cases */
		return name[0];

	}

}

double Atom::Dist(const Atom &A, const Atom &B) {

	double x = A.x - B.x;
	double y = A.y - B.y;
	double z = A.z - B.z;

	return sqrt(x * x + y * y + z * z);

}

int Atom::SetLFR(const Atom *A, const Atom *B, const Atom *C) {

	if (A == NULL || B == NULL || C == NULL) {
		return 1;
	}

	double a[3] = { B->x - A->x, B->y - A->y, B->z - A->z };
	double b[3] = { C->x - B->x, C->y - B->y, C->z - B->z };

	for (int i = 0; i < 3; i++) {
		lfr[2][i] = a[i] - b[i];
	}

	Math::cross(b, a, lfr[0]);
	Math::cross(lfr[2], lfr[0], lfr[1]);

	for (int i = 0; i < 3; i++) {
		double norm = sqrt(Math::dot(lfr[i], lfr[i]));
		for (int j = 0; j < 3; j++) {
			lfr[i][j] /= norm;
		}
	}

	return 0;

}
