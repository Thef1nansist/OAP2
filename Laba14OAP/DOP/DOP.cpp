#include <iostream>
#include <ctime>
#include <vector>
#define maxsize 10000
using namespace std;

int getHoarBorder(vector<int>& A, int sm, int em)
{
	int i = sm - 1, j = em + 1;
	int brd = A[sm];
	int buf;
	while (i < j)
	{
		while (A[--j] < brd);
		while (A[++i] > brd);
		if (i < j)
		{
			buf = A[j];
			A[j] = A[i];
			A[i] = buf;
		};
	}
	return j;
}
vector<int> sortHoar(vector<int>& A, int sm, int em)
{
	if (sm < em)
	{
		int hb = getHoarBorder(A, sm, em);
		sortHoar(A, sm, hb);
		sortHoar(A, hb + 1, em);
	}
	return A;
};
//Пирамида - дерево с произвольными значениями упорядочевается. Больший элемент в вершине и т.д.
void heapify(vector<int>& A, int pos, int n)
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
void piramSort(vector<int>& A, int n)
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

void shakesort(vector<int>& A)
{
	int left = 0, right = A.size() - 1;
	bool flag = true;
	while ((left < right) && flag)
	{
		flag = false;
		for (int i = left; i < right; i++)
		{
			if (A[i] < A[i + 1])
			{
				int tmp = A[i];
				A[i] = A[i + 1];
				A[i + 1] = tmp;
				flag = true;
			}
		}
		right--;
		for (int i = right; i < left; i++)
		{
			if (A[i - 1] < A[i])
			{
				int tmp = A[i];
				A[i] = A[i - 1];
				A[i - 1] = tmp;
				flag = true;
			}
		}
		left++;
	}
}

void bubbleSortup(vector<int>& A, int n)
{
	int i, j, t;
	for (i = 1; i < n; i++)
		for (j = n - 1; j >= i; j--)
			if (A[j - 1] > A[j])
			{
				t = A[j - 1];
				A[j - 1] = A[j];
				A[j] = t;
			}
}
void bubbleSort(vector<int>& A, int in, int n)
{
	int t;
	for (int i = in; i < n; ++i)
	{
		for (int j = 0; j < n - i; j++)
		{
			if (A[j] > A[j + 1])
			{
				t = A[j];
				A[j] = A[j + 1];
				A[j + 1] = t;
			}
		}
	}
}


void dop1() {
	vector<int> A;
	int size;
	cout << "Введите кол-во элементов" << endl;
	cin >> size;
	for (int i = 0; i <= size - 1; i++)
	{
		int num = rand() % 1000 + 1;
		A.push_back(num);
	}
	heapify(A, 0, A.size() - 1);
	piramSort(A, A.size() - 1);

	cout << "Мин эл. массива " << A[0] << endl;
	cout << "Макс эл. массива " << A[A.size() - 1] << "(" << A.size() - 1 << ")" << endl;
}

void dop2() {
	vector<int> A;
	int num, t;
	for (int i = 0; i <= 9; i++)
	{
		int num = rand() % 10 + 1;
		A.push_back(num);
	}
	cout << endl << endl;
	for (int k = 0; k <= 9; k++) {
		cout << A[k] << endl;
	}
	cout << endl << endl;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (A[j] > A[j + 1])
			{
				t = A[j];
				A[j] = A[j + 1];
				A[j + 1] = t;
			}
		}
	}
	for (int i = 6; i < A.size(); i++)
	{
		for (int j = 6; j < A.size() - 1; j++)
		{
			if (A[j] < A[j + 1])
			{
				t = A[j];
				A[j] = A[j + 1];
				A[j + 1] = t;
			}
		}
	}
	for (int k = 0; k <= 9; k++) {
		cout << A[k] << endl;
	}
}

void dop3()
{
	vector<int> A;
	int num;
	int amodup = 0;
	for (int i = 0; i <= 15; i++)
	{
		int num = rand() % 10 + 0;
		num = num - 5;
		A.push_back(num);
	}
	for (int k = 0; k < A.size(); k++) {
		int tmp = A[k];
		for (int j = k + 1; j < A.size(); j++)
			if (A[j] == tmp) {
				A.erase(A.begin() + j);
				amodup++;
			}
	}

	bubbleSortup(A, A.size());

	for (int k = 0; k < A.size(); k++) {
		int tmp = A[k];
		for (int j = k + 1; j < A.size(); j++)
			if (A[j] == tmp) {
				A.erase(A.begin() + j);
				amodup++;
			}
	}

	for (int k = 0; k <= A.size() - 1; k++) {
		cout << A[k] << endl;
	}
}

int main()
{
	setlocale(0, "");
	while (1) {
		cout << "1.dop1, 2.dop2, 3.dop3" << endl;
		int k;
		cin >> k;
		switch (k)
		{
		case 1: dop1();
			system("pause");
			system("cls");
			break;
		case 2: dop2();
			system("pause");
			system("cls");
			break;
		case 3: dop3();
			system("pause");
			system("cls");
			break;
		default: cout << "no" << endl;
			break;
		}
	}
}