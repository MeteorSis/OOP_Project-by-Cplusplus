#include "main.h"

void makeAccount(void)
{
	int accID;
	char cusName[NAME_LEN];
	char *namePtr;
	int balance;
	 
	cout << "[계좌개설]" << endl;
	cout << "계좌ID : ";
	cin >> accID;
	cout << "이 름 : ";
	cin >> cusName;
	namePtr = new char[strlen(cusName) + 1];
	strcpy(namePtr, cusName);
	cout << "입금액 : ";
	cin >> balance;
	accPtrArr[accNum++] = new Account(accID, balance, namePtr);
}

Account* searchID(int id)
{
	for (int i = 0; i < accNum; ++i)
		if (Account* accPtr=(accPtrArr[i]->getAccPtrFromID(id)))
			return accPtr;
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
	searchedAcc->deposit(money);
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
	if (!(searchedAcc->withdraw(money)))
	{
		cout << "잔액이 부족합니다." << endl;
		return;
	}
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
		accPtrArr[i]->showAccInfo();
}