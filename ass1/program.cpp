#include "program.hpp"
#include <stdio.h>

Program::Program(
		int numArith,
		int numLoad, 
		int numBranch,
		int numStore
		) {

	this -> numArith = numArith;
	this -> numLoad = numLoad;
	this -> numBranch = numBranch;
	this -> numStore = numStore;
	this -> numTotal = numArith + numLoad + numBranch + numStore;
}

Program::Program(
		int numTotal,
		double fracArith,
		double fracLoad, 
		double fracStore
		) {

	this -> numTotal = numTotal;
	this -> numArith = numTotal * fracArith;
	this -> numLoad = numTotal * fracLoad;
	this -> numBranch = numTotal * (1 - fracArith - fracStore - fracLoad);
	this -> numStore = numTotal * fracStore;
}

void Program::printStats () {
	printf(
		"Arith\tLoad\tBranch\tStore\tTotal\n"
		"%i\t%i\t%i\t%i\t%i\t\n\n", 
		numArith, numLoad, numBranch, numStore, numTotal
		);
}

int Program::getNumArith() {return numArith;}
int Program::getNumLoad() {return numLoad;}
int Program::getNumBranch() {return numBranch;}
int Program::getNumStore() {return numStore;}
int Program::getNumTotal() {return numTotal;}

