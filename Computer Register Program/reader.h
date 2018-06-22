//
//  reader.h
//  CPU.out
//
//  Created by Daivik Dinesh on 1/12/16.
//
//

#ifndef reader_h
#define reader_h

#include "instruction.h"
#include "registers.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    Instruction lines[1000];
} Reader;

int read(char*, Reader*);
char* fetch(Reader* , Registers* ,int n);

#endif /* reader_h */
