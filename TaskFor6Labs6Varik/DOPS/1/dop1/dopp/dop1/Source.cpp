#include "Header.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	int choice;
	char s[50];
	Stack* myStk = new Stack; //��������� ������ ��� �����
	myStk->head = NULL;       //������������� ������� ��������	
	cout << "�������� �������:" << endl;
	cout << "1 - ���������� �������� � ����" << endl;
	cout << "2 - ���������� �������� �� �����" << endl;
	cout << "3 - ����� �����" << endl;
	cout << "4 - (������ ��� 1 ���) ���������� ���������� �������� � ����" << endl; //����� 1 ����
	cout << "5 - (����� ��� 2 ���) ������������� �������� ������" << endl; // ������ ����� 1 ����

	cout << "6 - �����" << endl;
	for (;;)
	{
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "������� �������: " << endl;
			cin >> choice;
			push(choice, myStk);
			break;
		case 2:
			choice = pop(myStk);
			if (choice != -1)
				cout << "����������� �������: " << choice << endl;
			break;
		case 3:
			cout << "���� ����: " << endl;
			show(myStk);
			break;
		case 4:
			cout << "������� ������: ";
			cin >> s;
			pushstr(s, myStk);
			break;
		case 5:
			printstring(myStk);
			break;

		case 6:
			exit(1);
		}
	}
	return 0;
}