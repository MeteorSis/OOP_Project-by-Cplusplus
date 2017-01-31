#include "accountHandler.h"

AccountHandler::AccountHandler() : accPtrArr(ACC_NUM_OF_MAX), accNum(0){}

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
		try
		{
			if (!(cin >> choice))
				throw invalid_variable("\n���� ���� �Է��ϼž��մϴ�.");
			
			if (choice < 1 || choice > 5)
				throw invalid_menu("\n�������� �ʴ� �޴��� �Է��ϼ̽��ϴ�.");

			return choice;
		}
		catch (logic_error &ex)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ex.what() << endl;
			cout << "�ٽ� �Է����ֽʽÿ�" << endl << endl;
		}
	}
}

void AccountHandler::makeAccount(void)
{
	int accID;
	String cusName;
	int balance;

	int kindOfAcc;
	while (true)
	{
		cout << "\n[������������]" << endl;
		cout << "1. ���뿹�ݰ��� 2. �ſ�ŷڰ���" << endl;
		cout << "���� : ";

		try
		{
			if (!(cin >> kindOfAcc))
				throw invalid_variable("\n���� ���� �Է��ϼž��մϴ�.");

			if (kindOfAcc != NORMALACC && kindOfAcc != HIGHCREDITACC)
				throw invalid_menu("\n�������� �ʴ� �޴��� �Է��ϼ̽��ϴ�.");

			break;
		}
		catch (logic_error &ex)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ex.what() << endl;
			cout << "�ٽ� �Է����ֽʽÿ�" << endl;
		}
	}
	
	switch (kindOfAcc)
	{
	case NORMALACC:
		cout << "\n[���뿹�ݰ��� ����]" << endl;
		break;
	case HIGHCREDITACC:
		cout << "\n[�ſ�ŷڰ��� ����]" << endl;
		break;
	}

	while (true)
	{
		cout << "����ID : ";
		try
		{
			if (!(cin >> accID))
				throw invalid_variable("\n���� ���� �Է��ϼž��մϴ�.");
			break;
		}
		catch (invalid_variable &ex)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ex.what() << endl;
			cout << "�ٽ� �Է����ֽʽÿ�" << endl << endl;
		}
	}
	cout << "�� �� : ";
	cin >> cusName;
	while (true)
	{
		cout << "�Աݾ� : ";
		try
		{
			if (!(cin >> balance))
				throw invalid_variable("\n���� ���� �Է��ϼž��մϴ�.");
			if (balance < 0)
				throw minusException(balance, "\n��� ���� �Է��ϼž��մϴ�.");
			break;
		}
		catch (invalid_variable &ex)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ex.what() << endl;
			cout << "�ٽ� �Է����ֽʽÿ�" << endl << endl;
		}
		catch (minusException &ex)
		{
			cout << ex.what() << endl;
			cout << "�ٽ� �Է����ֽʽÿ�" << endl << endl;
		}
	}
	
	int interRate;
	while (true)
	{
		cout << "������ : ";
		try
		{
			if (!(cin >> interRate))
				throw invalid_variable("\n���� ���� �Է��ϼž��մϴ�.");
			break;
		}
		catch (invalid_variable &ex)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ex.what() << endl;
			cout << "�ٽ� �Է����ֽʽÿ�" << endl << endl;
		}
	}

	switch (kindOfAcc)
	{
	case NORMALACC:
		accPtrArr[accNum++] = new NormalAccount(accID, balance, cusName, interRate);
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
		accPtrArr[accNum++] = new HighCreditAccount(accID, balance, cusName, interRate, specialRate);
		break;
	}
	
}

void AccountHandler::depositMoney(void)
{
	int id;
	int money;
	cout << "\n[��   ��]" << endl;
	cout << "����ID : ";
	cin >> id;
	ACCOUNT_PTR searchedAcc = searchID(id);
	if (searchedAcc == nullptr)
	{
		cout << "ID�� �������� �ʽ��ϴ�." << endl;
		return;
	}
	while (true)
	{
		cout << "�Աݾ� : ";
		cin >> money;
		try
		{
			searchedAcc->deposit(money);
			break;
		}
		catch (minusException &ex)
		{
			cout << ex.what() << endl;
			cout << "�ٽ� �Է����ֽʽÿ�" << endl << endl;
		}
	}
		
	cout << "�ԱݿϷ�" << endl;
}

void AccountHandler::withdrawMoney(void)
{
	int id;
	int money;
	cout << "\n[��   ��]" << endl;
	cout << "����ID : ";
	cin >> id;
	ACCOUNT_PTR searchedAcc = searchID(id);
	if (searchedAcc == nullptr)
	{
		cout << "ID�� �������� �ʽ��ϴ�." << endl;
		return;
	}
	while (true)
	{
		cout << "��ݾ� : ";
		cin >> money;
		try
		{
			searchedAcc->withdraw(money);
			break;
		}
		catch (insuffException &ex)
		{
			cout << ex.what() << endl;
			cout << "�ٽ� �Է����ֽʽÿ�" << endl << endl;
		}
		catch (minusException &ex)
		{
			cout << ex.what() << endl;
			cout << "�ٽ� �Է����ֽʽÿ�" << endl << endl;
		}
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
	}
}

ACCOUNT_PTR AccountHandler::searchID(int id)
{
	for (int i = 0; i < accNum; ++i)
		if (ACCOUNT_PTR accPtr = (accPtrArr[i]->getAccPtrFromID(id)))
			return accPtr;
	return nullptr;
}
