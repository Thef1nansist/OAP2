#include<iostream>
#include"List.h"
int main()
{
	Address* head = NULL;
	Address* last = NULL;
	setlocale(LC_CTYPE, "Rus");
	int choice;
	char s[80];  int c;
	cout << endl;
	cout << "1. Ввод элемента" << endl;
	cout << "2. Вывод на экран" << endl;
	cout << "3. Поиск" << endl;
	cout << "4. Количсетво элементов" << endl;
	cout << "5. Очищение списка" << endl;
	cout << "6. Выход" << endl;
	cout << endl;
	for (;;)
	{
		cout << "Ваш выбор: ";
		cin >> choice;
		switch (choice)
		{
		case 1:  insert(setElement(), &head, &last);
			break;
		case 2:  outputList(&head, &last);
			break;
		case 3: {	  char fnumber[NAME_SIZE];
			cout << "Введите номер: ";
			cin >> fnumber;
			find(fnumber, &head);
		}
			  break;
		case 4: {

			countList(&head, &last);
		}
			  break;
		case 5: {
			delAll(&head, &last);
		}
			  break;
		case 6:  exit(0);
		default: exit(1);
		}
	}
	return 0;
}

