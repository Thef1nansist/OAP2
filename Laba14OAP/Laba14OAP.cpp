#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#define str_len 50000
using namespace std;

void heapify(int A[], int pos, int n)
{
	int t, tm;
	while (2 * pos + 1 < n)
	{
		t = 2 * pos + 1;
		if (2 * pos + 2 < n && A[2 * pos + 2] >= A[t])
			t = 2 * pos + 2;
		if (A[pos] < A[t])
		{
			tm = A[pos];
			A[pos] = A[t];
			A[t] = tm;
			pos = t;
		}
		else break;
	}
}
void piramSort(int A[], int n)
{
	for (int i = n - 1; i >= 0; i--)
		heapify(A, i, n);
	while (n > 0)
	{
		int tm = A[0];
		A[0] = A[n - 1];
		A[n - 1] = tm;
		n--;
		heapify(A, 0, n);
	}
}

void  PastSort(int B[], int size) {
	int i, j, temp;
	for (i = 0; i < size; i++) {
		for (int j = i; j > 0; j--)
		{
			if (B[j - 1] < B[j]) {
				temp = B[j];
				B[j] = B[j - 1];
				B[j - 1] = temp;
			}
		}
	}
}

void quicksort(int* mas, int first, int last)
{
	int mid, count;
	int f = first, l = last;
	mid = mas[(f + l) / 2]; //вычисление опорного элемента
	do
	{
		while (mas[f] < mid) f++;
		while (mas[l] > mid) l--;
		if (f <= l) //перестановка элементов
		{
			count = mas[f];
			mas[f] = mas[l];
			mas[l] = count;
			f++;
			l--;
		}
	} while (f < l);
	if (first < l) quicksort(mas, first, l);
	if (f < last) quicksort(mas, f, last);

	
}

void var61() {
	int A[str_len], count;
	for (int i = 0; i < str_len; i++) {
		A[i] = rand() % 1000;
	}
	double start = clock();
	quicksort(A, 0, str_len - 1);
	double end = clock();
	double time = (end - start) / CLOCKS_PER_SEC;
	cout << "Время на сортировку " << time;
	cout << endl;
}
void var62() {
	int A[str_len], count;
	for (int i = 0; i < str_len; i++) {
		A[i] = rand() % 1000;
	}
	double start = clock();
	heapify(A, 0, str_len - 1);
	piramSort(A, str_len - 1);
	double end = clock();
	double time = (end - start) / CLOCKS_PER_SEC;
	cout << "Время на сортировку " << time;
	cout << endl;
}
void var63() {
	int A[str_len], count;
	for (int i = 0; i < str_len; i++) {
		A[i] = rand() % 1000;
	}
	double start = clock();
	PastSort(A, str_len);
	double end = clock();
	double time = (end - start) / CLOCKS_PER_SEC;
	cout << "Время на сортировку " << time;
	cout << endl;
}

int main()
{
    setlocale(LC_ALL, "rus");
	while (1) {
		cout << "1. Хоара, 2 пирамидальная сортировка, 3 Сортировка методом простой вставки" << endl;
		int k;
		cin >> k;
		switch (k)
		{
		case 1: var61();
			system("pause");
			system("cls");
			break;
		case 2: var62();
			system("pause");
			system("cls");
			break;
		case 3: var63();
			system("pause");
			system("cls");
			break;
		default: cout << "no" << endl;
			break;
		}
	}
}	
