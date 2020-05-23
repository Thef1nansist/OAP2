#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct List
{
    int number;
    List* Next, * Head;

}; 


void ClearList(List* MyList) {
    while (MyList->Head != NULL) {
        List* temp = MyList->Head->Next;
        delete MyList->Head;
        MyList->Head = temp;
    }
}

void Add(int number,List*&MyList) {

    List* temp = new List;
    temp->number = number;
    temp->Next = MyList->Head;
    MyList->Head = temp;


}
void Show(List* MyList) {
    List* temp = MyList->Head;
    while (temp != NULL) {
        cout << "-->" << temp->number;
        temp = temp->Next;
    }
    cout << "-->NULL" << endl;
}

    void rec(List* MyList) {
        ofstream frm("mList.dat");
        if (frm.fail())
        {
            cout << "\n Ошибка открытия файла";
            exit(1);

        }

        List* current = MyList->Head;
        while (current!=NULL)
        {
            frm << current->number << " ";
            current = current->Next;


        }
        frm.close();
        cout << "Список записан в файл mList.dat\n";


    }
    void read(List * MyList) {
       
        ifstream frm("mList.dat");
        if (!frm.is_open())
        {
            cout << "\n Ошибка открытия файла";
            exit(1);
        }
        string temp;
        while (getline(frm,temp))
        {
            frm >> temp;
            cout << temp << " ";
        }
        frm.close();
       
    }
    void Mytask(List* MyList) {
        int cheker = 0;
        List* current = MyList->Head;
        while (current->Next->Next != NULL) {
            if (current->number == current->Next->Next->number) 
                cheker++;
            current = current->Next;

        }
        if (cheker == 0)
            cout << "Таких элементов нет";
        else
            cout << "Количество элементов у котрых равные соседи: " << cheker  << endl;

    }

int main()
{
    setlocale(LC_ALL, "Rus");
    int choice,i;
    List* MyList = new List;
    MyList->Head = NULL;
    do
    {
        cout << "\t\t\t.....МЕНЮ.....\n";
        cout << "\t\t\t.....1.Добавить элемент.....\n";
        cout << "\t\t\t.....2.Вывести стек.....\n";
        cout << "\t\t\t.....3.Очистить стек.....\n";
        cout << "\t\t\t.....4.Записать в файл.....\n";
        cout << "\t\t\t.....5.Считать из файла.....\n";
        cout << "\t\t\t.....6.Моё задание.....\n";
        cout << "\t\t\t.....7.Выход.....\n";
        cout << "Введите номер: ";
        cin >> choice;
        switch (choice) {
        case 1: printf("Введите элемент: ");
            cin >> i;
            Add(i, MyList);
            break;
        case 2:
            Show(MyList);
            break;
        case 3:ClearList(MyList);
            break;
        case 4:rec(MyList);
            break;
        case 5:read(MyList);
            break;

        case 6:Mytask(MyList);
            break;
        }
    

    } while (choice != 7);
    

    
    
    
    

    
}