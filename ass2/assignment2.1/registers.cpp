#include <iostream>
#include "registers.h"

using namespace std;

Registers::Registers () {}


void Register::setRegister(int regNum, int value) {

	registors[regNum] = value;
}


void Register::getRegister(int regNum) {
	
	if (regNum == 0) {
		return 0;

	} else {
		return registors[regNum];
	}

	return;
}
