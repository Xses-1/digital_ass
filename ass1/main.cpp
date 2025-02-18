#include "computer.hpp"
#include "program.hpp"
#include <stdio.h>

int main () {
	Computer computer1 = Computer(1, 2, 3, 4, 2);
	Computer computer2 = Computer(1.2, 2, 4, 3, 3);
	Computer computer3 = Computer(2, 2, 4, 6, 2);

	computer1.printStats();
	computer2.printStats();

	printf("CPI: %f\n", computer1.calculateGlobalCPI());
	printf("CPI: %f\n", computer2.calculateGlobalCPI());

	Program program1 = Program(2000, 100, 50, 100);
	Program program2 = Program(0.3, 0.4, 0.2, 0.0);
	Program program2 = Program(0.3, 0.4, 0.2, 0.0);

	program1.printStats();
	program2.printStats();

	return 0;
}
