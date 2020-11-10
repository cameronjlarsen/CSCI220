#include <iostream>
#include "Progression.h"
#include "Arithmetic.h"

Arithmetic::Arithmetic(long i) :Progression(), inc(i) {};  // constructor

long Arithmetic::nextValue()
{
	cur += inc;
	return cur;
}
