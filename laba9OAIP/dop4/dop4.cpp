#include<cmath>
#include<iostream>
int posled(int m, int counter, int r);
int find(int i, int n, int m, int r);
using namespace std;
int posled(int m, int counter, int r)
{
	while (counter != 26)
	{
		cout << m << " ";
		return posled(m + r, counter + 1, r);
	}

}
int find(int i, int m, int n, int r)
{
	while (i != 26)
	{
		if (n == i)
		{
			cout << std::endl;
			cout << "Число на позиции n=" << m << std::endl;
		}
		return find(i + 1, m + r, n, r);
	}
}
int main()
{
	setlocale(LC_CTYPE, "Russian");
	using namespace std;
	int n, m, counter = 0, i = 1, r;
	cout << "Введите начальное значение последовательности:";
	cin >> m;
	cout << endl;
	cout << "Введите число на которое будет изменяться последовательность:";
	cin >> r;
	cout << endl;
	cout << "Введите n:";
	cin >> n;
	cout << endl;
	cout << "Последовательность:";
	posled(m, counter, r);
	find(i, m, n, r);
}