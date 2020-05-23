#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#define MAX 100

using namespace std;

struct Stack
{
	char* st;  // этот параметр нужен для 1 допа, чтобы можно было в элемент односвязного списка засунуть типа строку
	int data;             //информационный элемент
	Stack* head;		 //вершина стека 
	Stack* next;		 //указатель на следующий элемент
};

void show(Stack* myStk);           //прототип
int  pop(Stack* myStk);           //прототип
void push(int x, Stack* myStk);  //прототип


void readstringlengths(Stack* myStk);
void findmaxlength(Stack* myStk);

