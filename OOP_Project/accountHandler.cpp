#include "accountHandler.h"

AccountHandler::AccountHandler() :accNum(0){}

int AccountHandler::showAndInputMenu() const
{
	int choice;
	while (true)
	{
		cout << "-----Menu------" << endl;
		cout << "1. ���°���" << endl;
		cout << "2. �� ��" << endl;
		cout << "3. �� ��" << endl;
		cout << "4. �������� ��ü ���" << endl;
		cout << "5. ���α׷� ����" << endl;
		cout << "���� : ";
		cin >> choice;
		if (choice >= 1 && choice <= 5)
			break;
		cout << "\n���� �߸��Ǿ����ϴ�.\n�ٽ� �Է����ֽʽÿ�\n" << endl;
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

	int kindOfAcc;
	while (true)
	{
		cout << "[������������]" << endl;
		cout << "1. ���뿹�ݰ��� 2. �ſ�ŷڰ���" << endl;
		cout << "���� : ";
		cin >> kindOfAcc;
		if(kindOfAcc==NORMALACC || kindOfAcc==HIGHCREDITACC)
			break;
		cout << "�߸��� ���� �Է��ϼ̽��ϴ�." << endl;
	}
	
	switch (kindOfAcc)
	{
	case NORMALACC:
		cout << "[���뿹�ݰ��� ����]" << endl;
		break;
	case HIGHCREDITACC:
		cout << "[�ſ�ŷڰ��� ����]" << endl;
		break;
	}
	cout << "����ID : ";
	cin >> accID;
	cout << "�� �� : ";
	cin >> cusName;
	namePtr = new char[strlen(cusName) + 1];
	strcpy(namePtr, cusName);
	cout << "�Աݾ� : ";
	cin >> balance;

	int interRate;
	cout << "������ : ";
	cin >> interRate;

	switch (kindOfAcc)
	{
	case NORMALACC:
		accPtrArr[accNum++] = new NormalAccount(accID, balance, namePtr, interRate);
		break;
	case HIGHCREDITACC:
		char specialRate;
		while (true)
		{
			cout << "�ſ��� (A, B, C) : ";
			cin >> specialRate;
			if ((specialRate >= 'A' && specialRate <= 'C') || (specialRate >= 'a' && specialRate <= 'c'))
				break;
			cout << "�ùٸ��� ���� ����� �Է��ϼ̽��ϴ�." << endl;
		}
		accPtrArr[accNum++] = new HighCreditAccount(accID, balance, namePtr, interRate, specialRate);
		break;
	}
	
}

void AccountHandler::depositMoney(void)
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

void AccountHandler::withdrawMoney(void)
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

void AccountHandler::showAllAccInfo(void)
{
	if (accNum == 0)
	{
		cout << "���� �������� �ʽ��ϴ�." << endl;
		return;
	}
	for (int i = 0; i < accNum; ++i)
	{
		accPtrArr[i]->showAccInfo();
		cout << endl;
	}
}

Account* AccountHandler::searchID(int id)
{
	for (int i = 0; i < accNum; ++i)
		if (Account* accPtr = (accPtrArr[i]->getAccPtrFromID(id)))
			return accPtr;
	return nullptr;
}
