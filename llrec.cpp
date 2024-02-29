#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

// split list into two lists
// nodes <= to pivot
// nodes > to pivot
// keep ordering of nodes
// delete og node

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot)
{
   if (head == nullptr)
   {
      smaller = nullptr;
      larger = nullptr;
      return;
   }

   else
   {
      llpivot(head->next, smaller, larger, pivot);

      if (head->val <= pivot)
      {
         head->next = smaller;
         smaller = head;
      }
      else
      {
         head->next = larger;
         larger = head;
      }

      head = nullptr;
   }
}