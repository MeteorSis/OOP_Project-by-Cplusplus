#pragma once

#include <stdexcept>
#include <string>

using std::logic_error;
using std::string;

class invalid_variable : public logic_error
{
public:
	explicit invalid_variable(const char* what_arg)
		:logic_error(what_arg) {}
	explicit invalid_variable(const string& what_arg)
		:logic_error(what_arg) {}
};