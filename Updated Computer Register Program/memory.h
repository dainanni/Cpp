#ifndef MEMORY_H
#define MEMORY_H

#include "word.h"

class Memory;

class ListNode
{
  Word *word;
  ListNode *next;
public:
  ListNode(Word *word, ListNode *next);
  ~ListNode();
  friend Memory;
}; // class ListNode;

class Memory
{
  ListNode *head;
  ListNode *curr;
public:
  Memory();
  ~Memory();
}; // class Memory;

#endif // MEMORY_H
