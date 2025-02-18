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

double Computer::calculateWeightedCPI(Program prog) {

	return (
		+ prog.getNumArith() * cpiArith
		+ prog.getNumLoad() * cpiLoad
		+ prog.getNumBranch() * cpiBranch
		+ prog.getNumStore() * cpiStore
		);
}
double Computer::calculateExecutionTime(Program prog) {

	return calculateWeightedCPI(prog) / cockRateGHz * 1e6;
}


double Computer::calculateMIPS(void) {

	return cockRateGHz / calculateGlobalCPI();
}

double Computer::calculateMIPS(Program prog) {

	return cockRateGHz / calculateWeightedCPI(prog);
}

