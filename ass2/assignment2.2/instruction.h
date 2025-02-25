#ifndef _INSTRUCTION_H_
#define _INSTRUCTION_H_

#include <iostream>
#include "registers.h"

class Instruction {
	public:
		Instruction(int, int, int);
		//virtual ~Instruction();
		virtual void disassemble();
		virtual int execute(Registers *);

	protected:
		int p1, p2, p3;
	
};

class AddInstruction : public Instruction {
	public:
		AddInstruction(int, int, int);
		void disassemble();
		int execute(Registers *);
};

class SubInstruction : public Instruction {
	public:
		SubInstruction(int, int, int);
		void disassemble();
		int execute(Registers *);
};

class OriInstruction : public Instruction {
	public:
		OriInstruction(int, int, int);
		void disassemble();
		int execute(Registers *);
};

class BrneInstruction : public Instruction {
	public:
		//BrneInstruction(int, int, int);
        BrneInstruction(int p1, int p2, int p3):
				Instruction(p1, p2, p3) {};
		virtual void disassemble();
		int execute(Registers *);
};


#endif /* _INSTRUCTION_H_ */
