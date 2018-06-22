//
//  decoder.c
//  CPU.out
//
//  Created by Daivik Dinesh on 1/12/16.
//
//

#include "decoder.h"
#include "registers.h"
#include "main.h"
#include <stdio.h>
#include<string.h>

int parse(char* instruction, Decoder* decoder, Registers* registers, int memory[])
{
    char* token;
    char* token2;
    char* token3;
    
    char copy[80];
    
    strcpy(copy, instruction);
    
    token = strtok(copy, ", ");
    
    strcpy(decoder->opcode, token);
    
    token2 = strtok(NULL, ", ");
    
    if(token2!= NULL)
    {
        decoder->operand1 = address(registers, token2, memory);
    }
    
    token3 = strtok(NULL, ", ");
    
    if(token3!= NULL)
    {
        decoder->operand2 = address(registers, token3, memory);
    }
    
    return 0;
}



int execute(Decoder * decoder, Registers* registers, int memory[])
{
 const char* array[7] = {"addl", "andl", "leave", "movl", "pushl", "ret", "subl"};
    int x;
    
    for(x = 0; x <= 7; x++)
    {
        if(strstr(array[x], decoder->opcode) != NULL)
        {
            break;
        }
    }
    
    switch(x)
        {
            case 0: addl(decoder);
                break;
                
            case 1: andl(decoder);
                break;
                
            case 2: leave(decoder, registers, memory);
                break;
            
            case 3: movl(decoder);
                break;
            
            case 4: pushl(decoder, registers, memory);
                break;
                
            case 5: ret(decoder, registers, memory);
                break;
                
            case 6: subl(decoder);
                break;
        }
    
    return 0;
}
    
int addl(Decoder * decoder)
{
    *(decoder->operand2) = *(decoder->operand1) + *(decoder->operand2);
    return 0;
}

int andl(Decoder* decoder)
{
    *(decoder->operand2) = *(decoder->operand1) & *(decoder->operand2);
    return 0;
}

int subl(Decoder* decoder)
{
    *(decoder->operand2) = *(decoder->operand2) - *(decoder->operand1);
    return 0;
}

int movl(Decoder* decoder)
{
    *(decoder->operand2) = *(decoder->operand1);
    return 0;
}

int pushl(Decoder* decoder, Registers* registers, int memory[])
{
    (registers->regs[esp]) -= 4;
    
    memory[registers->regs[esp]] = *(decoder->operand1);
    return 0;
}

int leave(Decoder* decoder, Registers* registers, int memory[])
{
    registers->regs[esp] = registers->regs[ebp];
    
    registers->regs[ebp] = memory[registers->regs[esp]];
    
    (registers->regs[esp]) += 4;
    return 0;
}

int ret(Decoder* decoder, Registers* registers, int memory[])
{
    registers->regs[eip] = registers->regs[esp];
    
    (registers->regs[esp]) += 4;
    return 0;
}


        
        
        
        
