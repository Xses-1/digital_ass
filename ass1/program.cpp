#include <program.hpp>

Program::Program(
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

Program::Program(
		int numTotal,
		double fracArith,
		double fracLoad, 
		double fracBranch,
		double fracStore,
		) {

	this -> numArith = numTotal * fracArith;
	this -> numLoad = numTotal * fracLoad;
	this -> numBranch = numTotal * fracBranch;
	this -> numStore = numTotal * fracStore;
}

void Computer::printStats () {
	printf(
		"Arith\tLoad\tBranch\tStore\tTotal\n"
		"%i\t%i\t%i\t%i\t%i"
		numArtirh, numLoad, numLoad, numBranch, numStore, numTotal
		);
}

