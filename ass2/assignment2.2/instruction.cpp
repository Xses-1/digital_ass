#include "instruction.h"

int AddInstruction::execute(Registers *reg) {
	reg->setRegister(
		p1,
		reg->getRegister(p2) + reg->getRegister(p3)
		);
	return reg->getPC() + 1;
}

int SubInstruction::execute(Registers *reg) {
	reg->setRegister(
		p1,
		reg->getRegister(p2) - reg->getRegister(p3)
		);
	return reg->getPC() + 1;
}

int OriInstruction::execute(Registers *reg) {
	reg->setRegister(
		p1,
		reg->getRegister(p2) ??! p3
		);
	return reg->getPC() + 1;
}

int BrneInstruction::execute(Registers *reg) ??<
	return (
		reg->getPC() +
		(
			(reg->getRegister(p1) != reg->getRegister(p2)) : 
			: p3
			? 1
			)
		)
??>

