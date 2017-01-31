#include "accountHandler.h"

AccountHandler::AccountHandler() : accPtrArr(ACC_NUM_OF_MAX), accNum(0){}

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
		try
		{
			if (!(cin >> choice))
				throw invalid_variable("\n정수 값을 입력하셔야합니다.");
			
			if (choice < 1 || choice > 5)
				throw invalid_menu("\n존재하지 않는 메뉴를 입력하셨습니다.");

			return choice;
		}
		catch (logic_error &ex)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ex.what() << endl;
			cout << "다시 입력해주십시오" << endl << endl;
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
		cout << "\n[계좌종류선택]" << endl;
		cout << "1. 보통예금계좌 2. 신용신뢰계좌" << endl;
		cout << "선택 : ";

		try
		{
			if (!(cin >> kindOfAcc))
				throw invalid_variable("\n정수 값을 입력하셔야합니다.");

			if (kindOfAcc != NORMALACC && kindOfAcc != HIGHCREDITACC)
				throw invalid_menu("\n존재하지 않는 메뉴를 입력하셨습니다.");

			break;
		}
		catch (logic_error &ex)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ex.what() << endl;
			cout << "다시 입력해주십시오" << endl;
		}
	}
	
	switch (kindOfAcc)
	{
	case NORMALACC:
		cout << "\n[보통예금계좌 개설]" << endl;
		break;
	case HIGHCREDITACC:
		cout << "\n[신용신뢰계좌 개설]" << endl;
		break;
	}

	while (true)
	{
		cout << "계좌ID : ";
		try
		{
			if (!(cin >> accID))
				throw invalid_variable("\n정수 값을 입력하셔야합니다.");
			break;
		}
		catch (invalid_variable &ex)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ex.what() << endl;
			cout << "다시 입력해주십시오" << endl << endl;
		}
	}
	cout << "이 름 : ";
	cin >> cusName;
	while (true)
	{
		cout << "입금액 : ";
		try
		{
			if (!(cin >> balance))
				throw invalid_variable("\n정수 값을 입력하셔야합니다.");
			if (balance < 0)
				throw minusException(balance, "\n양수 값을 입력하셔야합니다.");
			break;
		}
		catch (invalid_variable &ex)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ex.what() << endl;
			cout << "다시 입력해주십시오" << endl << endl;
		}
		catch (minusException &ex)
		{
			cout << ex.what() << endl;
			cout << "다시 입력해주십시오" << endl << endl;
		}
	}
	
	int interRate;
	while (true)
	{
		cout << "이자율 : ";
		try
		{
			if (!(cin >> interRate))
				throw invalid_variable("\n정수 값을 입력하셔야합니다.");
			break;
		}
		catch (invalid_variable &ex)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ex.what() << endl;
			cout << "다시 입력해주십시오" << endl << endl;
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
	cout << "\n[입   금]" << endl;
	cout << "계좌ID : ";
	cin >> id;
	ACCOUNT_PTR searchedAcc = searchID(id);
	if (searchedAcc == nullptr)
	{
		cout << "ID가 존재하지 않습니다." << endl;
		return;
	}
	while (true)
	{
		cout << "입금액 : ";
		cin >> money;
		try
		{
			searchedAcc->deposit(money);
			break;
		}
		catch (minusException &ex)
		{
			cout << ex.what() << endl;
			cout << "다시 입력해주십시오" << endl << endl;
		}
	}
		
	cout << "입금완료" << endl;
}

void AccountHandler::withdrawMoney(void)
{
	int id;
	int money;
	cout << "\n[출   금]" << endl;
	cout << "계좌ID : ";
	cin >> id;
	ACCOUNT_PTR searchedAcc = searchID(id);
	if (searchedAcc == nullptr)
	{
		cout << "ID가 존재하지 않습니다." << endl;
		return;
	}
	while (true)
	{
		cout << "출금액 : ";
		cin >> money;
		try
		{
			searchedAcc->withdraw(money);
			break;
		}
		catch (insuffException &ex)
		{
			cout << ex.what() << endl;
			cout << "다시 입력해주십시오" << endl << endl;
		}
		catch (minusException &ex)
		{
			cout << ex.what() << endl;
			cout << "다시 입력해주십시오" << endl << endl;
		}
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
	}
}

ACCOUNT_PTR AccountHandler::searchID(int id)
{
	for (int i = 0; i < accNum; ++i)
		if (ACCOUNT_PTR accPtr = (accPtrArr[i]->getAccPtrFromID(id)))
			return accPtr;
	return nullptr;
}
