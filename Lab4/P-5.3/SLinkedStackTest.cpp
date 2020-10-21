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
	std::cout << "Author: Cameron Larsen\n\n";

	LinkedStack<int> stack;

	std::cout << stack.empty();


	stack.push(5);
	stack.push(7);
	stack.push(2);

	

	return 0;
}