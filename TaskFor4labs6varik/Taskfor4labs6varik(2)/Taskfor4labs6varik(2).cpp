#include <iostream>
#include <fstream>
#include<clocale>

#define size 100 

//using namespace std;
using std::cout;
using std::cin;
using std::endl;

void enter_new();
void out();
void del();
void search();
union forSpis
{
	char str[20];
	int limb;
};

struct Spis
{
	 forSpis sername;
	 forSpis education;
	 forSpis spec;
	 forSpis podspec;
	 forSpis PositionInCompany;
	 forSpis salary;
	 forSpis Datetransition;

};

Spis b;
Spis all;
struct Spis current[size];
int current_size = 0; int choice;


int main()
{
	setlocale(LC_ALL, "Rus");

	cout << "\t\t\tГЛАВНОЕ МЕНЮ" << endl;
	cout << "\t\t1-для ввода записи" << endl;
	cout << "\t\t2-для вывода записи" << endl;
	cout << "\t\t3-для удаления" << endl;
	cout << "\t\t4-для поиска информации" << endl;
	cout << "\t\t5-для выхода" << endl;
	cout << "\t\tВведите: ";
	cin >> choice;

	do
	{
		switch (choice)
		{
		case 1:  enter_new();	break;
		case 2:  out();  break;
		case 3:  del();  break;
		case 4:  search();	break;
		}
	} while (choice != 5);
}

void enter_new() {

	printf("Ввод информации :\n");

	if (current_size < size) {

		cout << "Строка номер ";
		cout << current_size + 1 << endl;

		printf("Введите Ф.И.О. работника: ");
		cin >> current[current_size].sername.str;

		printf("Введите образование работника: ");
		cin >> current[current_size].education.str;

		printf("Введите специальость работника: ");
		cin >> current[current_size].spec.str;

		printf("Введите подразделение работника: ");
		cin >> current[current_size].podspec.str;

		printf("Введите оклад работника: ");
		cin >> current[current_size].salary.limb;

		printf("Введите должность работника: ");
		cin >> current[current_size].PositionInCompany.str;

		printf("Введите дату поступления на предприятие: ");
		cin >> current[current_size].Datetransition.str;

		current_size++;
	}
	else
	cout << "Введено максимальное кол-во строк";
	cout << "Что дальше?" << endl;
	cin >> choice;
}

void out() {
	char Choice[50];
	printf("Введите ФИО: ");
	cin >> Choice;
	for (int i = 0; i < current_size; i++) {

		if (strcmp(Choice, current[i].sername.str) == 0)
			printf("\n\t\t........Информация........\n\t\tФ.И.О. работника: %s\n\t\tобразование: %s\n\t\tспециальность: %s\n\t\tподразделение: %s\n\t\tоклад: %d\n\t\tдолжность: %s\n\t\tдата поступления: %s\n\t\t......................\n\n\n", current[i].sername.str, current[i].education.str, current[i].spec.str, current[i].podspec.str, current[i].salary.limb, current[i].PositionInCompany.str, current[i].Datetransition.str);

	}
	cout << "Что дальше?" << endl;
	cin >> choice;
}
void del() {
	int d;
	cout << "\nНомер строки, которую надо удалить (для удаления всех строк нажать 99)" << endl;
	cin >> d;
	if (d != 99)
	{
		for (int de1 = (d - 1); de1 < current_size; de1++)
			current[de1] = current[de1 + 1];
		current_size = current_size - 1;
	}
	if (d == 99)
		for (int i = 0; i < size; i++)
			current[i] = all;
	cout << "Что дальше?" << endl;
	cin >> choice;
}
void search() {
	char sername[16];
	cout << "Введите ФИО:" << "\n";
	cin >> sername;
	for (int z = 0; z < current_size; z++)
	{
		if (strcmp(sername, current[z].sername.str) == 0) {
			cout << "ФИО :";
			cout << current[z].sername.str << endl;
			cout << "Образование: ";
			cout << current[z].education.str << endl;
			cout << "Специальность: ";
			cout << current[z].spec.str << endl;
			cout << "Подразделение: " << endl;
			cout << current[current_size].podspec.str << endl;
			cout << "Оклад:";
			cout << current[z].salary.limb<< endl;
			cout << "Должность в компании: " << endl;
			cout << current[z].PositionInCompany.str << endl;
			cout << "Начало работы: ";
			cout << current[z].Datetransition.str << endl;
		}
	}
	cout << "Что дальше?" << endl;
	cin >> choice;

}