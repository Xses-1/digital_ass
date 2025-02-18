#include "computer.hpp"
#include "program.hpp"

int main () {
	Computer computer1 = Computer(1, 2, 3, 4, 5);
	Computer computer2 = Computer(6, 5, 4, 3, 2);

	computer1.printStats();
	computer2.printStats();
}
