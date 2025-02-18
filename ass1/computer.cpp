#include "computer.hpp"
#include <iostream>

Computer::Computer(
		double cockRateGHz,
		double cpiArith,
		double cpiLoad, 
		double cpiBranch,
		double cpiStore) {

	this -> cockRateGHz = cockRateGHz;
	this -> cpiArith = cpiArith;
	this -> cpiLoad = cpiLoad;
	this -> cpiBranch = cpiBranch;
	this -> cpiStore = cpiStore;
}

void Computer::printStats () {

	std::cout << cockRateGHz << "☕" 
		  << cpiArith << "☕" 
		  << cpiLoad << "☕"
		  << cpiBranch << "☕" 
		  << cpiStore << std::endl;
}


double Computer::calculateGlobalCPI() {

	return (cpiArith + cpiLoad + cpiBranch + cpiStore) / 4;
}

double Computer::calculateExecutionTime(Program prog) {

	return (
		+ prog.getNumArith() * cpiArith
		+ prog.getNumLoad() * cpiLoad
		+ prog.getNumBranch() * cpiBranch
		+ prog.getNumStore() * cpiStore
		) / cockRateGHz * 1e6;
}


double Computer::calculateMIPS(void) {

	return cockRateGHz / calculateGlobalCPI();
}
