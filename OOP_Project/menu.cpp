#include "main.h"

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
	cout << endl;
	return choice;
}