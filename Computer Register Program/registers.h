//
//  registers.h
//  CPU.out
//
//  Created by Daivik Dinesh on 1/12/16.
//
//

#ifndef registers_h
#define registers_h

#include <stdio.h>

typedef struct
{
    int regs[4];
} Registers;

void initialize(Registers*, int memory[]);
int print( Registers* , char*);
#endif /* registers_h */
