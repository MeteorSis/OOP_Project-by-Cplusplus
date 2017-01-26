#include "normalAccount.h"

NormalAccount::NormalAccount(const int &accID, const int &balance, const String &cusName, const int &interRate)
	:Account(accID, balance, cusName), interRate(interRate){}

void NormalAccount::deposit(const int &money)
{
	Account::deposit(money);
	Account::deposit(money*(interRate / 100.0));
}

void NormalAccount::showAccInfo() const
{
	Account::showAccInfo();
	cout << "ÀÌÀÚÀ² : " << interRate << "%" << endl;
}