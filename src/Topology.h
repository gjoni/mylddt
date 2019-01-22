/*
 * Topology.h
 *
 *  Created on: Oct 24, 2018
 *      Author: aivan
 */

#ifndef TOPOLOGY_H_
#define TOPOLOGY_H_

#include <map>
#include <set>
#include <utility>
#include <string>

using namespace std;

namespace topology {

const map<string, set<string> > CANONICAL20_ATOMS =
{
	{ "ALA", { "C", "CA", "CB", "N", "O" } },
	{ "ARG", { "C", "CA", "CB", "CD", "CG", "CZ", "N", "NE", "NH1", "NH2", "O" } },
	{ "ASN", { "C", "CA", "CB", "CG", "N", "ND2", "O", "OD1" } },
	{ "ASP", { "C", "CA", "CB", "CG", "N", "O", "OD1", "OD2" } },
	{ "CYS", { "C", "CA", "CB", "N", "O", "SG" } },
	{ "GLN", { "C", "CA", "CB", "CD", "CG", "N", "NE2", "O", "OE1" } },
	{ "GLU", { "C", "CA", "CB", "CD", "CG", "N", "O", "OE1", "OE2" } },
	{ "GLY", { "C", "CA", "N", "O" } },
	{ "HIS", { "C", "CA", "CB", "CD2", "CE1", "CG", "N", "ND1", "NE2", "O" } },
	{ "ILE", { "C", "CA", "CB", "CD1", "CG1", "CG2", "N", "O" } },
	{ "LEU", { "C", "CA", "CB", "CD1", "CD2", "CG", "N", "O" } },
	{ "LYS", { "C", "CA", "CB", "CD", "CE", "CG", "N", "NZ", "O" } },
	{ "MET", { "C", "CA", "CB", "CE", "CG", "N", "O", "SD" } },
	{ "PHE", { "C", "CA", "CB", "CD1", "CD2", "CE1", "CE2", "CG", "CZ", "N", "O" } },
	{ "PRO", { "C", "CA", "CB", "CD", "CG", "N", "O" } },
	{ "SER", { "C", "CA", "CB", "N", "O", "OG" } },
	{ "THR", { "C", "CA", "CB", "CG2", "N", "O", "OG1" } },
	{ "TRP", { "C", "CA", "CB", "CD1", "CD2", "CE2", "CE3", "CG", "CH2", "CZ2", "CZ3", "N", "NE1", "O" } },
	{ "TYR", { "C", "CA", "CB", "CD1", "CD2", "CE1", "CE2", "CG", "CZ", "N", "O", "OH" } },
	{ "VAL", { "C", "CA", "CB", "CG1", "CG2", "N", "O" } }
};

const map<string, set<pair<string, string> > > CANONICAL20_BONDS =
{
	{ "ALA", { { "N", "CA" }, { "CA", "C" }, { "C", "O" }, { "CA", "CB" } } },
	{ "ARG", { { "N", "CA" }, { "CA", "C" }, { "C", "O" }, { "CA", "CB" }, { "CB", "CG" }, { "CG", "CD" }, { "CD", "NE" }, { "NE", "CZ" }, { "CZ", "NH1" }, { "CZ", "NH2" } } },
	{ "ASN", { { "N", "CA" }, { "CA", "C" }, { "C", "O" }, { "CA", "CB" }, { "CB", "CG" }, { "CG", "OD1" }, { "CG", "ND2" } } },
	{ "ASP", { { "N", "CA" }, { "CA", "C" }, { "C", "O" }, { "CA", "CB" }, { "CB", "CG" }, { "CG", "OD1" }, { "CG", "OD2" } } },
	{ "CYS", { { "N", "CA" }, { "CA", "C" }, { "C", "O" }, { "CA", "CB" }, { "CB", "SG" } } },
	{ "GLN", { { "N", "CA" }, { "CA", "C" }, { "C", "O" }, { "CA", "CB" }, { "CB", "CG" }, { "CG", "CD" }, { "CD", "OE1" }, { "CD", "NE2" } } },
	{ "GLU", { { "N", "CA" }, { "CA", "C" }, { "C", "O" }, { "CA", "CB" }, { "CB", "CG" }, { "CG", "CD" }, { "CD", "OE1" }, { "CD", "OE2" } } },
	{ "GLY", { { "N", "CA" }, { "CA", "C" }, { "C", "O" } } },
	{ "HIS", { { "N", "CA" }, { "CA", "C" }, { "C", "O" }, { "CA", "CB" }, { "CB", "CG" }, { "CG", "ND1" }, { "ND1", "CE1" }, { "CG", "CD2" }, { "CD2", "NE2" }, { "CE1", "NE2" } } },
	{ "ILE", { { "N", "CA" }, { "CA", "C" }, { "C", "O" }, { "CA", "CB" }, { "CB", "CG1" }, { "CG1", "CD1" }, { "CB", "CG2" } } },
	{ "LEU", { { "N", "CA" }, { "CA", "C" }, { "C", "O" }, { "CA", "CB" }, { "CB", "CG" }, { "CG", "CD1" }, { "CG", "CD2" } } },
	{ "LYS", { { "N", "CA" }, { "CA", "C" }, { "C", "O" }, { "CA", "CB" }, { "CB", "CG" }, { "CG", "CD" }, { "CD", "CE" }, { "CE", "NZ" } } },
	{ "MET", { { "N", "CA" }, { "CA", "C" }, { "C", "O" }, { "CA", "CB" }, { "CB", "CG" }, { "CG", "SD" }, { "SD", "CE" } } },
	{ "PHE", { { "N", "CA" }, { "CA", "C" }, { "C", "O" }, { "CA", "CB" }, { "CB", "CG" }, { "CG", "CD1" }, { "CD1", "CE1" }, { "CE1", "CZ" }, { "CG", "CD2" }, { "CD2", "CE2" }, { "CE2", "CZ" } } },
	{ "PRO", { { "N", "CA" }, { "CA", "C" }, { "C", "O" }, { "CA", "CB" }, { "CB", "CG" }, { "CG", "CD" }, { "CD", "N" } } },
	{ "SER", { { "N", "CA" }, { "CA", "C" }, { "C", "O" }, { "CA", "CB" }, { "CB", "OG" } } },
	{ "THR", { { "N", "CA" }, { "CA", "C" }, { "C", "O" }, { "CA", "CB" }, { "CB", "OG1" }, { "CB", "CG2" } } },
	{ "TRP", { { "N", "CA" }, { "CA", "C" }, { "C", "O" }, { "CA", "CB" }, { "CB", "CG" }, { "CG", "CD1" }, { "CG", "CD2" }, { "CD1", "NE1" }, { "CD2", "CE2" }, { "CD2", "CE3" }, { "NE1", "CE2" }, { "CE2", "CZ2" }, { "CZ2", "CH2" }, { "CH2", "CZ3" }, { "CZ3", "CE3" } } },
	{ "TYR", { { "N", "CA" }, { "CA", "C" }, { "C", "O" }, { "CA", "CB" }, { "CB", "CG" }, { "CG", "CD1" }, { "CG", "CD2" }, { "CD1", "CE1" }, { "CD2", "CE2" }, { "CE1", "CZ" }, { "CE2", "CZ" }, { "CZ", "OH" } } },
	{ "VAL", { { "N", "CA" }, { "CA", "C" }, { "C", "O" }, { "CA", "CB" }, { "CB", "CG1" }, { "CB", "CG2" } } }
};

const map<string, char> CANONICAL20_MAP = 
{
	{ "CYS", 'C' }, { "ASP", 'D' }, { "SER", 'S' }, { "GLN", 'Q' },
	{ "LYS", 'K' }, { "ILE", 'I' }, { "PRO", 'P' }, { "THR", 'T' }, 
	{ "PHE", 'F' }, { "ASN", 'N' }, { "GLY", 'G' }, { "HIS", 'H' }, 
	{ "LEU", 'L' }, { "ARG", 'R' }, { "TRP", 'W' }, { "ALA", 'A' }, 
	{ "VAL", 'V' }, { "GLU", 'E' }, { "TYR", 'Y' }, { "MET", 'M' }, 
	{ "MSE", 'M' }, { "HYP", 'P' }, { "MLY", 'K' }, { "SEP", 'S' }, 
	{ "TPO", 'T' }, { "CSO", 'C' }, { "PTR", 'Y' }, { "KCX", 'K' }, 
	{ "CME", 'C' }, { "CSD", 'A' }, { "CAS", 'C' }, { "MLE", 'L' }, 
	{ "DAL", 'A' }, { "CGU", 'E' }, { "DLE", 'L' }, { "FME", 'M' }, 
	{ "DVA", 'V' }, { "OCS", 'C' }, { "DPR", 'P' }, { "MVA", 'V' }, 
	{ "TYS", 'Y' }, { "M3L", 'K' }, { "SMC", 'C' }, { "ALY", 'K' }, 
	{ "CSX", 'C' }, { "DCY", 'C' }, { "NLE", 'L' }, { "DGL", 'E' }, 
	{ "DSN", 'S' }, { "CSS", 'C' }, { "DLY", 'K' }, { "MLZ", 'K' }, 
	{ "DPN", 'F' }, { "DAR", 'R' }, { "PHI", 'F' }, { "IAS", 'D' }, 
	{ "DAS", 'D' }, { "HIC", 'H' }, { "MP8", 'P' }, { "DTH", 'T' }, 
	{ "DIL", 'I' }, { "MEN", 'N' }, { "DTY", 'Y' }, { "CXM", 'M' }, 
	{ "DGN", 'G' }, { "DTR", 'W' }, { "SAC", 'S' }, { "DSG", 'N' }, 
	{ "MME", 'M' }, { "MAA", 'A' }, { "YOF", 'Y' }, { "FP9", 'P' }, 
	{ "FVA", 'V' }, { "MLU", 'L' }, { "OMY", 'Y' }, { "FGA", 'E' }, 
	{ "MEA", 'F' }, { "CMH", 'C' }, { "DHI", 'H' }, { "SEC", 'C' }, 
	{ "OMZ", 'Y' }, { "SCY", 'C' }, { "MHO", 'M' }, { "MED", 'M' }, 
	{ "CAF", 'C' }, { "NIY", 'Y' }, { "OAS", 'S' }, { "SCH", 'C' }, 
	{ "MK8", 'L' }, { "SME", 'M' }, { "LYZ", 'K' }
};

}

#endif /* TOPOLOGY_H_ */
