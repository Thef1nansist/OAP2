#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;

struct node {
    int info;
    node* l, * r;
};

node* tree1 = NULL;
node* tree2 = NULL;

void push(int a, node** t) {
    if ((*t) == NULL) {
        (*t) = new node;
        (*t)->info = a;
        (*t)->l = (*t)->r = NULL;
        return;
    }

    if (a > (*t)->info)
        push(a, &(*t)->r);
    else
        push(a, &(*t)->l);
}

void pushFromFile(node** t, int a) {
    if ((*t) == NULL) {
        (*t) = new node;
        (*t)->info = a;
        (*t)->l = (*t)->r = NULL;
        return;
    }
    if (a > (*t)->info)
        pushFromFile(&(*t)->r, a);
    else
        pushFromFile(&(*t)->l, a);
}

void print(node* t) {
    if (t == NULL)
        return;
    cout << t->info << endl;
    print(t->l);
    print(t->r);
}

void printToFile(node* t, ofstream& file) {
    if (t == NULL)
        return;
    file << t->info << '\n';
    printToFile(t->l, file);
    printToFile(t->r, file);
}

void numberSearch(node* t, int number) {
    if (number > t->info) {
        cout << t->info << endl;
        numberSearch(t->r, number);
    }
    if (number < t->info) {
        cout << t->info << endl;
        numberSearch(t->l, number);
    }
    if (number == t->info) {
        cout << '|' << t->info << '|' << endl;
    }
}

int leftRoots(node* t) {
    static int sum = 0;
    if (t->l != NULL) {
        leftRoots(t->l);
        sum++;
    }
    if (t->r != NULL)
        leftRoots(t->r);
    return sum;
}

int arsum(const node* tr, int& n)
{
    int sum = 0;
    if (tr != NULL) {
        sum += tr->info + arsum(tr->l, n) + arsum(tr->r, n);
        ++n;
    }
    return sum;
}

int main() {
    setlocale(0, "");
    while (true) {
        int choice;
    Menu:
        cout << "\nВыберите Вариант:\n1.6 Вариант- Мой Варик\n2. 4 Вариант\n3. 5 Вариант\n4.14 Вариант \n5. Завершить\n";
        cin >> choice;
        switch (choice) {
        case 4: {
            int Amount, newNumber, Yes;
            cout << "Введите количество элементов:\t";
            cin >> Amount;
            cout << "\nВводите Числа:\n";
            for (int i = 0; i < Amount; ++i) {
                cin >> newNumber;
                push(newNumber, &tree1);
            }
            cout << "\nДерево:\n";
            print(tree1);
            cout << "\nВывести Выполнение Условия?\n";
            cin >> Yes;
            if (Yes) {
                cout << "\nСреднее арифметическое:\n";
                cout << arsum(tree1, Amount);
                cout << endl;
            }
            goto Menu;
        }
        case 2: {
            int numberChoice;
            cout << "\nВведите Число Из Дерева \n";
            cin >> numberChoice;
            cout << "\nКратчайший Путь\n";
            numberSearch(tree1, numberChoice);
            goto Menu;
        }
        case 3: {
            int Amount = leftRoots(tree1);
            cout << "\nКол-во Корней Являющихся Левыми Дочерними Корнями:\t" << Amount << endl;
            goto Menu;
        }
        case 1: {
            ifstream file("In.txt");
            ofstream fileOut("Out.txt");
            string Temp;
            int newNumber;
            if (!file.is_open()) {
                cout << "\nОшибка Открытия In.txt\n";
                goto Menu;
            }
            if (!fileOut.is_open()) {
                cout << "\nОшибка Отрытия Out.txt\n";
                goto Menu;
            }
            while (!file.eof()) {
                file >> newNumber;
                pushFromFile(&tree2, newNumber);
            }
            printToFile(tree2, fileOut);
            file.close();
            fileOut.close();
            cout << "\nУспешно\n";
            print(tree1);
            system("Out.txt");
            goto Menu;
        }
        case 5: return 0;
        default: {
            cout << "\nНеверный Выбор\n";
            goto Menu;
        }
        }
    }
}