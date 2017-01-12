#include "main.h"
#include "menu.h"
#include "functions.h"
#include "account.h"

Account* accPtrArr[ACC_NUM_OF_MAX];
extern int accNum = 0;

int main(void)
{
	while (true)
	{
		cout << endl;
		switch (menu())
		{
		case MAKE:
			makeAccount();
			break;
		case DEPOSIT:
			depositMoney();
			break;
		case WITHDRAW:
			withdrawMoney();
			break;
		case INQUIRE:
			showAllAccInfo();
			break;
		case EXIT:
			cout << "\n프로그램을 종료합니다." << endl;
			return 0;
		}
	}
}