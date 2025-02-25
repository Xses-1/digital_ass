#include <iostream>
#include "registers.h"
#include "instruction.h"

int main (void)
{
        appendInstruction (new OriInstruction (3, 0, 1));
        appendInstruction (new AddInstruction (4, 4, 1));
        appendInstruction (new SubInstruction (2, 2, 3));
        appendInstruction (new BrneInstruction (2, 0, -3));

        return 0;
}
