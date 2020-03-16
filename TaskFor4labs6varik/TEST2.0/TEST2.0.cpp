#include <iostream>
#include <fstream>
#include<clocale>

#define str_len 256 
#define size 100 

//using namespace std;
using std::cout;
using std::cin;
using std::endl;

void enter_new();
void out();
void del();
void search();


struct Auto
{
	char sername[str_len];
	char color[str_len];
	char type[str_len];
	char owner[str_len];
	int number;
	int lastyear;
	unsigned year : 8;

};
enum mark
{
	Audi, BMV, Mersedes, Nisan, Toyota, Honda, Mazda, Ford

}mark;

unsigned int l;
Auto b;
Auto all;
struct Auto current[size];
int current_size = 0; int choice;
float marks[8];


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
		printf("Введите марку афтомобиля: ");
		cin >> current[current_size].sername;
		printf("Введите цвет афтомобиля: ");
		cin >> current[current_size].color;
		printf("Введите заводской номер афтомобиля: ");
		cin >> current[current_size].number;
		printf("Введите дату выпуска афтомобиля: ");
		cin >> l;
		printf("Введите тип кузова афтомобиля: ");
		cin >> current[current_size].type;
		printf("Введите дату последнего техосмотра афтомобиля: ");
		cin >> current[current_size].lastyear;
		printf("Введите последнего владельца афтомобиля: ");
		cin >> current[current_size].owner;
		current_size++;
		b.year = l;

	}
	else
		cout << "Введено максимальное кол-во строк";
	cout << "Что дальше?" << endl;
	cin >> choice;
}

void out() {
	char Choice[50];
	printf("Введите марку авто: ");
	cin >> Choice;
	for (int i = 0; i < current_size; i++) {

		if (strcmp(Choice, current[i].sername) == 0)
			printf("\n\t\t........Информация........\n\t\tМарка автомобиля: %s\n\t\tцвет афтомобиля: %s\n\t\tзаводской номер афтомобиля: %d\n\t\tдата выпуска: %u\n\t\tтип кузова: %s\n\t\tдата последнего техосмотра: %d\n\t\tпоследний владелец: %s\n\t\t......................\n\n\n", current[i].sername, current[i].color, current[i].number, l, current[i].type, current[i].lastyear, current[i].owner);

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
	cout << "Марка автомобиля:" << "\n";
	cin >> sername;
	for (int z = 0; z < current_size; z++)
	{
		if (strcmp(sername, current[z].sername) == 0) {
			cout << "Марка :";
			cout << current[z].sername << endl;
			cout << "Цвет:";
			cout << current[z].color << endl;
			cout << "Заводской номер:";
			cout << current[z].number << endl;
			cout << "Дата выпуска: " << endl;
			cout << l << endl;
			cout << "Тип кузова:";
			cout << current[z].type << endl;
			cout << "Дата последнего техосмотра: " << endl;
			cout << current[z].lastyear << endl;
			cout << "Последний владелец: ";
			cout << current[z].owner << endl;
		}
	}
	cout << "Что дальше?" << endl;
	cin >> choice;

}