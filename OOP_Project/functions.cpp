#include "main.h"

void makeAccount(void)
{
	int accID;
	char cusName[NAME_LEN];
	char *namePtr;
	int balance;
	 
	cout << "[���°���]" << endl;
	cout << "����ID : ";
	cin >> accID;
	cout << "�� �� : ";
	cin >> cusName;
	namePtr = new char[strlen(cusName) + 1];
	strcpy(namePtr, cusName);
	cout << "�Աݾ� : ";
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
	cout << "[��   ��]" << endl;
	cout << "����ID : ";
	cin >> id;
	Account* searchedAcc = searchID(id);
	if (searchedAcc == nullptr)
	{
		cout << "ID�� �������� �ʽ��ϴ�." << endl;
		return;
	}
	cout << "�Աݾ� : ";
	cin >> money;
	searchedAcc->deposit(money);
	cout << "�ԱݿϷ�" << endl;
}

void withdrawMoney(void)
{
	int id;
	int money;
	cout << "[��   ��]" << endl;
	cout << "����ID : ";
	cin >> id;
	Account* searchedAcc = searchID(id);
	if (searchedAcc == nullptr)
	{
		cout << "ID�� �������� �ʽ��ϴ�." << endl;
		return;
	}
	cout << "��ݾ� : ";
	cin >> money;
	if (!(searchedAcc->withdraw(money)))
	{
		cout << "�ܾ��� �����մϴ�." << endl;
		return;
	}
	cout << "��ݿϷ�" << endl;
}

void showAllAccInfo(void)
{
	if (accNum == 0)
	{
		cout << "���� �������� �ʽ��ϴ�." << endl;
		return;
	}
	for (int i = 0; i < accNum; ++i)
		accPtrArr[i]->showAccInfo();
}