#pragma once
#include "normalAccount.h"
class HighCreditAccount : public NormalAccount
{
private:
	char specialRate;
public:
	HighCreditAccount(const int &accID, const int &balance, char * const &cusName, const int &interRate, const char &specialRate);
};