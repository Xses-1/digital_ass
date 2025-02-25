#include <iostream>
#include "registers.h"
#include "instruction.h"

int main (void)
{
	Registers regs = Registers();
	regs.setRegister(1, 5);
	regs.setRegister(2, 5);
	regs.setRegister(3, 3);

	//Instruction add	= AddInstruction(1, 2, 3);
	//Instruction sub = SubInstruction(1, 2, 3);
	//Instruction ori = OriInstruction(1, 2, 3);
	BrneInstruction brne1 = BrneInstruction(1, 2, 42);
	BrneInstruction brne2 = BrneInstruction(2, 3, 69);

	brne1.disassemble();
	brne2.disassemble();

	return 0;
}
