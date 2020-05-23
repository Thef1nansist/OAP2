#include "Header.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	int choice;
	char s[50];
	Stack* myStk = new Stack; //выделение памяти для стека
	myStk->head = NULL;       //инициализация первого элемента	
	cout << "Выберите команду:" << endl;
	cout << "1 - Добавление элемента в стек" << endl;
	cout << "2 - Извлечение элемента из стека" << endl;
	cout << "3 - Вывод стека" << endl;
	cout << "4 - (Первый доп 1 шаг) Добавление строкового элемента в стек" << endl; //часть 1 допа
	cout << "5 - (Первй доп 2 шаг) Переписывание введённой строки" << endl; // вторая часть 1 допа

	cout << "6 - Выход" << endl;
	for (;;)
	{
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Введите элемент: " << endl;
			cin >> choice;
			push(choice, myStk);
			break;
		case 2:
			choice = pop(myStk);
			if (choice != -1)
				cout << "Извлеченный элемент: " << choice << endl;
			break;
		case 3:
			cout << "Весь стек: " << endl;
			show(myStk);
			break;
		case 4:
			cout << "Введите строку: ";
			cin >> s;
			pushstr(s, myStk);
			break;
		case 5:
			printstring(myStk);
			break;

		case 6:
			exit(1);
		}
	}
	return 0;
}