#include <iostream>
using namespace std;

int menu(void);
void makeAccount(void);
void depositMoney(void);
void withdrawMoney(void);
void showAllAccInfo(void);

int main(void)
{
	while (true)
	{
		switch (menu())
		{
		case 1:
			makeAccount();
			break;
		case 2:
			depositMoney();
			break;
		case 3:
			withdrawMoney();
			break;
		case 4:
			showAllAccInfo();
			break;
		case 5:
			cout << "\n프로그램을 종료합니다." << endl;
			return 0;
		}
	}
}

int menu(void)
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
	return choice;
}