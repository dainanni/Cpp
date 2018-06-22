//
//  main.c
//  CPU.out
//
//  Created by Daivik Dinesh on 1/12/16.
//
//

// Author: Sean Davis

#include "registers.h"
#include "decoder.h"
#include "reader.h"
#include "instruction.h"
#include "main.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int* address(Registers* registers, char* operand, int* memory)
{
    static int value;
    char regNames[4][7] = {"eax", "ebp", "esp", "eip"};
    char *ptr;
    int regNum, index;
    
    if(operand == NULL)
        return NULL;
    
    if(operand[0] == '$') // immediate mode
    {
        value = atoi(&operand[1]);
        return &value;
    } // if immediate mode
    
    for(regNum = eax; regNum <= eip; regNum++)
        if(strstr(operand, regNames[regNum]))
            break;
    
    ptr = strchr(operand, '(');
    if(ptr) // some form of indirect addressing
    {
        *ptr = '\0';  // terminate operand string at first '('
        index = atoi(operand);  // will return 0 if no number there!
        return  &memory[registers->regs[regNum] + index];
    } // if ptr
    else  // direct addressing
        return &(registers->regs[regNum]);
    
} // address ()

int main(int argc, char* argv[])
{
    Reader reader;
    Decoder decoder;
    Registers registers;
    char instruction[80];
    int i = 0;
    int memory[1001];	


    initialize(&registers, memory);
    
    while(eip != 0)
    {
        read(argv[1], &reader);
        fetch(&reader, &registers, i);
        parse(instruction, &decoder, &registers, memory);
     	execute(&decoder, &registers, memory);
        print (&registers, instruction);
    }
    
    return 0;
}  // main()
