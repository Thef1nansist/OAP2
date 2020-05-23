#include<iostream>
#include"List.h"
using namespace std;
void insert(Address* e, Address** phead, Address** plast)
{
	Address* p = *plast;
	if (*plast == NULL)
	{
		e->next = NULL;
		e->prev = NULL;
		*plast = e;
		*phead = e;
		return;
	}
	else
	{
		p->next = e;
		e->next = NULL;
		e->prev = p;
		*plast = e;
	}
}
//-----------------------------------------------------------
Address* setElement()
{
	Address* temp = new  Address();
	if (!temp)
	{
		cerr << "������ ��������� ������ ������";
		return NULL;
	}
	cout << "������� �������: ";
	cin >> temp->surname;
	cout << "������� ���: ";
	cin >> temp->name;
	cout << "������� ��������: ";
	cin >> temp->parentname;
	cout << "������� ��� �����: ";
	cin >> temp->type;
	cout << "������� ����� �����: ";
	cin >> temp->number;
	cout << "������� ����� �� �����: ";
	cin >> temp->sum;
	cout << "������� ���� ���������� ���������: ";
	cin >> temp->date;
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}
void outputList(Address** phead, Address** plast)
{
	Address* t = *phead;
	if (t == NULL)
	{
		cout << "������ ����!" << endl;
	}
	while (t)
	{
		cout << "�������:" << t->surname << endl;
		cout << "���:" << t->name << endl;
		cout << "��������:" << t->parentname << endl;
		cout << "��� �����:" << t->type << endl;
		cout << "����� �����:" << t->number << endl;
		cout << "����� �� �����:" << t->sum << endl;
		cout << "���� ���������� ����������:" << t->date << endl;
		t = t->next;
	}
	cout << "" << endl;
}
void find(char number[NAME_SIZE], Address** phead)
{
	Address* t = *phead;
	while (t)
	{
		if (!strcmp(number, t->number)) break;
		t = t->next;
	}
	if (!t)
		cerr << "��� �� �������" << endl;
	else
		cout << "�������:" << t->surname << endl;
	cout << "���:" << t->name << endl;
	cout << "��������:" << t->parentname << endl;
	cout << "��� �����:" << t->type << endl;
	cout << "����� �����:" << t->number << endl;
	cout << "����� �� �����:" << t->sum << endl;
	cout << "���� ���������� ����������:" << t->date << endl;
}
void countList(Address** phead, Address** plast)
{
	Address* t = *phead;
	int i = 0;
	while (t != NULL)
	{
		i++;
		t = t->next;
	}
	cout << "���������� ���������=" << i << endl;
}
void delAll(Address** phead, Address** plast)
{
	Address* t = *phead;
	while (t != NULL)
	{

		if (*phead == t)
		{
			*phead = t->next;
			if (*phead)
				(*phead)->prev = NULL;
			else
				*plast = NULL;
		}
		else
		{
			t->prev->next = t->next;
			if (t != *plast)
				t->next->prev = t->prev;
			else
				*plast = t->prev;
		}
		t = t->next;
		delete t;
	}
	cout << "������ ������!" << endl;
}