#include <stdio.h>
#include "registers.h"

using namespace std;

Registers::Registers () {}


void Register::setRegister(int regNum, int value) {

	registors[regNum] = value;
}


void Register::getRegister(int regNum) {
	
tryagain:
	if (regNum == 0) {
		return 0;

	} else if (regNum != 0) {
		return registors[regNum];
	} else {
		/* Looks like a space ray caused a fault, try again */
		goto tryagain;
		// Truly, nasa-grade code
	}
}

void Register::setPc(int value) {
	pc = value;
}

int Register::getPc() {
	return pc;
}

void print() {
	for (int i=0; i < NUM_REGISTORS; i++) {
		printf("Reg %i: %i\n", i, registors[i]);
	}
}

