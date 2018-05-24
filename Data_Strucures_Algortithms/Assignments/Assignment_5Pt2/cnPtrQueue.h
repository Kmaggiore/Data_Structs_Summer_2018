#ifndef CN_PTR_QUEUE_H
#define CN_PTR_QUEUE_H

#include <cstdlib>        // for size_t
#include <stack>          // for STL stack template
#include "nodes_LLoLL.h"  // for CNode

namespace CS3358_FA17_A5P2
{
   class cnPtrQueue
   {
   public:
      typedef std::size_t size_type;
      cnPtrQueue();                // constructor
      bool empty() const;          // determines if is empty
      size_type size() const;      // returns # of items in queue
      CNode* front();              // Method returns the first element in the
      void push(CNode* cnPtr);     // Push an item onto the queue
      void pop();                  // Pop and item off the queue
   private:
      std::stack<CNode*> inStack;  // Stack Input will go into.
      std::stack<CNode*> outStack; // Stack the output will flow from.
      size_type numItems;          // # of items in queue.
   };
}  // end of namespace

#endif
