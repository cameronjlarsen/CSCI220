#pragma once
#include <exception>
#include <string>
#include "LinkedList.h"

template <typename A>
class Stack
{
public:
	Stack();								// constructor
	~Stack();								// destructor
	int size() const;						// number of items in stack
	bool empty() const;						// is the stack empty?
	const A& top() const;	// the top element
	void push(const A& e);					// push e onto the stack
	void pop();			// remove the top element

	class StackEmpty : public std::exception {
	public:
		StackEmpty(const std::string& err) : std::exception() {}
	};
private:
	LinkedList<A> S;						// linked list of elements
	int n;								// number of elements
};



template<typename A>
inline Stack<A>::Stack()										// constructor
:S(), n(0) {}

template<typename A>
inline Stack<A>::~Stack()										// destructor
{
	while (!empty()) pop();
}

template<typename A>
inline int Stack<A>::size() const								// number of items in stack
{
	return n;
}

template<typename A>
inline bool Stack<A>::empty() const								// is stack empty?
{
	return n == 0;
}

template<typename A>
inline const A& Stack<A>::top() const			// get the top element
{
	if (empty()) throw StackEmpty("Top of stack empty");
	return S.front();
}

template<typename A>
inline void Stack<A>::push(const A& e)							// push element onto stack
{
	++n;
	S.addFront(e);
}

template<typename A>
inline void Stack<A>::pop()					// pop the stack
{
	if (empty()) throw StackEmpty("Pop from empty stack");
	--n;
	S.removeFront();
}
