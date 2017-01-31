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
		cout << "\n입력한 금액 : " << money << "원은 음수입니다.";
		return logic_error::what();
	}
};