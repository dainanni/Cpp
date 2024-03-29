#ifndef READER_H
#define	READER_H

#include <iostream>
#include "instruction.h"
#include "registers.h"

using namespace std;

class Reader
{
  Instruction lines[1000];
public:
  void fetch(Instruction *instruction, Registers *registers) const;
  friend istream& operator>> (istream &is, Reader &reader);
}; // class Reader;

#endif // READER_H
