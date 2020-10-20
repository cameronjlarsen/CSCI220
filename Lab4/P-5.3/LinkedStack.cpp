#include "LinkedStack.h"

template <typename T>
LinkedStack<T>::LinkedStack()
	: S(), n(0) {}

template <typename T>
int LinkedStack<T>::size() const
{
	return n;						// number of items in the stack
}

template <typename T>
bool LinkedStack<T>::empty() const
{
	return n == 0;					// is the stack empty?
}

template <typename T>
const Elem& LinkedStack<T>::top() const throw(StackEmpty)
{	// get the top element
	try {
		if (empty())
			throw StackEmpty("Top of empty stack");
	}
	catch (StackEmpty) {
		return;
	}
		// do stuff
	return S.front();
}

template <typename T>
void LinkedStack<T>::push(const Elem& e)
{	// push element onto stack
	++n;
	S.addFront(e);
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
	--n;
	S.removeFront();
}
