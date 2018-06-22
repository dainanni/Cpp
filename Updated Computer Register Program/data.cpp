#include "data.h"

Data::Data(int address) : Word(address)
{
} // Data()

int& Data::getWord() const
{
  return num;
} // getWord() const

int& Data::getWord()
{
  return num;
} // getWord()

bool Data::operator= (int a)
{
  num = a;
  return *this;
} // operator=
