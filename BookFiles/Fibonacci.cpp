#include <iostream>
#include "Fibonacci.h"
#include "Progression.h"

Fibonacci::Fibonacci(long f, long s) :Progression(f), second(s), prev(second - first) {}

long Fibonacci::firstValue()
{
	cur = first;
	prev = second - first;
	return cur;
}

long Fibonacci::nextValue()
{
	long temp = prev;
	prev = cur;
	cur += temp;
	return cur;
}