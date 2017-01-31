#include "account.h"

Account::Account(const int &accID, const int &balance, const String &cusName)
	:accID(accID), balance(balance), cusName(cusName){}


ACCOUNT_PTR Account::getAccPtrFromID(const int &accID)
{
	if (this->accID == accID)
		return this;
	return nullptr;
}

void Account::deposit(const int &money)
{
	if (money < 0)
		throw minusException(money, "\n양수 값을 입력하셔야합니다.");
	balance += money;
}

void Account::withdraw(const int &money)
{
	if (money < 0)
		throw minusException(money, "\n양수 값을 입력하셔야합니다.");
	if (this->balance < money)
	{
		string tmpStr("\n잔액이 모자랍니다. : (잔액 : ");
		tmpStr.append(to_string(balance));
		tmpStr.append("원)");
		throw insuffException(tmpStr);
	}
	this->balance -= money;
}

void Account::showAccInfo(void) const
{
	cout << "\n계좌ID : " << accID << endl;
	cout << "이 름 : " << cusName << endl;
	cout << "잔 액 : " << balance << endl;
}