#include <stdio.h>
#include <string.h>
#include <iostream>
#include "registers.h"

using namespace std;

Registers::Registers () {
	
	for (int i=0; i < NUM_REGISTORS; i++) {
		registors[i] = 0;
	}

	// For extra resilience
	// registers is an array, so sizeof returns total size
	memset(registors, 0, sizeof(registors));

	pc = 0;
}


void Registers::setRegister(int regNum, int value) {

	registors[regNum] = value;
}


int Registers::getRegister(int regNum) {
	
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

void Registers::setPC(int value) {
	pc = value;
}

int Registers::getPC() {
	return pc;
}

void Registers::print() {
	std::cout << std::endl << "-----------------------------" << std::endl;

	for (int i=0; i < NUM_REGISTORS; i++) {
		printf("Reg %i: %i\n", i, registors[i]);
	}

	std::cout << "This is the progrma counter: " << pc << std::endl;

	std::cout << std::endl << std::endl << 
		"--------------------------------" << std::endl;
}

