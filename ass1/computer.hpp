#include "program.hpp"

class Computer {
public:
	double cockRateGHz;
	double cpiArith;
	double cpiLoad;
	double cpiBranch;
	double cpiStore;

	Computer(double, double, double, double, double);
	void printStats();
	double calculateMIPS();
	double calculateMIPS(Program);
	double calculateGlobalCPI();
	double calculateWeightedCPI(Program);
	double calculateExecutionTime(Program);

};

