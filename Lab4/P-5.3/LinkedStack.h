#pragma once
#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

#include "SLinkedList.h"
#include "StackEmpty.h"
#include <string>

template <typename T>
class LinkedStack {
public:
	LinkedStack();								// constructor
	int size() const;							// number of items in the stack
	bool empty() const;							// is the stack empty?
	const T& top() const;	// the top element
	void push(const T& e);					// push element onto stack
	void pop();									// pop the stack
private:
	SLinkedList<T> list;						// linked list of elements
	int num_elements;							// number of elements
};
#endif // !LINKEDSTACK_H
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
