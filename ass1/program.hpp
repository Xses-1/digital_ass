class Program {
public:
	int numArith;
	int numLoad;
	int numBranch;
	int numStore;
	int numTotal;

	Program(int, int, int, int, int);
	Program(int, double, double, double, double);
	void printStats();

};
