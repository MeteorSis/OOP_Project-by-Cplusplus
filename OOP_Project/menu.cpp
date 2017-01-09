#include "main.h"

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
	cout << endl;
	return choice;
}