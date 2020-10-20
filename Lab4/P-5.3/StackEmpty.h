#pragma once
#include <exception>
class StackEmpty:public std::exception
{
public:
	StackEmpty(const char* error)					// constructor
		:errMsg(error) {}
	std::string getError() { return errMsg; }		// access error message
	
private:
	std::string errMsg;								// error message
};
