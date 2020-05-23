#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#define MAX 100

using namespace std;

struct Stack
{
	char* st;  // ���� �������� ����� ��� 1 ����, ����� ����� ���� � ������� ������������ ������ �������� ���� ������
	int data;             //�������������� �������
	Stack* head;		 //������� ����� 
	Stack* next;		 //��������� �� ��������� �������
};

void show(Stack* myStk);           //��������
int  pop(Stack* myStk);           //��������
void push(int x, Stack* myStk);  //��������


void readstringlengths(Stack* myStk);
void findmaxlength(Stack* myStk);

