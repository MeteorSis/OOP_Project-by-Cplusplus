#include "main.h"
#include "accountHandler.h"

int main(void)
{
	AccountHandler accHandler;
	while (true)
	{
		cout << endl;
		switch (accHandler.showAndInputMenu())
		{
		case MAKE:
			accHandler.makeAccount();
			break;
		case DEPOSIT:
			accHandler.depositMoney();
			break;
		case WITHDRAW:
			accHandler.withdrawMoney();
			break;
		case INQUIRE:
			accHandler.showAllAccInfo();
			break;
		case EXIT:
			cout << "\n���α׷��� �����մϴ�." << endl;
			return 0;
		}
	}
}