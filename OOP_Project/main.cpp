#include "main.h"
#include "menu.h"
#include "functions.h"

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
			cout << "\n���α׷��� �����մϴ�." << endl;
			return 0;
		}
	}
}