// FILE: DPQueue.cpp
// IMPLEMENTS: p_queue (see DPQueue.h for documentation.)
//
// INVARIANT for the p_queue class:
//   1. The number of items in the p_queue is stored in the member
//      variable used.
//   2. The items themselves are stored in a dynamic array (partially
//      filled in general) organized to follow the usual heap storage
//      rules.
//      2.1 The member variable heap stores the starting address
//          of the array (i.e., heap is the array's name). Thus,
//          the items in the p_queue are stored in the elements
//          heap[0] through heap[used - 1].
//      2.2 The member variable capacity stores the current size of
//          the dynamic array (i.e., capacity is the maximum number
//          of items the array currently can accommodate).
//          NOTE: The size of the dynamic array (thus capacity) can
//                be resized up or down where needed or appropriate
//                by calling resize(...).
// NOTE: Private helper functions are implemented at the bottom of
// this file along with their precondition/postcondition contracts.

#include <cassert>   // provides assert function
#include <iostream>  // provides cin, cout
#include <iomanip>   // provides setw
#include <cmath>     // provides log2
#include <string.h>  // provides memcpy
#include "DPQueue.h"

using namespace std;

namespace CS3358_FA17A7
{
   void p_queue::print_tree(const char message[], size_type i) const
   {
      const char NO_MESSAGE[] = "";
      size_type depth;

      if (message[0] != '\0')
         cout << message << endl;

      if (i >= used)
         cout << "(EMPTY)" << endl;
      else
      {
         depth = size_type( log( double(i+1) ) / log(2.0) + 0.1 );
         if (2*i + 2 < used)
            print_tree(NO_MESSAGE, 2*i + 2);
         cout << setw(depth*3) << "";
         cout << heap[i].data;
         cout << '(' << heap[i].priority << ')' << endl;
         if (2*i + 1 < used)
            print_tree(NO_MESSAGE, 2*i + 1);
      }
   }

   void p_queue::print_array(const char message[]) const
   {
      if (message[0] != '\0')
         cout << message << endl;

      if (used == 0)
         cout << "(EMPTY)" << endl;
      else
         for (size_type i = 0; i < used; i++)
            cout << heap[i].data << ' ';
   }

   p_queue::p_queue(size_type initial_capacity) : capacity(initial_capacity), used(0)
   {
      if (capacity < 1)
       capacity = DEFAULT_CAPACITY;

      heap = new ItemType [capacity];
   }

   p_queue::p_queue(const p_queue& src) : capacity(src.capacity), used(src.used)
   {
      heap = new ItemType [src.capacity];

      memcpy(heap, src.heap, sizeof(src.heap) * used);
   }

   p_queue::~p_queue()
   {
      delete [] heap;
   }

   p_queue& p_queue::operator=(const p_queue& rhs)
   {
      if(&rhs != this){

        used = rhs.used;
        capacity = rhs.capacity;

        ItemType *newHeap = new ItemType [rhs.capacity];

        memcpy(newHeap, rhs.heap, sizeof(rhs.heap) * used);

        delete heap;

        heap = newHeap;
      }
      return *this;
   }

   void p_queue::push(const value_type& entry, size_type priority)
   {
      if(used >= capacity)
       resize(capacity * 1.5);

      ItemType newItem;

      newItem.priority = priority;
      newItem.data = entry;

      heap[used] = newItem;

      size_type temp = used;

      used++; // needed by parent priority to not fail assertion. 

      while( temp != 0 && parent_priority(temp) < heap[temp].priority )
      {
       swap_with_parent(temp);

       temp = parent_index(temp);
      }
   }

   void p_queue::pop()
   {
     assert(size() > 0);

     size_type tempIndex = 0;

     heap[tempIndex] = heap[used - 1];

     while((!is_leaf(tempIndex)) && big_child_priority(tempIndex) > heap[tempIndex].priority)
     {

      size_type temp = big_child_index(tempIndex);

      swap_with_parent(temp);

      tempIndex = temp;
     }

     --used;
   }

   p_queue::size_type p_queue::size() const { return used; }


   bool p_queue::empty() const{ return used == 0; }


   p_queue::value_type p_queue::front() const
   {
      assert( size() > 0 );

      return heap[0].data;
   }

   void p_queue::resize(size_type new_capacity)
   {
     if(new_capacity == capacity)   // truncation prevention
      new_capacity++;

     if(new_capacity < capacity)    // smaller value prevention
      new_capacity = capacity;

     if(new_capacity < 1)           // fraction value prevention
      new_capacity = 1;

     capacity = new_capacity;

     ItemType *temp = new ItemType [capacity];

     for(size_type i = 0; i < used; i++)
       temp[i] = heap[i];

     delete [] heap;

     heap = temp;
   }

   bool p_queue::is_leaf(size_type i) const
   {
      assert(i < used);

      if ( (2 * i + 1) < used || (2 * i + 2) < used )
       return false;

       else
        return true;
   }

   p_queue::size_type p_queue::parent_index(size_type i) const
   {
      assert(i > 0 && i < used);

      return (i - 1 ) / 2;
   }

   p_queue::size_type p_queue::parent_priority(size_type i) const
   {
      assert(i > 0 && i < used);

      return heap[(i - 1) / 2].priority;
   }

   p_queue::size_type p_queue::big_child_index(size_type i) const
   {
      assert(is_leaf(i) == false);

      if( 2 * i + 2 < used ){

       if( heap[2 * i + 1].priority > heap[2 * i + 2].priority )
        return 2 * i + 1;

        else
         return 2 * i + 2;
      }
       else
         return 2 * i + 1;
   }

   p_queue::size_type p_queue::big_child_priority(size_type i) const
   {
      assert( is_leaf(i) == false );

       if( 2 * i + 2 < used ){

        if(heap[2 * i + 1].priority > heap[2 * i + 2].priority)
         return heap[2 * i + 1].priority;

         else
          return heap[2 * i + 2].priority;
       }
       else
        return heap[2 * i + 1].priority;
   }

   void p_queue::swap_with_parent(size_type i)
   {
      assert( (i > 0) && (i < used) );

      ItemType temp = heap[i];

      heap[i] = heap[(i - 1) / 2];

      heap[(i - 1) / 2] = temp;
   }
}
