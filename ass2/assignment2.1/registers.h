#ifndef _REGISTERS_H_
#define _REGISTERS_H_

class Registers
{
	public:
		void 	setRegister(int regNum, int value);
		int 	getRegister(int regNum);
		void 	setPC(int value);
		int 	getPC();
		void 	print();
	
	Registers();

	private:
		int registors[32];
};

#endif	/* _REGISTERS_H_ */
