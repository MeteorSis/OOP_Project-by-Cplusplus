#pragma once
#include "account.h"
class NormalAccount : public Account
{
private:
	int interRate;
public:
	NormalAccount(const int &accID, const int &balance, char * const &cusName, const int &interRate);
	void deposit(const int &money);
	void showAccInfo(void) const;
};