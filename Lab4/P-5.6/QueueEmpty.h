#pragma once
#include <exception>
class QueueEmpty :public std::exception
{
public:
	QueueEmpty(const char* error)					// constructor
		:errMsg(error) {}
	std::string getError() { return errMsg; }		// access error message

private:
	std::string errMsg;								// error message
};