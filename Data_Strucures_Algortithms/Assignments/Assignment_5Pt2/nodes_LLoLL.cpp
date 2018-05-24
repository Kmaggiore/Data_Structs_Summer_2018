#include "nodes_LLoLL.h"
#include "cnPtrQueue.h"
#include <iostream>
using namespace std;

namespace CS3358_FA17_A5P2
{
   void Destroy_cList(CNode*& cListHead)
   {
      int count = 0;
      CNode* cNodePtr = cListHead;
      while (cListHead != 0)
      {
         cListHead = cListHead->link;
         delete cNodePtr;
         cNodePtr = cListHead;
         ++count;
      }
      cout << "Dynamic memory for " << count << " CNodes freed"
           << endl;
   }

   void Destroy_pList(PNode*& pListHead)
   {
      int count = 0;
      PNode* pNodePtr = pListHead;
      while (pListHead != 0)
      {
         pListHead = pListHead->link;
         Destroy_cList(pNodePtr->data);
         delete pNodePtr;
         pNodePtr = pListHead;
         ++count;
      }
      cout << "Dynamic memory for " << count << " PNodes freed"
           << endl;
   }

   // do depth-first traversal and print data
   void ShowAll_DF(PNode* pListHead, ostream& outs)
   {
     // Parent List is the Outer Loop
      while (pListHead != 0)                  // While the list head is not equal to 0
      {
         CNode* cListHead = pListHead->data;  // Declare a new child node and initialize to pListHeads data field
         while (cListHead != 0)               // While there is data in the parent Nodes data field
         {
            outs << cListHead->data << "  ";  // Output the data
            cListHead = cListHead->link;      // Assign to next link in child Node List
         }
         pListHead = pListHead->link;         // Move to next link in Parent List
      }
   }

/* Procedure for breadth first search */
/*
if (head == 0) return
create queue q of CNode*
while (head != 0)
   if (head->data != 0)
      q.push(head->data)
   head = head->link;
while ( ! q.empty() )
   cursor = q.front()
   q.pop()
   display cursor->data
   if ( cursor->link != 0 )
      q.push( cursor->link )
*/

   // do breadth-first (level) traversal and print data
   void ShowAll_BF(PNode* pListHead, ostream& outs)
   {

     if(pListHead == 0)           // if the list is empty
      return;

     // create a new Queue
      cnPtrQueue q;
      CNode* curser;

     while(pListHead != 0)              // while we are not at the end of the list
     {
      if(pListHead -> data != 0)         // if there is data in the node
        q.push(pListHead -> data);       // push it onto the stack

        pListHead = pListHead -> link;
     }

      while( !q.empty() )                      // while the queue is not empty
      {
        curser = q.front();                     // assign pointer to front of queue
        q.pop();                                // pop the queue
        outs << curser -> data << "  ";         // display the data

        if(curser -> link != 0)
          q.push(curser -> link);

       }
  }

}         // end of namespace
