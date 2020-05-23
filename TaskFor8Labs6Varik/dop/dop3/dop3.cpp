
#include <iostream>
#include <conio.h>
using namespace std;

struct  Node
{
    int x;
    Node* Next;
    Node* Prev;
};

struct List
{
    Node* Head = NULL, * Tail = NULL;
    int size = 0;
    void Add(int x);
    bool del(int k);
    void Show(int size);
    int Count();
};



int List::Count()
{
    return size;
}

void List::Add(int x)
{
    size++;
    Node* temp = new Node;
    temp->Next = Head;
    temp->x = x;

    if (Head != NULL)
    {
        Tail->Next = temp;
        Tail = temp;
    }
    else Head = Tail = temp;
}

bool List::del(int k)
{
    if (Head == NULL) {
        cout << "Список пуст" << endl;
        return false;
    }
    else
        Node* temp = new Node;
    Node* temp = Tail;
    while (Head != Tail)
    {
        for (int i = 1; i < k; i++)
        {
            temp = temp->Next;
            Node* buf = temp->Next;
            cout << buf->x << " ";
            if (buf == Head)
            {
                Head = buf->Next;
            }
            if (buf == Tail)
            {
                Tail = temp;
            }
            temp->Next = buf->Next;
            delete buf;
        }
    }
    return true;
}

void List::Show(int temp)
{
    Node* tempHead = Head;

    temp = size;
    while (temp != 0)
    {
        cout << tempHead->x << " ";
        tempHead = tempHead->Next;
        temp--;
    }
}
void main()
{
    setlocale(LC_ALL, "Russian");
    int n, k;
    List lst;
    cout << "Введите кол-во элементов в списке" << endl;
    cin >> n;
    for (int i = 1; i < n + 1; i++)
    {
        lst.Add(i);
    }
    cout << "Список:" << endl;
    lst.Show(lst.Count());
    cout << endl;
    cout << "Введите k:" << endl;
    cin >> k;
    cout << endl;
    cout << "Порядок удаления:";
    lst.del(k);
}