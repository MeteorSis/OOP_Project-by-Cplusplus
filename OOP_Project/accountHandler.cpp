#include "accountHandler.h"

AccountHandler::AccountHandler() :accPtrArr(ACC_NUM_OF_MAX), accNum(0){}

int AccountHandler::showAndInputMenu() const
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
	String cusName;
	int balance;

	int kindOfAcc;
	while (true)
	{
		cout << "[계좌종류선택]" << endl;
		cout << "1. 보통예금계좌 2. 신용신뢰계좌" << endl;
		cout << "선택 : ";
		cin >> kindOfAcc;
		if(kindOfAcc==NORMALACC || kindOfAcc==HIGHCREDITACC)
			break;
		cout << "잘못된 값을 입력하셨습니다." << endl;
	}
	
	switch (kindOfAcc)
	{
	case NORMALACC:
		cout << "[보통예금계좌 개설]" << endl;
		break;
	case HIGHCREDITACC:
		cout << "[신용신뢰계좌 개설]" << endl;
		break;
	}
	cout << "계좌ID : ";
	cin >> accID;
	cout << "이 름 : ";
	cin >> cusName;
	cout << "입금액 : ";
	cin >> balance;

	int interRate;
	cout << "이자율 : ";
	cin >> interRate;

	switch (kindOfAcc)
	{
	case NORMALACC:
		accPtrArr[accNum++] = new NormalAccount(accID, balance, cusName, interRate);
		break;
	case HIGHCREDITACC:
		char specialRate;
		while (true)
		{
			cout << "신용등급 (A, B, C) : ";
			cin >> specialRate;
			if ((specialRate >= 'A' && specialRate <= 'C') || (specialRate >= 'a' && specialRate <= 'c'))
				break;
			cout << "올바르지 않은 등급을 입력하셨습니다." << endl;
		}
		accPtrArr[accNum++] = new HighCreditAccount(accID, balance, cusName, interRate, specialRate);
		break;
	}
	
}

void AccountHandler::depositMoney(void)
{
	int id;
	int money;
	cout << "[입   금]" << endl;
	cout << "계좌ID : ";
	cin >> id;
	ACCOUNT_PTR searchedAcc = searchID(id);
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
	ACCOUNT_PTR searchedAcc = searchID(id);
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
	{
		accPtrArr[i]->showAccInfo();
		cout << endl;
	}
}

ACCOUNT_PTR AccountHandler::searchID(int id)
{
	for (int i = 0; i < accNum; ++i)
		if (ACCOUNT_PTR accPtr = (accPtrArr[i]->getAccPtrFromID(id)))
			return accPtr;
	return nullptr;
}
