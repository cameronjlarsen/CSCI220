#pragma once
#ifndef SHRINKING_VECTOR_H
#define SHRINKING_VECTOR_H

#include <exception>
#include <algorithm>

typedef int Elem;						// base element type
class ShrinkingVector {
public:
	ShrinkingVector();					// constructor
	int size() const;					// number of elements
	bool empty() const;					// is vector empty?
	Elem& operator[](int i);			// element at index
	Elem& at(int i);					// element at index
	void erase(int i);					// remove element at index
	void insert(int i, const Elem& e);	// insert element at index
	void reserve(int N);				// reserve at least N spots
	void shrinkToFit();					// shrink to exact capacity
	int maxElements() const;			// max elements storable in current array
private:
	int capacity;						// current array size
	int num_elements;					// number of elements in vector
	Elem* element_array;				// array storing the elements
};

#endif // !SHRINKING_VECTOR_H