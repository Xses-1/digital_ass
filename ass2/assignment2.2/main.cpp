#include <iostream>
#include "registers.h"
#include "instruction.h"

int main (void)
{
	Registers regs = Registers();
	regs.setRegisters(1, 5);
	regs.setRegisters(2, 5);
	regs.setRegisters(3, 3);

	Instruction add	= AddInstruction(1, 2, 3);
	Instruction sub = SubInstruction(1, 2, 3);
	Instruciton ori = OriInstruction(1, 2, 3);
	Instruction brne1 = BrneInstruction(1, 2, 42);
	Instruction brne2 = BrneInstruction(2, 3, 69);

	brne1.dissasemble();
	brne2.dissasemble();

	return 0;
}
