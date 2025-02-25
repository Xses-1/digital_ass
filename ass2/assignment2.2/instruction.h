#ifndef _INSTRUCTION_H_
#define _INSTRUCTION_H_

#include <iostream>
#include "registers.h"

using namespace std;

class Instruction {
	public:
		virtual ~Instruction();
		virtual void disassemble();
		virtual int execute(Registers *);

	protected:
		int p1, p2, p3;
	
};

class AddInstruction : public Instruction {
	public:
		void disassemble();
		int execute(Registers *);
};

class SubInstruction : public Instruction {
	public:
		void disassemble();
		int execute(Registers *);
};

class OriInstruction : public Instruction {
	public:
		void disassemble();
		int execute(Registers *);
};

class BrneInstruction : public Instruction {
	public:
		void disassemble();
		int execute(Registers *);
};


#endif /* _INSTRUCTION_H_ */
