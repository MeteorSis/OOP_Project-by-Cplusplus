#pragma once

#include "BankingCommonDecl.h"
#include "normalAccount.h"
class HighCreditAccount : public NormalAccount
{
private:
	char specialRate;
public:
	HighCreditAccount(const int &accID, const int &balance, const String &cusName, const int &interRate, const char &specialRate);
	void deposit(const int &money) throw (minusException);
	void showAccInfo(void) const;
};