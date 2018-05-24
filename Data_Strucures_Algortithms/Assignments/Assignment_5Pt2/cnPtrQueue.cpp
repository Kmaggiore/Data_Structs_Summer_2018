#include "cnPtrQueue.h"
#include <cassert>
using namespace std;

namespace CS3358_FA17_A5P2
{
 // inStack <*CNode> input Stack
 // outStack<*CNode> outPut Stack

  cnPtrQueue::cnPtrQueue() : numItems(0){}

  bool cnPtrQueue::empty() const{
    return outStack.empty() && inStack.empty();    // the queue is only empty if both of the stacks are empty.
  }

  cnPtrQueue::size_type cnPtrQueue::size() const{
    return numItems;                               // return the number of items
   }

  CNode* cnPtrQueue::front(){                      // return the front Node of outStack

   assert(!outStack.empty() || !inStack.empty());  // ensure at least one of the stacks is full.

   if(outStack.empty()){                           // if the outStack is empty

      while(!inStack.empty()){                     // while the inStack is Not Empty
       outStack.push(inStack.top());               // fill it with values from inStack
       inStack.pop();                              // pop the inStack
     }
   }
   return outStack.top();
  }

  void cnPtrQueue::push(CNode* cnPtr)
  {
    numItems++;
    inStack.push(cnPtr);
   }


  void cnPtrQueue::pop(void){
    assert(!outStack.empty() || !inStack.empty());  // ensure at least one of the stacks is full.

     if(outStack.empty())                          // if the outstack is empty
      while(!inStack.empty()){                      // fill it with inStack
        outStack.push(inStack.top());               // push the value from inStack to outStack
        inStack.pop();                              // pop and get ready for next value.
      }
      outStack.pop();
      numItems--;
  }

}
