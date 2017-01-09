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
			cout << "\n���α׷��� �����մϴ�." << endl;
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
	return choice;
}