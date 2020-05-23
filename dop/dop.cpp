#include<iostream>
#include<string>
#include<vector>

using namespace std;

//struct Database
//{
// int number;
// string name;
// int tarif;
// struct Database* left;
// struct Database* right;
//};
//
//Database* root = NULL;
//
//void pushAbonent(Database** t, int Number, int Tarif, string Name);
//void printAbonent(Database* t);
//void searchAbonent(Database* t, int Number);
//void mostPopularTarif(Database* t);
//
//
//int AmountOfFirst = 0, AmountOfSecond = 0, AmountOfThird = 0, counter = 0;
//int main()
//{
// int choice = 0;
// setlocale(LC_ALL, "rus");
// do
// {
// cout << "1 - добавление нового элемента\n";
// cout << "2 - вывод базы даных\n";
// cout << "3 - поиск владельца по номеру телефона\n";
// cout << "4 - вывод наиболее востребованного тарифа\n";
// cout << "0 - выход\n";
// cout << "\nНомер операции > "; cin >> choice;
//
// switch (choice) {
// case 1: {
// int Amount, Number, Tarif;
// string Name;
// cout << "\nВведите Номер Клиента:\n";
// cin >> Number;
// cout << "\nВведите Имя Клиента:\n";
// cin.ignore();
// getline(cin, Name);
// cout <<"\nВыберите Тариф:\n1. Первый\n2. Второй\n3. Третий\n";
// cin >> Tarif;
// pushAbonent(&root, Number, Tarif, Name);
// cout << "\nДобавлен успешно!\n\n";
// break;
// }
// case 2: {
// cout << "\nДерево Клиентов\n";
// printAbonent(root);
// break;
// }
// case 3: {
// int Number;
// cout << "\nВведите Номер Клиента\n";
// cin >> Number;
// searchAbonent(root, Number);
// break;
// }
// case 4: {
// int max;
// mostPopularTarif(root);
// if (AmountOfFirst >= AmountOfSecond >= AmountOfThird)
// max = AmountOfFirst;
// else if (AmountOfFirst < AmountOfSecond > AmountOfThird)
// max = AmountOfSecond;
// else max = AmountOfThird;
// cout << "\nСамый популярный Тариф:\t";
// if (max == AmountOfFirst)
// cout << "Первый\n";
// else if (max == AmountOfSecond)
// cout << "Второй\n";
// else cout << "Третий\n";
// AmountOfFirst = 0;
// AmountOfSecond = 0;
// AmountOfThird = 0;
// break;
// }
// case 0: break;
// default: {
// cout << "\nНеверный Выбор\n";
// break;
// }
// }
// } while (choice != 0);
//}
//
//void pushAbonent(Database** t, int Number, int Tarif, string Name) {
// if ((*t) == NULL) {
// (*t) = new Database();
// (*t)->name = Name;
// (*t)->number = Number;
// (*t)->tarif = Tarif;
// return;
// }
// if (Number > (*t)->number)
// pushAbonent(&(*t)->left, Number, Tarif, Name);
// else
// pushAbonent(&(*t)->right, Number, Tarif, Name);
//}
//
//void printAbonent(Database* t) {
// if (t) {
// cout << "\nИмя:\t" << t->name;
// cout << "\nНомер:\t" << t->number;
// cout << "\nТариф:\t";
// if (t->tarif == 1)
// cout << "Первый\n";
// else if (t->tarif == 2)
// cout << "Второй\n";
// else cout << "Третий\n";
// printAbonent(t->left);
// printAbonent(t->right);
// }
//}
//
//void searchAbonent(Database* t, int Number) {
// if (t) {
// if (t->number == Number) {
// cout << "\nИмя:\t" << t->name;
// cout << "\nНомер:\t" <<t->number;
// cout << "\nТариф:\t";
// if (t->tarif == 1)
// cout << "Первый\n";
// else if (t->tarif == 2)
// cout << "Второй\n";
// else cout << "Третий\n";
// return;
// }
// searchAbonent(t->left, Number);
// searchAbonent(t->right, Number);
// }
//}
//
//void mostPopularTarif(Database* t) {
// if (t) {
// if (t->tarif == 1)
// AmountOfFirst++;
// if (t->tarif == 2)
// AmountOfSecond++;
// if (t->tarif == 3)
// AmountOfThird++;
// mostPopularTarif(t->left);
// mostPopularTarif(t->right);
// }
//}

//доп 2

struct El
{
    int data;
    El* left;
    El* right;
};

El* root = NULL;

El* CreateEl(int data)
{
    El* interm = new El[sizeof(El)];
    interm->data = data;
    interm->left = interm->right = NULL;
    return interm;
}

void printT(El* p, int level)
{
    if (p)
    {
        printT(p->left, level + 1);
        for (int i = 0; i < level; i++)
            cout << " ";
        cout << p->data << endl;
        printT(p->right, level + 1);
    }
}

El* f(El* rt, int n, int count)
{
    static int loop = 0, data = 0;
    loop++; data++;

    if (loop <= n)
    {
        if (root == NULL && count == 0)
        {
            root = CreateEl(data);
            ++count;
            f(root, n, count);
            return root;
        }
        else if (count == 1)
        {
            rt->left = CreateEl(data);
            ++count;
            f(rt, n, count);
        }
        else if (count == 2)
        {
            --count;
            rt->right = CreateEl(data);
            f(rt->right, n, count);
        }
    }
}

int main()
{
    setlocale(LC_ALL, "rus");
    int n = 0;
    cout << "Введите число N (количество вершин) > "; cin>> n;
    root = f(root, n, 0);
    printT(root, 0);
}