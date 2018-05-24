#include <iostream>
#include <cstdlib>
using namespace std;

template <class T>
void GetValue(T& value)
{
cout << "Enter value: ";
cin >> value;
}

int main()
{
int intValue;
double dblValue;
char charValue;

  GetValue(intValue);
  cout << "Value entered is "
       << intValue << endl;

  GetValue(dblValue);
  cout << "Value entered is "
       << dblValue << endl;

  GetValue(charValue);
  cout << "Value entered is "
       << charValue << endl;

return(EXIT_SUCCESS);
}
