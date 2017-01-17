#include "main.h"
#include "highCreditAccount.h"

HighCreditAccount::HighCreditAccount(const int &accID, const int &balance, char * const &cusName, const int &interRate, const char &specialRate)
	:NormalAccount(accID, balance, cusName, interRate), specialRate(specialRate)
{

}

void HighCreditAccount::showAccInfo() const
{
	NormalAccount::showAccInfo();
	cout << "신용등급 : " << specialRate << endl;
}