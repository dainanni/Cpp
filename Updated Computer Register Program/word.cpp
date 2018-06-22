#include "word.h"

Word::Word(int address):address(address)
{
} // Word();

Word::~Word()
{
}; // ~Word();

bool Word::operator< (const Word &word) const
{
  return (address < word.address);
}; // operator<
