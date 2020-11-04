#include "ShrinkingVector.h"

ShrinkingVector::ShrinkingVector()							// constructor
:capacity(0), num_elements(0), element_array(nullptr) {}

int ShrinkingVector::size() const							// number of elements
{
	return num_elements;
}

bool ShrinkingVector::empty() const							// is vector empty?
{
	return size() == 0;
}

Elem& ShrinkingVector::operator[](int i)					// element at index
{
	return element_array[i];
}

Elem& ShrinkingVector::at(int i)							// element at index(safe)
{
	try {
		if (i < 0 || i >= num_elements)
			throw std::exception("illegal index in function at()");
	}
	catch (std::exception& e) {
		return element_array[0];
	}
	return element_array[i];
}

void ShrinkingVector::erase(int i)							// remove element at index
{
	for (int j = i + 1; j < num_elements; j++)
		element_array[j - 1] = element_array[j];			// shift elements down
	num_elements--;											// one fewer element
}

void ShrinkingVector::insert(int i, const Elem& e)
{
	if (num_elements >= capacity)							// overflow?
		reserve(std::max(1, 2 * capacity));					// double array size
	for (int j = num_elements - 1; j >= i; j--)
		element_array[j + 1] = element_array[j];			// shift elements up
	element_array[i] = e;									// put in empty slot
	num_elements++;											// one more element
}

void ShrinkingVector::reserve(int N)						// reserve at least N spots
{
	if (capacity >= N) 
		return;												// already big enough
	Elem* temp_array = new Elem[N];							// allocate bigger array
	for (int j = 0; j < num_elements; j++)					// copy contents to new array
		temp_array[j] = element_array[j];
	if (element_array != nullptr) delete[]element_array;	// discard old array
	element_array = temp_array;								// make temp_array the new array
	capacity = N;											// set new capacity
}

void ShrinkingVector::shrinkToFit()							// shrink to exact capacity
{
	if (capacity == size())
		return;												// already to size
	Elem* temp_array = new Elem[num_elements];					// create a temp array of the current size
	for (int i = 0; i < num_elements; i++)					// copy contents to new array
		temp_array[i] = element_array[i];					
	if (element_array != nullptr) delete[]element_array;	// discard old array
	element_array = temp_array;								// make temp_array the new array
	capacity = size();										// set new capacity
}

int ShrinkingVector::maxElements() const					// max elements storable in current array
{
	return capacity;
}