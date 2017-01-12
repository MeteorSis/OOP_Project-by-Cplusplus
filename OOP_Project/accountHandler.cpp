#include "accountHandler.h"

AccountHandler::AccountHandler() :accNum(0){}

int AccountHandler::showAndInputMenu() const//this is handler
{
	int choice;
	while (true)
	{
		cout << "-----Menu------" << endl;
		cout << "1. 계좌개설" << endl;
		cout << "2. 입 금" << endl;
		cout << "3. 출 금" << endl;
		cout << "4. 계좌정보 전체 출력" << endl;
		cout << "5. 프로그램 종료" << endl;
		cout << "선택 : ";
		cin >> choice;
		if (choice >= 1 && choice <= 5)
			break;
		cout << "\n값이 잘못되었습니다.\n다시 입력해주십시오\n" << endl;
	}
	cout << endl;
	return choice;
}

void AccountHandler::makeAccount(void)
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

void AccountHandler::depositMoney(void)
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

void AccountHandler::withdrawMoney(void)
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

void AccountHandler::showAllAccInfo(void)
{
	if (accNum == 0)
	{
		cout << "고객이 존재하지 않습니다." << endl;
		return;
	}
	for (int i = 0; i < accNum; ++i)
		accPtrArr[i]->showAccInfo();
}

Account* AccountHandler::searchID(int id)
{
	for (int i = 0; i < accNum; ++i)
		if (Account* accPtr = (accPtrArr[i]->getAccPtrFromID(id)))
			return accPtr;
	return nullptr;
}
