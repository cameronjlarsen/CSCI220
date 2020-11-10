#ifndef FIBONACCI_H
#define FIBONACCI_H
#include "Progression.h"

class Fibonacci :public Progression
{
public:
	Fibonacci(long f = 0, long s = 1); // constructor
	virtual ~Fibonacci() {};
protected:
	virtual long firstValue();
	virtual long nextValue();
protected:
	long second;
	long prev;
};

#endif