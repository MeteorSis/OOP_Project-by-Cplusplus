#include "main.h"

void makeAccount(void)
{
	cout << "[계좌개설]" << endl;
	cout << "계좌ID : ";
	cin >> accArr[accNum].accID;
	cout << "이 름 : ";
	cin >> accArr[accNum].cusName;
	cout << "입금액 : ";
	cin >> accArr[accNum++].balance;
}

Account* searchID(int id)
{
	for (int i = 0; i < accNum; ++i)
	{
		if (accArr[i].accID == id)
			return &accArr[i];
	}
	return nullptr;
}

void depositMoney(void)
{
	int id;
	int money;
	cout << "[입   금]" << endl;
	cout << "계좌ID : ";
	cin >> id;
	Account* searchedAcc = searchID(id);
	if (searchedAcc == nullptr)
	{
		cout << "ID가 존재하지 않습니다." << endl;
		return;
	}
	cout << "입금액 : ";
	cin >> money;
	searchedAcc->balance += money;
	cout << "입금완료" << endl;
}

void withdrawMoney(void)
{
	int id;
	int money;
	cout << "[출   금]" << endl;
	cout << "계좌ID : ";
	cin >> id;
	Account* searchedAcc = searchID(id);
	if (searchedAcc == nullptr)
	{
		cout << "ID가 존재하지 않습니다." << endl;
		return;
	}
	cout << "출금액 : ";
	cin >> money;
	if (searchedAcc->balance < money)
	{
		cout << "잔액이 부족합니다." << endl;
		return;
	}
	searchedAcc->balance -= money;
	cout << "출금완료" << endl;
}

void showAllAccInfo(void)
{
	if (accNum == 0)
	{
		cout << "고객이 존재하지 않습니다." << endl;
		return;
	}
	for (int i = 0; i < accNum; ++i)
	{
		cout << "계좌ID : " << accArr[i].accID << endl;
		cout << "이 름 : " << accArr[i].cusName << endl;
		cout << "잔 액 : " << accArr[i].balance << endl;
		cout << endl;
	}
}