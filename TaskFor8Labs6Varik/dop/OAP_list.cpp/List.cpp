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
		cerr << "Ошибка выделения памяти памяти";
		return NULL;
	}
	cout << "Введите фамилию: ";
	cin >> temp->surname;
	cout << "Введите имя: ";
	cin >> temp->name;
	cout << "Введите отчество: ";
	cin >> temp->parentname;
	cout << "Введите тип счета: ";
	cin >> temp->type;
	cout << "Введите номер счета: ";
	cin >> temp->number;
	cout << "Введите сумму на счете: ";
	cin >> temp->sum;
	cout << "Введите дату последнего изменения: ";
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
		cout << "Список пуст!" << endl;
	}
	while (t)
	{
		cout << "Фамилия:" << t->surname << endl;
		cout << "Имя:" << t->name << endl;
		cout << "Отчество:" << t->parentname << endl;
		cout << "Тип счета:" << t->type << endl;
		cout << "Номер счета:" << t->number << endl;
		cout << "Сумма на счете:" << t->sum << endl;
		cout << "Дата последнего измененеия:" << t->date << endl;
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
		cerr << "Имя не найдено" << endl;
	else
		cout << "Фамилия:" << t->surname << endl;
	cout << "Имя:" << t->name << endl;
	cout << "Отчество:" << t->parentname << endl;
	cout << "Тип счета:" << t->type << endl;
	cout << "Номер счета:" << t->number << endl;
	cout << "Сумма на счете:" << t->sum << endl;
	cout << "Дата последнего измененеия:" << t->date << endl;
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
	cout << "Количество элементов=" << i << endl;
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
	cout << "Список очищен!" << endl;
}