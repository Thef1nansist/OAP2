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



void readstringlengths(Stack* myStk)  //эта функция 2 допа, считывает строки из файла, вычисляет их длину и заполняет односвязный список длинами строк 
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
	show(myStk);  // эта штука выводит на экран все элементы односвязного списка, просто для удобства сунул сюда
}

void findmaxlength(Stack* myStk)  //эта функция перебирает стек с длинами строк как положено, с головы стека, и выводит длину и номер
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
	cout << "Максимальное количество: " << maxlength << endl << "Номер этой строки, считая с конца стека: " << num << endl;
}
