#include "highCreditAccount.h"

HighCreditAccount::HighCreditAccount(const int &accID, const int &balance, char * const &cusName, const int &interRate, const char &specialRate)
	:NormalAccount(accID, balance, cusName, interRate), specialRate(specialRate){}

void HighCreditAccount::deposit(const int &money)
{
	NormalAccount::deposit(money);
	double spRate;
	switch (specialRate)
	{
	case 'A': case 'a':
		spRate = 0.07;
		break;
	case 'B': case 'b':
		spRate = 0.04;
		break;
	case 'C': case 'c':
		spRate = 0.02;
		break;
	}
	Account::deposit(money*spRate);
}

void HighCreditAccount::showAccInfo() const
{
	NormalAccount::showAccInfo();
	cout << "신용등급 : " << specialRate << endl;
}