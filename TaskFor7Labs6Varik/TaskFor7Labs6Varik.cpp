#include <windows.h>
#include <iostream>
#include <conio.h>
#include <tchar.h>
#include <clocale>

using namespace std;


struct Queue
{
    int Data;
    struct Queue* next; 
};

Queue* head; // Указатель на голову очереди
Queue* tail; // Указатель на хвост очереди

int kol = 0; //Количество элементов
int kolNUL = 0;
int max; // Максимальный элемент

void Creation();                    /*Функция, которая создает очередь*/
void Add_last(Queue* temp);         /*Функция, которая добавляет элемент в конец*/
void Head_to_tail();                /*Считывание элемента из "головы" и перенос в "хвост"*/
void show_menu();                   /*Вывод информации для главного меню*/
void menu();                        /*Главное меню*/
void Loading(struct Queue* array);  /*Загрузка данных из очереди в массив*/
void inf();                         /*Информация об элементе*/
void check_kol();                   /*Проверка на пустой список*/


/*Функция, которая создает очередь*/
void Creation() // Создание очереди
{
    head = (Queue*)malloc(sizeof(Queue));
    head->next = NULL;
    tail = head;
    kol = 0;
}


void check_kol()
{
    if (kol == 0)
    {
        cout << "Список пуст!" << endl;
        system("pause");
        menu();
    }
}


void Add_last(Queue* temp)
{
    tail->Data = temp->Data;
    tail->next = (Queue*)malloc(sizeof(Queue));
    tail = tail->next;
    tail->next = NULL;  //обнуление указателя на следующий элемент 
    kol++;
}


void Head_to_tail()
{
    Queue* buff = head;
    tail->Data = buff->Data;
    tail->next = (Queue*)malloc(sizeof(Queue));
    tail = tail->next;
    tail->next = NULL;
    buff = head->next;
    free(head);
    head = buff;
}


void Tablitsa()
{
    for (int i = 0; i < kol; i++)
    {
       if(i ==0)
           max = head->Data;
       if (max < head->Data)
           max = head->Data;
        printf("%d) %d\n", i + 1, head->Data);
        Head_to_tail();
    }
    printf("Максимальный элемент очереди: %d\n", max);
    printf("Размерность очереди: %d\n", kol);
}


void show_menu()
{
    system("cls");
    cout << "1 - Добавить элемент" << endl;
    cout << "2 - Просмотр одного элемента" << endl;
    cout << "3 - Просмотр всех элементов" << endl;
    cout << "4 - Моё задание" << endl;
    cout << "5 - Выход" << endl;
}

/*Загрузка данных из очереди в массив*/
void Loading(struct Queue* array)
{
    for (int i = 0; i < kol; i++) {
        array[i].Data = head->Data;
        Head_to_tail();
    }
}

/*Ввод элементов с клавиатуры*/
void input()
{
    system("cls");
    Queue queue;
    int num;
    cout << "Введите число: ";
    cin >> num;
    queue.Data = num;
    Add_last(&queue);
}

/*Информация об элементе*/
void inf()
{
    int Num;
    system("cls");
    cout << "Введите номер элемента: ";
    cin >> Num;
    Num = Num - 1;
    Queue* array = new Queue[kol];
    Loading(array);
    cout << "Число: " << array[Num].Data << endl;
}

void My_Task() {
    system("cls");
    Tablitsa();
    for (int i = 0; i < kol; i++) {
        if (head->Data != 0) {
            printf("%d) %d\n", i + 1, head->Data);
            Head_to_tail();
            kolNUL++;
        }
        else
            break;
    }
    printf("\nРазмер оставшейся очереди равен: %d\n", (kol - kolNUL));

}


void menu()
{
    char ch;
    show_menu();
    while (1)
    {
        ch = _getch();
        if (ch == 49)
        {
            system("cls");
            input();
            system("pause");
            menu();
        }
        if (ch == 50)
        {
            system("cls");
            check_kol();
            inf();
            system("pause");
            menu();
        }
        if (ch == 51)
        {
            system("cls");
            check_kol();
            Tablitsa();
            system("pause");
            menu();
        }
        if (ch == 52)
        {
            system("cls");
            check_kol();
            My_Task();
            system("pause");
            menu();
        }
        if (ch == 53)
        {
            exit(0);
        }
    }
}

int main()
{
    setlocale(LC_ALL, "rus");
    Creation();
    menu();
    return 0;
}