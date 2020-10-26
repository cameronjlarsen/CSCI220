/*
	Program: SLinkedStackTest
	Author: Cameron Larsen
	Course: CSCI 220
	Date: 10/21/2020
	Description: Test program showing Stack ADT by means of a singly linked list

	I certify that the following code is my own work.

	Exception(s): N/A
*/

#include <iostream>
#include "LinkedStack.h"


int main()
{
	std::cout << "Author: Cameron Larsen\n"
			<< "This program will showcase an implementation of a stack data structure\n";

	LinkedStack<int> stack;

	std::cout << "\nLet's create a stack and check it's status\n";
	if (stack.empty()) {
		std::cout << "The stack is empty\n";
	}
	else {
		std::cout << "The stack is not empty\n";
	}
	
	std::cout << "The stack has a size of: " << stack.size() << "\n";
	std::cout << "\nLet's push some numbers onto the stack: 5, 7, 2\n";
	stack.push(5);
	stack.push(7);
	stack.push(2);

	std::cout << "\nLet's see if it's empty and check it's size\n";
	if (stack.empty()) {
		std::cout << "The stack is empty\n";
	}
	else {
		std::cout << "The stack is not empty\n";
	}
	std::cout << "The stack has a size of: " << stack.size() << "\n";
	std::cout << "Now lets pop some numbers from the stack, and re-check it's size\n";

	stack.pop();
	std::cout << "The stack has a size of: " << stack.size() << "\n";
	stack.pop();
	std::cout << "The stack has a size of: " << stack.size() << "\n";
	stack.pop();
	std::cout << "The stack has a size of: " << stack.size() << "\n";

	std::cout << "\nLet's see if it's empty and check it's size\n";
	if (stack.empty()) {
		std::cout << "The stack is empty\n";
	}
	else {
		std::cout << "The stack is not empty\n";
	}

	return 0;
}