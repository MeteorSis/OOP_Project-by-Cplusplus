#pragma once

#include <stdexcept>
#include <string>

using std::logic_error;
using std::string;

class invalid_menu : public logic_error
{
public:
	explicit invalid_menu(const char* what_arg)
		:logic_error(what_arg) {}
	explicit invalid_menu(const string& what_arg)
		:logic_error(what_arg) {}
};