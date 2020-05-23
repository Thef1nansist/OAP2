//2. Создать стек с целочисленным информационным полем.Заполнить его длинами строк, считанных из файла.
//Распечатаьть на экране содержимое стека.Указать номер и длину последней самой короткой строки файла.

#include "Header.h"


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
	cout << "4 - (Второй доп) Чтение длин строк из файла и вывод стека" << endl; //2 доп
	cout << "5 - Выход" << endl;
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
			readstringlengths(myStk); //функция 2 допа, смотри файл с функциями
			findmaxlength(myStk); //еще одна функция 2 допа, смотри файл с функциями
			break;
		case 5:
			exit(1);
		}
	}
	return 0;
}