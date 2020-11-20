#include "Calculator.h"
#include <iostream>
// default constructor
Calculator::Calculator(std::string exp)						
:postfix_tokens(""), infix_tokens(""), result(0)
{
	setExpr(exp);
	if (getExpr() != "0") {
		postfix();
		eval();
	}
}
// destructor
Calculator::~Calculator() {}								
// returns the postfix expression
void Calculator::postfix()			
{
	Stack<char>stk;

	for (int i = 0; i < infix_tokens.length(); i++) {

		// if the scanned character is an operand add
		// it to the output string		
		if (isdigit(infix_tokens[i])) {
			postfix_tokens += infix_tokens[i];
			// if the next char is not a digit add a space
			if (!(isdigit(infix_tokens[i + 1])))
				postfix_tokens += ' ';
		}

		// if the scanned character is a '(' push it 
		// to the stack
		else if (infix_tokens[i] == '(')
			stk.push('(');

		// if the scanned character is an ')',
		// pop and output to string from stack until an '('
		// is encountered
		else if (infix_tokens[i] == ')') {
			while (!stk.empty() && stk.top() != '(') {
				char c = stk.top();
				stk.pop();
				postfix_tokens += c;
				postfix_tokens += ' ';
			}
			if (stk.top() == '(') {
				char c = stk.top();
				stk.pop();
			}
		}
		// TODO: add asscociativity
		// if an operator is scanned
		else if (isOperator(infix_tokens[i])) {
			// while the stack is not empty, the precedence of the operator is <= precedence of
			// the operator at the top of the stack and the operator is left-to-right asscociative
			while (!stk.empty() && prec(infix_tokens[i]) <= prec(stk.top()) && assoc(stk.top())) {
				char c = stk.top();
				stk.pop();
				postfix_tokens += c;
				postfix_tokens += ' ';
			}
			stk.push(infix_tokens[i]);
		}
	}

	// pop all remaining elements from the stack
	while (!stk.empty()){
		try {
			if (stk.top() == '(' || stk.top() == ')') {
				throw InvalidExpression("Invalid expression");
			}
			char c = stk.top();
			stk.pop();
			postfix_tokens += c;
			postfix_tokens += ' ';
		}
		catch (InvalidExpression& exp) {
			postfix_tokens = "Invalid Expression";
			break;
		}
	}
	std::cout << "\nPostfix Expression: " << postfix_tokens;

}
// returns the result of the expression
void Calculator::eval()						
{
	if (postfix_tokens == "Invalid Expression") {
		infix_tokens = "Invalid Expression";
		return;
	}
	// create stack to store expression
	Stack<int>stk;

	// scan all characters one by one
	for (int i = 0; postfix_tokens.length(); i++) {
		int val1 = 0;
		int val2 = 0;
		
		// if the character is a blank space then continue
		if (postfix_tokens[i] == ' ')continue;

		// if the scanned character is a digit
		// push it to the stack
		else if (std::isdigit(postfix_tokens[i])) {
			int num = 0;
			while (i < postfix_tokens.length() && isdigit(postfix_tokens[i])) {
				num = (num * 10) + (postfix_tokens[i] - '0');
				i++;
			}
			i--;
			stk.push(num);
		}

		// if the scanned character is an operator, pop
		// two elements from the stack and apply operator
		else if (isOperator(postfix_tokens[i])) {
			val1 = stk.top();
			stk.pop();
			val2 = stk.top();
			stk.pop();
			switch (postfix_tokens[i])
			{
			case '+': stk.push(val2 + val1);
				break;
			case '-': stk.push(val2 - val1);
				break;
			case '*': stk.push(val2 * val1);
				break;
			case '/': stk.push(val2 / val1);
				break;
			case '%': stk.push(val2 % val1);
				break;
			case '^': stk.push(pow(val2, val1));
				break;
			}
		}
		else
			break;
	}
	result = stk.top();
	stk.pop();

	std::cout << "\nResult: " << result;
}
// receives the infix expression as string and store it
void Calculator::setExpr(std::string exp)					
{
	infix_tokens = exp;
}
// returns the infix expression as string
std::string Calculator::getExpr()							
{
	return infix_tokens;
}
// check if input is an operator
bool Calculator::isOperator(char input)						
{
	switch (input)
	{
	case '+':
		return true;
	case '-':
		return true;
	case '*':
		return true;
	case '/':
		return true;
	case '%':
		return true;
	case'^':
		return true;
	default:
		return false;
		break;
	}
}
// return precedence value of operator
int Calculator::prec(char input)							
{
	switch (input)
	{
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
	case '%':
		return 2;
	case '^':
		return 3;
	default:
		return -1;
		break;
	}
}
// returns associativity of operator: 0 = RL, 1 = LR
bool Calculator::assoc(char input)							
{
	switch (input)
	{
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
		return true;
	case '^':
		return false;
	default:
		break;
	}
}
