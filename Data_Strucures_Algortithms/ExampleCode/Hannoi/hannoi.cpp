#include <iostream>
using namespace std;

void Hanoi(int n, char fromPeg, char auxPeg, char toPeg)
{

   if (n > 0)
   {
    if (n == 1){
     cout << "Move disk from " << fromPeg << " to "
          << toPeg << endl;
    }

     else
     {
      Hanoi(n-1, fromPeg, toPeg, auxPeg);
      cout << "Move disk from " << fromPeg << " to "
           << toPeg << endl;
      Hanoi(n-1, auxPeg, fromPeg, toPeg);
      }
    }
}


int main(int argc, char* argv[])
{

  int n = 3;
  char fromPeg = 'A';
  char auxPeg = 'B';
  char toPeg = 'C';

  Hanoi(n,fromPeg,auxPeg,toPeg);

  return 0;
}
