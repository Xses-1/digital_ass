#include <program.h>

class program(int, int, int, int);

Computer::Computer(
		int numArith,
		int numLoad, 
		int numBranch,
		int numStore,
		int numTotal,
		) {

	this -> numArith = numArith;
	this -> numLoad = numLoad;
	this -> numBranch = numBranch;
	this -> numStore = numStore;
	this -> numTotal = numTotal;
}


void Computer::printStats () {
	printf(
		"Arith\tLoad\tBranch\tStore\tTotal\n"
		"%i\t%i\t%i\t%i\t%i"
		numArtirh, numLoad, numLoad, numBranch, numStore, numTotal
		);
}

