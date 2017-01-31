#pragma once

#include <stdexcept>
#include <string>
#include <iostream>

using std::logic_error;
using std::string;
using std::cout;
using std::endl;

class insuffException : public logic_error
{
public:
	explicit insuffException(const char* what_arg)
		: logic_error(what_arg) {}
	explicit insuffException(const string& what_arg)
		: logic_error(what_arg) {}
};