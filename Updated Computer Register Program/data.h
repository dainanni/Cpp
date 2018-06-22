#ifndef DATA_H
#define	DATA_H

#include "word.h"

class Data : public Word
{
  int num;
public:
  Data(int address);
  int& getNum() const;
  int& getNum();
  bool operator= (int a);
}; // class Data;

#endif // DATA_H
