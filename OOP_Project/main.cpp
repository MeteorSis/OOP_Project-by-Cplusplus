#include "main.h"
#include "menu.h"
//#include "account.h"

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
			cout << "\n���α׷��� �����մϴ�." << endl;
			return 0;
		}
	}
}