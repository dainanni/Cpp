#include <cstdlib>
#include "memory.h"

ListNode::ListNode(Word *word, ListNode *head)
{
} // ListNode()

ListNode::~ListNode()
{
  delete word;
} // ~ListNode()

Memory::Memory():head(NULL)
{
} // Memory()

Memory::~Memory()
{
  curr = head;
  while(curr != NULL)
  {
    head = curr->next;
    delete curr;
    curr = curr->next;
  }
} // ~Memory()
