#include "ShrinkingVector.h"
#include <iostream>

int main() {
	std::cout << "Shrinking Vector Test\n";

	ShrinkingVector vec;
	std::cout << "\nInitial size and capacity";
	std::cout << "\nvec size: " << vec.size();
	std::cout << "\nvec capacity: " << vec.maxElements();

	vec.insert(0, 1);
	std::cout << "\nInsert element at index 0";
	std::cout << "\nvec size: " << vec.size();
	std::cout << "\nvec capacity: " << vec.maxElements();

	vec.reserve(10);
	std::cout << "\nReserve capacity of 10";
	std::cout << "\nvec size: " << vec.size();
	std::cout << "\nvec capacity: " << vec.maxElements();

	vec.shrinkToFit();
	std::cout << "\nShrink to fit";
	std::cout << "\nvec size: " << vec.size();
	std::cout << "\nvec capacity: " << vec.maxElements();
}