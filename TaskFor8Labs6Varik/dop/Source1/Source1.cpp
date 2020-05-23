#include<iostream>
#include"List.h"
#include<locale>
int main()
{
	Address* head = NULL;
	Address* last = NULL;
	setlocale(LC_CTYPE, "Rus");
	int choice;
	char s[80];  int c;
	cout << endl;
	cout << "1. Ввод элемента" << endl;
	cout << "2. Старший студент" << endl;
	cout << "3. Младший студент" << endl;
	cout << "4. Лучший ученик" << endl;
	cout << "5. вывод списка" << endl;
	cout << "6. 1 курс" << endl;
	cout << "7. 2 курс" << endl;
	cout << "8. 3 курс" << endl;
	cout << "9. 4 курс" << endl;
	cout << "10. Выход" << endl;
	cout << endl;
	for (;;)
	{
		cout << "Ваш выбор: ";
		cin >> choice;
		switch (choice)
		{
		case 1:  insert(setElement(), &head, &last);
			break;
		case 2:  studentOld(&head, &last);
			break;
		case 3: 	studentYoung(&head, &last);
			break;
		case 4: average(&head, &last);
			break;
		case 5: outputList(&head, &last);
			break;
		case 6: outputFirstCourse(&head, &last);
			break;
		case 7:
			outputSecondCourse(&head, &last);
			break;
		case 8:
			outputThirdCourse(&head, &last);
			break;
		case 9:
			outputFourthCourse(&head, &last);
			break;
		case 10:  exit(0);
		default: exit(1);
		}
	}
	return 0;
}