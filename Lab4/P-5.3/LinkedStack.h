#pragma once
#include "SLinkedList.h"
#include "StackEmpty.h"
#include <string>

typedef std::string Elem;
template <typename T>
class LinkedStack {
public:
	LinkedStack();								// constructor
	int size() const;							// number of items in the stack
	bool empty() const;							// is the stack empty?
	const Elem& top() const throw(StackEmpty);	// the top element
	void push(const Elem& e);					// push element onto stack
	void pop();									// pop the stack
private:
	SLinkedList<Elem> S;						// linked list of elements
	int n;										// number of elements
};