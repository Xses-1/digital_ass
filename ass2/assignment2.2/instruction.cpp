#include "instruction.h"

Instruction::Instruction(int p1, int p2, int p3) {
	this->p1 = p1;
	this->p2 = p2;
	this->p3 = p3;
}

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
			(reg->getRegister(p1) != reg->getRegister(p2)) ?
			p3
			: 1
			)
		);
??>

void AddInstruction::disassemble () {
	printf("add $%i, $%i, $%i\n", p1, p2, p3);
}

void SubInstruction::disassemble () {
	printf("sub $%i, $%i, $%i\n", p1, p2, p3);
}

void OriInstruction::disassemble () {
	printf("ori $%i, $%i, %i\n", p1, p2, p3);
}

void BrneInstruction::disassemble () {
	printf("brne $%i, $%i, %i\n", p1, p2, p3);
}

