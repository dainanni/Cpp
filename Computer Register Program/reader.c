//
//  reader.c
//  CPU.out
//
//  Created by Daivik Dinesh on 1/12/16.
//
//

#include "reader.h"
#include "registers.h"
#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int read (char* file, Reader* reader)
{
    FILE *fp;
    char ch[100];
    fp = fopen(file, "r");
    reader->lines[0].address = 100;

    while(fgets(ch, 100, fp) != NULL)
    {
        if((ch[0] == '.') || (ch[1] == '.'))
        {
            continue;
        }
        
        for(int i=0; i != '\0'; i++)
        {
        
            if(ch[i] == '\t')
            {
                ch[i] = ' ';
            
            }
        
            else if(ch[i] == '\n')
            {
                ch[i] = '\0';
                
            }
        
            reader->lines[i].info = (char*)malloc(strlen(ch)+1);
            strcpy(reader->lines[i].info, ch);
            reader->lines[i].address += 4;
	}
    }
    
    fclose(fp);
    return 0;
}

char* fetch(Reader *reader, Registers *registers,int n)
{
    for(int n=0; n != 1000; n++)
    {
        if(reader->lines[n].address == registers->regs[eip])
        {
            registers->regs[eip] += 4;
            return (reader->lines[n].info);
        }
        
        else
        {
            continue;
        }
        
    }
    
return 0;
}

