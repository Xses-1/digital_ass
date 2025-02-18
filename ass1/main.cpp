#include "computer.hpp"
#include "program.hpp"
#include <stdio.h>
#include <iostream>

int main () {
	Computer computer1 = Computer(1, 2, 3, 4, 2);
	Computer computer2 = Computer(1.2, 2, 4, 3, 3);
	Computer computer3 = Computer(2, 2, 4, 6, 2);

	std::cout << std::endl << "Computors! Stats: " << std::endl;
	computer1.printStats();
	computer2.printStats();
	computer3.printStats();

	std::cout << std::endl << "CPIs: " << std::endl;
	printf("CPI: %f\n", computer1.calculateGlobalCPI());
	printf("CPI: %f\n", computer2.calculateGlobalCPI());
	printf("CPI: %f\n", computer3.calculateGlobalCPI());

	std::cout << std::endl << "MIPS independent: " << std::endl;
	std::cout << computer1.calculateMIPS() << "☕"
		  << computer2.calculateMIPS() << "☕"
		  << computer3.calculateMIPS() 
		  << std::endl;


	Program program1 = Program(2000, 100, 50, 100);
	Program program2 = Program(2000, 0.1, 0.25, 0.4);
	Program program3 = Program(500, 2000, 200, 100);

	std::cout << std::endl << "PRogram Stats: " << std::endl;
	program1.printStats();
	program2.printStats();
	program3.printStats();

	std::cout << std::endl << "MIPS dependent: " << std::endl;
	std::cout << computer1.calculateMIPS(program1) << "☕"
		  << computer2.calculateMIPS(program2) << "☕"
		  << computer3.calculateMIPS(program3) 
		  << std::endl;


	return 0;
}
