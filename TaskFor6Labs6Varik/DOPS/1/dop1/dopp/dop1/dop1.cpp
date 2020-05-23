#include "Header.h"
using namespace std;

void push(int x, Stack* myStk)
{
	Stack* e = new Stack;
	e->data = x;
	e->next = myStk->head;
	myStk->head = e;
	cout << "Что дальше?" << endl;
}

void pushstr(char* s, Stack* myStk)  //функция из 1 допа, просто добавляющая одну строку в голову стека
{
	Stack* e = new Stack;
	e->st = s;
	e->next = myStk->head;
	myStk->head = e;
	cout << "Что дальше?" << endl;
}

int pop(Stack* myStk)
{
	if (myStk->head == NULL)
	{
		cout << "Стек пуст!" << endl;
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
	cout << "Что дальше?" << endl;
}

void show(Stack* myStk)
{
	Stack* e = myStk->head;
	int a;
	if (e == NULL)
		cout << "Стек пуст!" << endl;
	while (e != NULL)
	{
		a = e->data;
		cout << a << " ";
		e = e->next;
	}
	cout << endl;
	cout << "Что дальше?" << endl;
}


void printstring(Stack* myStk)  //функция 1 допа, переписывающая строку из головы стека так как нужно в задании
{
	string a = myStk->head->st;
	int mid = (a.length() / 2) - 1;
	for (int i = mid; i >= 0; i--)
	{
		cout << a[i];
	}
	for (int i = a.length() - 1; i > mid; i--)
	{
		cout << a[i];
	}
	cout << endl << "Что дальше?" << endl;
}



