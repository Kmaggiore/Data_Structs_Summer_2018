#include "temp2Int.h"
#include <cstdlib>
#include <iostream>
using namespace std;
int main()
{
 OrderedPair<int> intObj;
 OrderedPair<double> doubleObj; 

 intObj.SetPair(3, 5);
 doubleObj.SetPair(3.3, 5.5);
 cout << "\nOrdered pair of integers: ";

 intObj.ShowPair(cout);
 cout << "\nOrdered pair of doubles: ";

 doubleObj.ShowPair(cout);
 cout << endl;

return (EXIT_SUCCESS);
}
