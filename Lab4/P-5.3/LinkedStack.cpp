#include "LinkedStack.h"

template <typename T>
LinkedStack<T>::LinkedStack()
	: list(), num_elements(0) {}

template <typename T>
int LinkedStack<T>::size() const
{
	return num_elements;						// number of items in the stack
}

template <typename T>
bool LinkedStack<T>::empty() const
{
	return num_elements == 0;					// is the stack empty?
}

template <typename T>
const T& LinkedStack<T>::top() const
{	// get the top element
	try {
		if (empty())
			throw StackEmpty("Top of empty stack");
	}
	catch (StackEmpty) {
		return;
	}
		// do stuff
	return list.front();
}

template <typename T>
void LinkedStack<T>::push(const T& e)
{	// push element onto stack
	++num_elements;
	list.addFront(e);
}

template <typename T>
void LinkedStack<T>::pop()
{	// pop the stack
	try {
		if (empty())
			throw StackEmpty("Pop from empty stack");
	}
	catch (StackEmpty) {
		return;
	}
	--num_elements;
	list.removeFront();
}
