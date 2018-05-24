#ifndef TEMP2INT_H
#define TEMP2INT_H
#include <iostream>

template <class OP>
class OrderedPair
{
private:
OP x, y;

public:
OrderedPair(OP xx = 0, OP yy = 0);

void SetPair(OP xx, OP yy);

void ShowPair(std::ostream& outs) const;
};

#include "temp2Imp.hpp"
/*
class DoublePair
{
 private:
 double x, y;
 public:
 DoublePair(double xx = 0, double yy = 0);
 void SetPair(double xx, double yy);
 void ShowPair(std::ostream& outs) const;
};
*/

#endif
