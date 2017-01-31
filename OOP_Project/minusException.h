#pragma once

#include <stdexcept>
#include <string>
#include <iostream>

using std::logic_error;
using std::string;
using std::cout;
using std::endl;

class minusException : public logic_error
{
private:
	int money;
public:
	explicit minusException(const int& money, const char* what_arg)
		:money(money), logic_error(what_arg) {}
	explicit minusException(const int& money, const string& what_arg)
		:money(money), logic_error(what_arg) {}
	char const* what(void) const
	{
		cout << "\n�Է��� �ݾ� : " << money << "���� �����Դϴ�.";
		return logic_error::what();
	}
};