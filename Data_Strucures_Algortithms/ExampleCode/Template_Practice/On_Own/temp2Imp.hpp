#include <iostream>
using namespace std;

template<class OP>
OrderedPair<OP>::OrderedPair(OP xx, OP yy) : x(xx), y(yy) { }

template <class OP>
void OrderedPair<OP>::SetPair(OP xx, OP yy) {x = xx; y = yy;}

template <class OP>
void OrderedPair<OP>::ShowPair(ostream& outs) const
{ outs << '(' << x << ", " << y << ')'; }


/*
DoublePair::DoublePair(double xx, double yy) : x(xx), y(yy) { }

void DoublePair::SetPair(double xx, double yy) {x = xx; y = yy;}

void DoublePair::ShowPair(ostream& outs) const

{ outs << '(' << x << ", " << y << ')'; }
*/
