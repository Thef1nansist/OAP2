#include <iostream>
#include <fstream>

struct list
{
    int number;
    list* next;
};

using namespace std;

int IsEmpty(list* p);
void enter_new(list*& p, int value);
int del(list*& p, int value);
void search(list* p);
void out(list* p);
void rec(list*& p);
void read(list*& p);
void MyTask(list*& p);

int main()
{
    setlocale(LC_ALL, "Rus");
    int choice;
    list* first = NULL;
    do
    {
        cout << "\t\t\t.....МЕНЮ.....\n";
        cout << "\t\t\t.....1.Добавить элемент.....\n";
        cout << "\t\t\t.....2.Удалить элемент.....\n";
        cout << "\t\t\t.....3.Найти элемент.....\n";
        cout << "\t\t\t.....4.Вывести список.....\n";
        cout << "\t\t\t.....5.Записать в файл.....\n";
        cout << "\t\t\t.....6.Считать из файла.....\n";
        cout << "\t\t\t.....7.Сумма положительных элементов......\n";
        cout << "\t\t\t.....8.Выход.....\n";
        cout << "Введите номер: ";
        cin >> choice;

        switch (choice)
        {
        case 1:  int value;
            cout << "Введите число: ";
            cin >> value; enter_new(first, value);	break;
        case 2:  if (!IsEmpty(first)) {
            cout << "Введите удаляемое число ";
            cin >> value;
            if (del(first, value))
            {
                cout << "Удалено число " << value << endl;
                out(first);
            }
        };  break;
        case 3:  search(first);	break;
        case 4:  out(first);	break;
        case 5:  rec(first);	break;
        case 6:  read(first);	break;
        case 7:  MyTask(first);	break;

        }
    } while (choice != 8);

}
int IsEmpty(list* p) {
    return p == NULL;
}
void enter_new(list*& p, int value) {

    list* newP = new list;
    if (newP != NULL) {
        newP->number = value;
        newP->next = p;
        p = newP;
    }
    else
        cout << "Операция добавления не выполнена" << endl;
}
int del(list*& p, int value) {
    list* previous, * current, * temp;
    if (value == p->number) {
        temp = p;
        delete temp;
        return value;
    }
    else
    {
        previous = p;
        current = p->next;
        while (current != NULL && current->number != value)
        {
            previous = current;
            current = current->next;
        }
        if (current != NULL) {
            temp = current;
            previous->next = current->next;
            free(temp);
            return value;
        }
    }
    return 0;
}
void search(list* p) {
    int current_size, cheker = 0;
    list* tmp;
    tmp = p;
    cout << "\nВведите ваше число: ";
    cin >> current_size;
    while (tmp != NULL) {
        if (current_size == tmp->number) {
            cout << "Искомый элемент есть в списке " << "\n";
            cheker++;
            break;
        }
        else
            tmp = tmp->next;
    }
    if (cheker == 0)
        cout << "Такого элемента нет в списке. \n";
}
void out(list* p) {
    if (p == NULL)
        cout << "Spisok pust" << endl;
    else {
        cout << "Spisok: " << endl;
        while (p != NULL) {
            cout << "-->" << p->number;
            p = p->next;
        }
        cout << "-->NULL" << endl;
    }
}
void rec(list*& p) {
    list* temp = p;
    list buf;
    ofstream frm("mList.dat");
    if (frm.fail())
    {
        cout << "\n Ошибка открытия файла";
        exit(1);
    }
    while (temp)
    {
        buf = *temp;
        frm.write((char*)&buf, sizeof(list));
        temp = temp->next;
    }
    frm.close();
    cout << "Список записан в файл mList.dat\n";


}
void read(list*& p) {
    list buf, * first = nullptr;
    ifstream frm("mList.dat");
    if (frm.fail())
    {
        cout << "\n Ошибка открытия файла";
        exit(1);
    }
    frm.read((char*)&buf, sizeof(list));
    while (!frm.eof())
    {
        enter_new(first, buf.number);
        cout << "-->" << buf.number;
        frm.read((char*)&buf, sizeof(list));
    }
    cout << "-->NULL" << endl;
    frm.close();
    p = first;
    cout << "\nСписок считан из файла mList.dat\n";
}
void MyTask(list*& p) {
    int current = 0;
    int lastsp = -100;
    list* tmp;
    tmp = p;
    while (tmp != NULL) {
        if (tmp->number>0) {
            current = current + tmp->number;
            tmp = tmp->next;
        }
        else
            tmp = tmp->next;
    }
    if (current == 0)
        cout << "Таких элементов нет";
    else
        cout << "Сумма элементов: " << current << endl;
}


