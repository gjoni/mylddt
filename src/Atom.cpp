#include "Atom.h"

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

}

Atom::Atom(const Atom &source) :
		atomNum(source.atomNum), altLoc(source.altLoc),
		x(source.x), y(source.y), z(source.z), occup(source.occup), temp(source.temp), 
		chem_type(source.chem_type), residue(source.residue) {

	strcpy(name, source.name);
	strcpy(element, source.element);
	strcpy(charge, source.charge);

}

Atom::Atom(const AtomRecord::Atom &source) :
		atomNum(source.atomNum), altLoc(source.altLoc),
		x(source.x), y(source.y), z(source.z), occup(source.occup), temp(source.temp),
		chem_type(' '), residue(NULL) {

	strcpy(name, source.atomName);
	strcpy(element, source.element);
	strcpy(charge, source.charge);
	chem_type = GetChemType(name);

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
