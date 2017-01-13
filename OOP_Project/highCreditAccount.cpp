#include "highCreditAccount.h"

HighCreditAccount::HighCreditAccount(const int &accID, const int &balance, char * const &cusName, const int &interRate, const char &specialRate)
	:NormalAccount(accID, balance, cusName, interRate), specialRate(specialRate)
{

}