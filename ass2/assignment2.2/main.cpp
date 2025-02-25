#include <iostream>
#include "registers.h"
#include "instruction.h"

int main (void)
{
	Registers regs = Registers();
	regs.setRegistes(1, 5);
	regs.setRegistes(2, 5);
	regs.setRegistes(3, 3);

	Instruction brne = BrneInstruction();
	return 0;
}
