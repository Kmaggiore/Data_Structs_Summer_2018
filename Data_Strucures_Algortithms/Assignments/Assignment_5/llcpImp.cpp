#include <iostream>
#include <cstdlib>
#include "llcpInt.h"
using namespace std;

int FindListLength(Node* headPtr)
{
   int length = 0;

   while (headPtr != 0)
   {
      ++length;
      headPtr = headPtr->link;
   }

   return length;
}

bool IsSortedUp(Node* headPtr)
{
   if (headPtr == 0 || headPtr->link == 0) // empty or 1-node
      return true;
   while (headPtr->link != 0) // not at last node
   {
      if (headPtr->link->data < headPtr->data)
         return false;
      headPtr = headPtr->link;
   }
   return true;
}

void InsertAsHead(Node*& headPtr, int value)
{
   Node *newNodePtr = new Node;
   newNodePtr->data = value;
   newNodePtr->link = headPtr;
   headPtr = newNodePtr;
}

void InsertAsTail(Node*& headPtr, int value)
{
   Node *newNodePtr = new Node; // create new node
   newNodePtr->data = value;    // assign value
   newNodePtr->link = 0;        // set the next link to NULL
   if (headPtr == 0)            // see if list is empty
      headPtr = newNodePtr;     // if it is assing it the new node
   else
   {
      Node *cursor = headPtr;    // declare an itterator

      while (cursor->link != 0)  // not at last node
         cursor = cursor->link;  // move to next node in list

      cursor->link = newNodePtr; // assign elemtns to tail of the list
   }
}

void InsertSortedUp(Node*& headPtr, int value)
{
   Node *precursor = 0,
        *cursor = headPtr;

  // while data is less than current data node moe to next
   while (cursor != 0 && cursor->data < value)
   {
      precursor = cursor;
      cursor = cursor->link;
   }

  // create new node
   Node *newNodePtr = new Node;
  // assign value to data field
   newNodePtr->data = value;
  // assign next link to link field of NewNode
   newNodePtr->link = cursor;
  // if curser is head of list assign it to head of list.
   if (cursor == headPtr)
      headPtr = newNodePtr;
   else
      precursor->link = newNodePtr; // set previous node to point to newNode

   ///////////////////////////////////////////////////////////
   /* using-only-cursor (no precursor) version
   Node *newNodePtr = new Node;
   newNodePtr->data = value;
   //newNodePtr->link = 0;
   //if (headPtr == 0)
   //   headPtr = newNodePtr;
   //else if (headPtr->data >= value)
   //{
   //   newNodePtr->link = headPtr;
   //   headPtr = newNodePtr;
   //}
   if (headPtr == 0 || headPtr->data >= value)
   {
      newNodePtr->link = headPtr;
      headPtr = newNodePtr;
   }
   //else if (headPtr->link == 0)
   //   head->link = newNodePtr;
   else
   {
      Node *cursor = headPtr;
      while (cursor->link != 0 && cursor->link->data < value)
         cursor = cursor->link;
      //if (cursor->link != 0)
      //   newNodePtr->link = cursor->link;
      newNodePtr->link = cursor->link;
      cursor->link = newNodePtr;
   }

   ////////////////// commented lines removed //////////////////

   Node *newNodePtr = new Node;
   newNodePtr->data = value;
   if (headPtr == 0 || headPtr->data >= value)
   {
      newNodePtr->link = headPtr;
      headPtr = newNodePtr;
   }
   else
   {
      Node *cursor = headPtr;
      while (cursor->link != 0 && cursor->link->data < value)
         cursor = cursor->link;
      newNodePtr->link = cursor->link;
      cursor->link = newNodePtr;
   }
   */
   ///////////////////////////////////////////////////////////
}

bool DelFirstTargetNode(Node*& headPtr, int target)
{
   Node *precursor = 0,
        *cursor = headPtr;

  // while curser is not null and not equal to data
   while (cursor != 0 && cursor->data != target)
   {
      precursor = cursor;
      cursor = cursor->link;
   }
  // if the curser is null it is not in list.
   if (cursor == 0)
   {
      cout << target << " not found." << endl;
      return false;
   }
  // if the data is stored in head pointer reset head pointer to next link.
   if (cursor == headPtr) //OR precursor == 0
      headPtr = headPtr->link;
   else
      precursor->link = cursor->link;
  // delete current node
   delete cursor;
   return true;
}

bool DelNodeBefore1stMatch(Node*& headPtr, int target)
{
   if (headPtr == 0 || headPtr->link == 0 || headPtr->data == target) return false;
   Node *cur = headPtr->link, *pre = headPtr, *prepre = 0;
   while (cur != 0 && cur->data != target)
   {
      prepre = pre;
      pre = cur;
      cur = cur->link;
   }
   if (cur == 0) return false;
   if (cur == headPtr->link)
   {
      headPtr = cur;
      delete pre;
   }
   else
   {
      prepre->link = cur;
      delete pre;
   }
   return true;
}

// Traverse List
void ShowAll(ostream& outs, Node* headPtr)
{
   while (headPtr != 0)
   {
      outs << headPtr->data << "  ";
      headPtr = headPtr->link;
   }
   outs << endl;
}

void FindMinMax(Node* headPtr, int& minValue, int& maxValue)
{
  // check if list is empty
   if (headPtr == 0)
   {
      cerr << "FindMinMax() attempted on empty list" << endl;
      cerr << "Minimum and maximum values not set" << endl;
   }
   else
   {
    // Assign min and max value to the first element in list
      minValue = maxValue = headPtr->data;
    // While there is a next Node
      while (headPtr->link != 0)
      {
        // assign head to next link in chain
         headPtr = headPtr->link;
        // if the next value is smaller than min value, replace min value
         if (headPtr->data < minValue)
            minValue = headPtr->data;
         else if (headPtr->data > maxValue)  // else if next value is larger than max assign to maxValue
            maxValue = headPtr->data;
      }
   }
}

double FindAverage(Node* headPtr)
{
  // check for empty List
   if (headPtr == 0)
   {
      cerr << "FindAverage() attempted on empty list" << endl;
      cerr << "An arbitrary zero value is returned" << endl;
      return 0.0;
   }
   else
   {
      int sum = 0,
          count = 0;

      while (headPtr != 0)
      {
         ++count;
         sum += headPtr->data;
         headPtr = headPtr->link;
      }

      return double(sum) / count;
   }
}

void ListClear(Node*& headPtr, int noMsg)
{
   int count = 0;

   Node *cursor = headPtr;
   while (headPtr != 0)
   {
      headPtr = headPtr->link;
      delete cursor;
      cursor = headPtr;
      ++count;
   }
   if (noMsg) return;
   clog << "Dynamic memory for " << count << " nodes freed"
        << endl;
}

void RemOddDupEven(Node*& headPtr)
{
  Node *cur = headPtr;
  Node *pred = 0;

  while(cur != 0)
  {
      if(cur -> data % 2 == 0)
      {
        Node *newNode = new Node;
        newNode -> data = cur -> data;
        newNode -> link = 0;

        if(cur == headPtr)
        {
         newNode -> link = headPtr;
         headPtr = newNode;
        }
          else
          {
            pred -> link = newNode;
            newNode -> link = cur;
          }

        pred = cur;

        if(cur -> link != 0)
         cur = cur -> link;

          else
           return;
      }

      if(cur -> data % 2 == 1)
      {
        Node* nextNode = cur -> link;
        delete cur;
        cur = nextNode;

        if(pred)
         pred -> link = cur;

           else
            headPtr = cur;
      }
   }
 }
