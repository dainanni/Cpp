//
//  decoder.h
//  CPU.out
//
//  Created by Daivik Dinesh on 1/12/16.
//
//

#ifndef decoder_h
#define decoder_h

#include "registers.h"
#include "main.h"
#include <string.h>
#include <stdio.h>

typedef struct
{
    char opcode[20];
    int* operand1;
    int* operand2;
} Decoder;

int parse(char *, Decoder*, Registers*, int memory[]);
int execute(Decoder*, Registers*, int memory[]);

int addl(Decoder*);
int subl(Decoder*);
int andl(Decoder*);
int leave(Decoder*, Registers*, int memory[]);
int ret(Decoder*, Registers*, int memory[]);
int pushl(Decoder*, Registers*, int memory[]);
int movl(Decoder*);

#endif /* decoder_h */
