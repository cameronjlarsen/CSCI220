#ifndef ARITHMETIC_H
#define ARITHMETIC_H

#include "Progression.h"

class Arithmetic :public Progression //arithmetic progression
{
public:
	Arithmetic(long i = 1); // constructor
	virtual ~Arithmetic() {};  // destructor
protected:
	virtual long nextValue(); // advance
protected:
	long inc; // increment
};

// 0 2 4 6 8 10 inc = 2

#endif