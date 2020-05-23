#pragma once
using namespace std;
const unsigned int NAME_SIZE = 30;
const unsigned int CITY_SIZE = 20;

struct Address
{
	char name[NAME_SIZE];
	char surname[NAME_SIZE];
	char parentname[NAME_SIZE];
	char type[NAME_SIZE];
	char number[NAME_SIZE];
	char sum[NAME_SIZE];
	char date[NAME_SIZE];
	Address* next;
	Address* prev;
};
void insert(Address* e, Address** phead, Address** plast);
Address* setElement();
void outputList(Address** phead, Address** plast);
void find(char name[NAME_SIZE], Address** phead);
void countList(Address** phead, Address** plast);
void delAll(Address** phead, Address** plast);