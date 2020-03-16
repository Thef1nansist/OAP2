#include <iostream>

#define str_len 30                               
#define size 30

using namespace std;

void output();
void input(int current_size);
void enter_new();
void del();
void change();
void out();

typedef struct Storage {
	char name[str_len];
	int price;
	int number;
	int procent;
	int wprice;
}STUD;


struct Storage list_of_tovar[size];
struct Storage bad;
FILE* f; errno_t err;


int current_size = 0; int choice;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	while (1) {
		cout << "Введите:" << endl;
		cout << "1-для добавления записи" << endl;
		cout << "2-для вывода записи(ей)" << endl;
		cout << "3-для изменения записи" << endl;
		cout << "4-удаление записи" << endl;
		cout << "6-Ввод данных с клавиатуры и запись в файл" << endl;
		cout << "7-Вывод данных из файла" << endl;
		cout << "5-для выхода" << endl;
		printf("Что душе угодно?: ");
		int k;
		cin >> k;
		switch (k) {
		case 1:
			enter_new();
			break;
		case 2:
			out();
			break;
		case 3:
			change();
			break;
		case 4:
			del();
			break;
		case 6:
			input(1);
			break;
		case 7:
			output();
			break;
		case 5:
			return 0;
		default:
			printf("Введите номер заново");
			break;
		}
	}
}
void enter_new() {
	printf("\t\t\t\tВвод информации\n");
	if (current_size < size) {

		printf("Введите наименование товара: \n");
		cin >> list_of_tovar[current_size].name;

		printf("Введите цену товара: \n");
		cin >> list_of_tovar[current_size].price;

		printf("Введите количество товара: \n");
		cin >> list_of_tovar[current_size].number;

		printf("Введите надбавку на товар: \n");
		cin >> list_of_tovar[current_size].procent;
		int test = list_of_tovar[current_size].procent;

		list_of_tovar[current_size].wprice = (int)((float)(list_of_tovar[current_size].price * (float)(list_of_tovar[current_size].procent*0.01)) + list_of_tovar[current_size].price);
		current_size++;

		
	}
	else {
		printf("\n\n\t\tСписок товаров уже заполнен!\t\t\n\n");
	}
}

void del() {
	char choicest[50];
	printf("\n\n\t\tВведите наименование товара:\n ");
	cin >> choicest;

	if (strcmp(choicest, "ALL") != 0) {
		for (int i = 0; i < current_size; i++)
			if (strcmp(choicest, list_of_tovar[i].name) == 0) {
				for (int j = i; j < current_size; j++)
					list_of_tovar[j] = list_of_tovar[j + 1];
				current_size--;
			}
			else {
				for (int i = 0; i < current_size; i++) {
					list_of_tovar[i] = bad;
				}
				current_size = 0;
			}
	}
}
void change() {
	char choice[50];
	int NumChoice,cheker=1;
	printf("Введите название товара: ");
	cin >> choice;
	for (int i = 0; i < size; i++) {
		if (strcmp(choice, list_of_tovar[i].name) == 0) {
			while (cheker) {
				printf("Выберите действие: \n1.Изменить наименование товара\n2.Изменить количество тавара\n3.Изменить стоимость товара\n4.Изменить надбавку на товар\n5.Все изменения внесены\n ");
				cin >> NumChoice;
				switch (NumChoice) {
				case 1: {
					printf("\nВведите новое наименование товара: ");
					cin >> list_of_tovar[i].name; }
					  break;
				case 2: {
					printf("\nВведите новое количество товара: ");
					cin >> list_of_tovar[i].number; }
					  break;
				case 3: {
					printf("\nВведите новую стоимость товара: ");
					cin >> list_of_tovar[i].price; }
					  break;
				case 4: {
					printf("\nВведите ноeую надбавку за товар: ");
					cin >> list_of_tovar[i].procent; }
					  list_of_tovar[i].wprice = (int)((float)(list_of_tovar[i].price * (float)(list_of_tovar[i].procent * 0.01)) + list_of_tovar[i].price);
					  break;
				case 5:
					cheker = 0;
				default:
					break;
				}
			}

		}
	}
	

}
void out() {
	char Choice[50];
	printf("Введите наименование товара: ");
	cin >> Choice;

	for (int i = 0; i < current_size; i++) {

		if(strcmp(Choice,list_of_tovar[i].name)==0) 
			printf("\n\t\t........Информация........\n\t\tНаименование товара: %s\n\t\tЦена товара: %d\n\t\tЦена товара с надбавкой: %d\n\t\tКоличество товара: %d\n\t\tПроцент торговой надбавки: %d\n\t\t......................\n\n\n", list_of_tovar[i].name, list_of_tovar[i].price, list_of_tovar[i].wprice,list_of_tovar[i].number, list_of_tovar[i].procent);
	}



}

void input(int current_size)
{
	STUD buf = { ' ', ' ' };
	if (!fopen_s(&f, "base.bin", "ab"))
	{
		for (int p = 0; p < current_size; p++)
		{
			cout << "Наименование товара: ";
						cin >> buf.name;
			
						cout << "Цена товара: "; 	
						cin >> buf.price;
			
						printf("Введите количество товара: \n");
						cin >> buf.number;
			
						printf("Введите надбавку на товар: \n");
						cin >> buf.procent;

			fwrite(&buf, sizeof(buf), 1, f);
		}
		fclose(f);
	}
	else {
		cout << "Ошибка открытия файла";
		return;
	}
}

void output() {
	STUD buf;
	if (!fopen_s(&f, "base.bin", "rb"))
	{
		fread(&buf, sizeof(buf), 1, f);
		while (!feof(f))
		{
			printf("\t\t\tИнформация о товаре\n\t\t.........Наименование товара:%s......... \n\t\t.........Количество товара:%d......... \n\t\t.........Цена товара:%d.........\n\t\t.........Процент надбавки: %d.........", buf.name, buf.number, buf.price, buf.procent);
			printf("\n\n");
			fread(&buf, sizeof(buf), 1, f);
		}
		cout << endl;
		fclose(f);                                  /*создаём функцию для вывода информации из файла*/
	}
	else {
		cout << "Ошибка открытия файла";
		return;
	}
		}
