//
//  registers.c
//  CPU.out
//
//  Created by Daivik Dinesh on 1/12/16.
//
//

#include "registers.h"
#include "main.h"
#include <stdio.h>

void initialize(Registers* registers, int memory[])
{
    registers->regs[esp] = 992;
    registers->regs[ebp] = 996;
    registers->regs[eip] = 100;
    registers->regs[eax] = 0;
    memory[1000] = 0;
    
}

int print(Registers* registers, char* instruction)
{
    printf(" %s eip: %d eax: %d ebp: %d esp: %d", instruction, registers->regs[eip], registers->regs[eax], registers->regs[ebp], registers->regs[esp]);
    
    return 0;
}












