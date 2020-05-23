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
	cout << "������� ���� ��������: " << endl;;
	cout << "������� ����:";
	cin >> temp->day;
	cout << endl;
	cout << "������� �����:";
	cin >> temp->month;
	cout << endl;
	cout << "������� ���:";
	cin >> temp->year;
	cout << endl;
	cout << "������� ����� �����: ";
	cin >> temp->course;
	cout << "������� ����� ������: ";
	cin >> temp->group;
	cout << "������� ������ �� ���������: " << endl;
	cout << "����������:";
	cin >> temp->math;
	cout << endl;
	cout << "����:";
	cin >> temp->OAIP;
	cout << endl;
	cout << "���������� ����:";
	cin >> temp->English;
	cout << endl;
	cout << "��:";
	cin >> temp->Yap;
	cout << endl;
	cout << "���:";
	cin >> temp->Kyar;
	cout << endl;
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

		cout << "--------------------------------------------------" << endl;
		cout << "�������:" << t->surname << endl;
		cout << "���:" << t->name << endl;
		cout << "��������:" << t->parentname << endl;
		cout << "���� ��������:" << t->day << "." << t->month << "." << t->year << endl;
		cout << "����:" << t->course << endl;
		cout << "������:" << t->group << endl;
		cout << "������:" << endl;
		cout << "����������:" << t->math << endl;
		cout << "����:" << t->OAIP << endl;
		cout << "���������� ����:" << t->English << endl;
		cout << "��:" << t->Yap << endl;
		cout << "���:" << t->Kyar << endl;
		t = t->next;

	}
}
void outputFirstCourse(Address** phead, Address** plast)
{
	int i = 0;
	Address* t = *phead;
	if (t == NULL)
	{
		cout << "������ ����!" << endl;
	}
	cout << "---------------------�������� 1 �����-------------------" << endl;
	if (strcmp(t->surname, (t->next)->surname) > 0)
	{
		t = t->next;
		t->next = t->prev;
		t->prev = t;
	}
	while (i != 2)
	{


		if (t->course == 1)
		{
			cout << "--------------------------------------------------" << endl;
			cout << "�������:" << t->surname << endl;
			cout << "���:" << t->name << endl;
			cout << "��������:" << t->parentname << endl;
			cout << "���� ��������:" << t->day << "." << t->month << "." << t->year << endl;
			cout << "����:" << t->course << endl;
			cout << "������:" << t->group << endl;
			cout << "������:" << endl;
			cout << "����������:" << t->math << endl;
			cout << "����:" << t->OAIP << endl;
			cout << "���������� ����:" << t->English << endl;
			cout << "��:" << t->Yap << endl;
			cout << "���:" << t->Kyar << endl;
			t = t->next;
		}
		else
		{
			t = t->next;
		}

		i++;
	}
}
void outputSecondCourse(Address** phead, Address** plast)
{
	Address* t = *phead;
	if (t == NULL)
	{
		cout << "������ ����!" << endl;
	}
	cout << "--------------------�������� 2 �����----------------" << endl;
	while (t)
	{
		if (t->course == 2)
		{
			cout << "--------------------------------------------------" << endl;
			cout << "�������:" << t->surname << endl;
			cout << "���:" << t->name << endl;
			cout << "��������:" << t->parentname << endl;
			cout << "���� ��������:" << t->day << "." << t->month << "." << t->year << endl;
			cout << "����:" << t->course << endl;
			cout << "������:" << t->group << endl;
			cout << "������:" << endl;
			cout << "����������:" << t->math << endl;
			cout << "����:" << t->OAIP << endl;
			cout << "���������� ����:" << t->English << endl;
			cout << "��:" << t->Yap << endl;
			cout << "���:" << t->Kyar << endl;
			t = t->next;
		}
		else
			t = t->next;

	}
}
void outputThirdCourse(Address** phead, Address** plast)
{
	Address* t = *phead;
	if (t == NULL)
	{
		cout << "������ ����!" << endl;
	}
	cout << "--------------------�������� 3 �����----------------" << endl;
	while (t)
	{
		if (t->course == 3)
		{
			cout << "--------------------------------------------------" << endl;
			cout << "�������:" << t->surname << endl;
			cout << "���:" << t->name << endl;
			cout << "��������:" << t->parentname << endl;
			cout << "���� ��������:" << t->day << "." << t->month << "." << t->year << endl;
			cout << "����:" << t->course << endl;
			cout << "������:" << t->group << endl;
			cout << "������:" << endl;
			cout << "����������:" << t->math << endl;
			cout << "����:" << t->OAIP << endl;
			cout << "���������� ����:" << t->English << endl;
			cout << "��:" << t->Yap << endl;
			cout << "���:" << t->Kyar << endl;
			t = t->next;
		}
		else
			t = t->next;

	}
}
void outputFourthCourse(Address** phead, Address** plast)
{
	Address* t = *phead;
	if (t == NULL)
	{
		cout << "������ ����!" << endl;
	}
	cout << "--------------------�������� 4 �����----------------" << endl;
	while (t)
	{
		if (t->course == 4)
		{
			cout << "--------------------------------------------------" << endl;
			cout << "�������:" << t->surname << endl;
			cout << "���:" << t->name << endl;
			cout << "��������:" << t->parentname << endl;
			cout << "���� ��������:" << t->day << "." << t->month << "." << t->year << endl;
			cout << "����:" << t->course << endl;
			cout << "������:" << t->group << endl;
			cout << "������:" << endl;
			cout << "����������:" << t->math << endl;
			cout << "����:" << t->OAIP << endl;
			cout << "���������� ����:" << t->English << endl;
			cout << "��:" << t->Yap << endl;
			cout << "���:" << t->Kyar << endl;
			t = t->next;
		}
		else
			t = t->next;

	}
}
void studentOld(Address** phead, Address** plast)
{
	int old = 0;
	Address* tmp = *phead;
	old = tmp->year;
	while (tmp)
	{

		if (tmp->year < old)
		{
			old = tmp->year;
		}
		tmp = tmp->next;

	}
	Address* t = *phead;
	while (t)
	{
		if (t->year == old)
		{
			cout << "������� �������=" << t->surname << endl;
		}
		t = t->next;
	}

}
void studentYoung(Address** phead, Address** plast)
{
	int young = 0;
	Address* tmp = *phead;
	young = tmp->year;
	while (tmp)
	{

		if (tmp->year > young)
		{
			young = tmp->year;
		}
		tmp = tmp->next;

	}
	Address* t = *phead;
	while (t)
	{
		if (t->year == young)
		{
			cout << "������� �������=" << t->surname << endl;
		}
		t = t->next;
	}
}
void average(Address** phead, Address** plast)
{
	float average1 = 0, average2 = 0, average3 = 0;
	Address* t = *phead;
	while (t)
	{
		average1 = (t->English + t->math + t->Kyar + t->Yap + t->OAIP) / 5;
		cout << "�������:" << t->surname << " " << "������� ����=" << average1 << endl;
		t = t->next;
		average2 = (t->English + t->math + t->Kyar + t->Yap + t->OAIP) / 5;
		cout << "�������:" << t->surname << " " << "������� ����=" << average2 << endl;
		t = t->next;

	}
	Address* emp = *phead;
	while (emp)
	{
		if (average1 >= average2 && average1 >= average3)
		{
			cout << "Best students:" << emp->surname << endl;
		}
		emp = emp->next;
		if (average2 >= average1 && average2 >= average3)
		{
			cout << "Best students:" << emp->surname << endl;
		}
		emp = emp->next;


	}
}