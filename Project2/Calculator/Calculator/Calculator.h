#pragma once
#include <string>
#include <exception>
#include "Stack.h"

class Calculator
{
public:
	Calculator(std::string exp);					// constructor
	~Calculator();									// destructor
	void postfix();									// returns the postfix expression
	void eval();									// returns the result of the expression
	void setExpr(std::string exp);					// receives the infix expression as string and store it
	std::string getExpr();							// returns the infix expression as string
	class InvalidExpression : public std::exception {
	public:
		InvalidExpression(const std::string& err) : std::exception() {}
	};
private:
	int result;										// result of expression
	std::string infix_tokens;						// infix expression
	std::string postfix_tokens;						// postfix expression
	bool isOperator(char input);					// check if input is an operator
	int prec(char input);							// return precedence value of operator in stack
	bool assoc(char input);							// returns associativity of operator: 0 = RL, 1 = LR
};

