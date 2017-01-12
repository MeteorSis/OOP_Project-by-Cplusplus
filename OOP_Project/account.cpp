#include "main.h"
#include "account.h"

Account::Account(const int &accID, const int &balance, char * const &cusName)
	:accID(accID), balance(balance), cusName(cusName){}

Account::~Account()
{
	delete cusName;
}

Account* Account::getAccPtrFromID(const int &accID)
{
	if (this->accID == accID)
		return this;
	return nullptr;
}

void Account::deposit(const int &money)
{
	balance += money;
}

bool Account::withdraw(const int &money)
{
	if (this->balance < money)
		return false;
	this->balance -= money;
	return true;
}

void Account::showAccInfo(void) const
{
	cout << "°èÁÂID : " << accID << endl;
	cout << "ÀÌ ¸§ : " << cusName << endl;
	cout << "ÀÜ ¾× : " << balance << endl;
	cout << endl;
}