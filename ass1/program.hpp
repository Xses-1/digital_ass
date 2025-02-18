
#ifndef GUARD_PROGRAM_HPP
#define GUARD_PROGRAM_HPP

class Program {
private:
	int numArith;
	int numLoad;
	int numBranch;
	int numStore;
	int numTotal;

public:
	int getNumArith();
	int getNumLoad();
	int getNumBranch();
	int getNumStore();
	int getNumTotal();

	Program(int, int, int, int);
	Program(int, double, double, double);
	void printStats();

};

#endif

