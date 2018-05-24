#include "btNode.h"

void dumpToArrayInOrder(btNode* bst_root, int* dumpArray)
{
   if (bst_root == 0) return;

   int dumpIndex = 0;
   dumpToArrayInOrderAux(bst_root, dumpArray, dumpIndex);
}

void dumpToArrayInOrderAux(btNode* bst_root, int* dumpArray, int& dumpIndex)
{
   if (bst_root == 0) return;

   dumpToArrayInOrderAux(bst_root->left, dumpArray, dumpIndex);
   dumpArray[dumpIndex++] = bst_root->data;
   dumpToArrayInOrderAux(bst_root->right, dumpArray, dumpIndex);
}

void tree_clear(btNode*& root)
{
   if (root == 0) return;
   tree_clear(root->left);
   tree_clear(root->right);
   delete root;
   root = 0;
}

int bst_size(btNode* bst_root)
{
   if (bst_root == 0) return 0;
   return 1 + bst_size(bst_root->left) + bst_size(bst_root->right);
}

void bst_insert(btNode*& bst_root, int newData)
{
  if(bst_root == 0)
  {
    btNode* ntbi = new btNode;
    ntbi -> data = newData;
    ntbi -> left = 0;
    ntbi -> right = 0;
    bst_root = ntbi;
  }

  btNode* prev = 0;
  btNode* cur = bst_root;

  while(cur != 0)
  {
    if (newData < cur -> data)
    {
      prev = cur;
      cur = cur -> left;
    }

      else if(newData > cur -> data)
      {
        prev = cur;
        cur = cur -> right;
      }

        else
        {
          cur -> data = newData;
          return;
        }
  }

  btNode* ntbi = new btNode;
  ntbi -> left = 0;
  ntbi -> right = 0;
  ntbi -> data = newData;

   if(newData < prev -> data)
     prev -> left = ntbi;

   if(newData > prev -> data)
     prev -> right = ntbi;
}

 bool bst_remove(btNode*& bst_root, const int dataTBD)
 {
   if(bst_root == 0)
    return false;

   else if(dataTBD > bst_root -> data)
     return bst_remove(bst_root -> right, dataTBD);

    else if(dataTBD < bst_root -> data)
      return bst_remove(bst_root -> left, dataTBD);

     else
     {
          btNode* ntbd = bst_root;

          if(bst_root -> right == 0 && bst_root -> left != 0)
          {
            bst_root = bst_root -> left;
            delete ntbd;
          }

            else if(bst_root -> left == 0 && bst_root -> right != 0)
            {
             bst_root = bst_root -> right;
             delete ntbd;
            }

             else if(bst_root -> left == 0 && bst_root -> right == 0)
             {
              bst_root = 0;
              delete ntbd;
             }

              else
              {
                bst_remove_max(bst_root -> left, bst_root -> data);
              }
      }
      return true;
 }

 void bst_remove_max(btNode*& bst_root, int& newVal)
 {
   if(bst_root -> right == 0)
   {
     newVal = bst_root -> data;
     btNode* ntbd = bst_root;
     bst_root = bst_root -> left;
     delete ntbd;
     return;
   }
    else
     return bst_remove_max(bst_root -> right, newVal);
 }
