//
//  main.h
//  CPU.out
//
//  Created by Daivik Dinesh on 1/12/16.
//
//


#ifndef main_h
#define main_h

#include <stdio.h>
#include "registers.h"



enum {eax, ebp, esp, eip};
int* address(Registers* registers, char* ptr, int* memory);



#endif /* main_h */
