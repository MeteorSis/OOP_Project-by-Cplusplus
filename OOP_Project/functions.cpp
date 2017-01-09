#include "main.h"

void makeAccount(void)
{
	cout << "[���°���]" << endl;
	cout << "����ID : ";
	cin >> accArr[accNum].accID;
	cout << "�� �� : ";
	cin >> accArr[accNum].cusName;
	cout << "�Աݾ� : ";
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
	searchedAcc->balance += money;
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
	if (searchedAcc->balance < money)
	{
		cout << "�ܾ��� �����մϴ�." << endl;
		return;
	}
	searchedAcc->balance -= money;
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
	{
		cout << "����ID : " << accArr[i].accID << endl;
		cout << "�� �� : " << accArr[i].cusName << endl;
		cout << "�� �� : " << accArr[i].balance << endl;
		cout << endl;
	}
}