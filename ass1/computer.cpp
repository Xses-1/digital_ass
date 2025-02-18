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

	std::cout << cockRateGHz 
		  << cpiArith
		  << cpiLoad
		  << cpiBranch
		  << cpiStore << std::endl;
}

/*
void Computer::calculateGlobalCPI() {

	long double CPI = 0.0;

	return CPI = 
*/
