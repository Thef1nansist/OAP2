#include "Header.h"
using namespace std;

void push(int x, Stack* myStk)
{
	Stack* e = new Stack;
	e->data = x;
	e->next = myStk->head;
	myStk->head = e;
	cout << "��� ������?" << endl;
}



int pop(Stack* myStk)
{
	if (myStk->head == NULL)
	{
		cout << "���� ����!" << endl;
		return -1;
	}
	else
	{
		Stack* e = myStk->head;
		int a = myStk->head->data;
		myStk->head = myStk->head->next;
		delete e;
		return a;
	}
	cout << "��� ������?" << endl;
}

void show(Stack* myStk)
{
	Stack* e = myStk->head;
	int a;
	if (e == NULL)
		cout << "���� ����!" << endl;
	while (e != NULL)
	{
		a = e->data;
		cout << a << " ";
		e = e->next;
	}
	cout << endl;
	cout << "��� ������?" << endl;
}



void readstringlengths(Stack* myStk)  //��� ������� 2 ����, ��������� ������ �� �����, ��������� �� ����� � ��������� ����������� ������ ������� ����� 
{
	ifstream fin; string a;
	fin.open("text.txt");
	while (!fin.eof())
	{
		fin >> a;
		Stack* e = new Stack;
		e->data = a.length();
		e->next = myStk->head;
		myStk->head = e;
	}
	fin.close();
	show(myStk);  // ��� ����� ������� �� ����� ��� �������� ������������ ������, ������ ��� �������� ����� ����
}

void findmaxlength(Stack* myStk)  //��� ������� ���������� ���� � ������� ����� ��� ��������, � ������ �����, � ������� ����� � �����
{
	Stack* e = myStk->head;
	int maxlength = 0, number = 1, num = 0;
	while (e != NULL)
	{
		if (e->data > maxlength)
		{
			maxlength = e->data;
			num = number;
		}
		number++;
		e = e->next;
	}
	cout << "������������ ����������: " << maxlength << endl << "����� ���� ������, ������ � ����� �����: " << num << endl;
}
