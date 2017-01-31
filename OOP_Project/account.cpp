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
		throw minusException(money, "\n��� ���� �Է��ϼž��մϴ�.");
	balance += money;
}

void Account::withdraw(const int &money)
{
	if (money < 0)
		throw minusException(money, "\n��� ���� �Է��ϼž��մϴ�.");
	if (this->balance < money)
	{
		string tmpStr("\n�ܾ��� ���ڶ��ϴ�. : (�ܾ� : ");
		tmpStr.append(to_string(balance));
		tmpStr.append("��)");
		throw insuffException(tmpStr);
	}
	this->balance -= money;
}

void Account::showAccInfo(void) const
{
	cout << "\n����ID : " << accID << endl;
	cout << "�� �� : " << cusName << endl;
	cout << "�� �� : " << balance << endl;
}