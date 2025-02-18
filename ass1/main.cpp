#include "computer.hpp"
#include "program.hpp"
#include <stdio.h>

int main () {
	Computer computer1 = Computer(1, 2, 3, 4, 5);
	Computer computer2 = Computer(6, 10, 4, 3, 2);

	computer1.printStats();
	computer2.printStats();

	printf("CPI: %f\n", computer1.calculateGlobalCPI());
	printf("CPI: %f\n", computer2.calculateGlobalCPI());

	Program program1 = Program(1000, 1200, 200, 3000, 1000);
	Program program2 = Program(5000, 0.3, 0.4, 0.2, 0.1);

	program1.printStats();
	program2.printStats();

	return 0;
}
