/*
	Program: Calculator
	Author: Cameron Larsen
	Course: CSCI 220
	Date: 11/16/2020
	Description: Calculator program that takes infix expressions
	converts to postfix expressions then evaluates and returns the result

	I certify that the following code is my own work.

	Exception(s): N/A
*/
#include "Calculator.h"
#include <iostream>

int main() {
	std::cout << "Author: Cameron Larsen\n\n";
	std::cout << "Welcome to my calculator\n";
	std::cout << "Enter 0 to exit program\n";
	std::string input;
	do {
		std::cout << "\nEnter an expression: ";
		std::getline(std::cin, input);
		Calculator calc(input);
		if (input == "0") {
			std::cout << "\nThanks for using my calculator";
			break;
		}
		else {
			continue;
		}
	} while (input != "0");
}