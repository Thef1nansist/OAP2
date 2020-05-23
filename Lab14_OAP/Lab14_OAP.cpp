#include <iostream>
#include <cstdlib>
#define str_len 20
using namespace std;


void sortShella(int B[], int size) {
	int d = size;
	d = d / 2;
	while (d > 0)
	{
		for (int i = 0; i < size - d; i++)
		{
			int j = i;
			while (j >= 0 && B[j] > B[j + d])
			{
				int count = B[j];
				B[j] = B[j + d];
				B[j + d] = count;
				j--;
			}
		}
		d = d / 2;
	}
	cout << "Сортировка методом Шелла: ";
	for (int i = 0; i < size; i++) cout << B[i] << " "; //вывод массива
}
void sortTheChoice(int B[], int size) {
	int k, i, j, temp;
	for (i = 0; i < size; i++) {

		for (j = i + 1; j < size; j++) {
			if (B[i] > B[j]) {
				temp = B[i];
				B[i] = B[j];
				B[j] = temp;
			}
		}
	}
	cout << "Сортировка методом выбора: ";
	for (int i = 0; i < size; i++) cout << B[i] << " ";
}
void variant6() {
	int A[str_len], B[str_len], size = 0;
	cout << "Начальный массив: ";
	for (int i = 0; i < str_len; i++) {
		A[i] = rand() % 100;
		if (A[i] % 2 == 0) {
			B[size] = A[i];
			size++;
		}
		cout << A[i] << " ";
	}
	cout << endl;

	 sortShella(B, size);
	cout << endl;
	sortTheChoice(B, size);

	cout << endl;

}


void BubbleSort(int B[], int size) {
	int i, j, k, temp;
	for (i = 1; i < size; i++) {
		for (j = 0; j < size - i; j++) {
			if (B[j] < B[j + 1]) {
				temp = B[j];
				B[j] = B[j + 1];
				B[j + 1] = temp;
			}
		}
	}
	cout << "Сортировка методом пузырька: ";
	for (int i = 0; i < size; i++) cout << B[i] << " ";
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
	cout << "Сортировка методом пузырька: ";
	for (int i = 0; i < size; i++) cout << B[i] << " ";
}
void variant1() {
	int A[str_len], B[str_len], size = 0;
	cout << "Начальный массив: ";
	for (int i = 0; i < str_len; i++) {
		A[i] = rand() % 100;
		if (i % 2 == 0) {
			B[size] = A[i];
			size++;
		}
		cout << A[i] << " ";
	}
	cout << endl;
	BubbleSort(B, size);
	cout << endl;
	PastSort(B, size);
	cout << endl;
}

void ShekSort(int B[], int size) {
	int left = 1;
	int right = size - 1;
	while (left <= right) {
		for (int i = right; i >= left; i--) {
			if (B[i - 1] > B[i]) {
				int temp = B[i];
				B[i] = B[i - 1];
				B[i - 1] = temp;
			}

		}
		left++;
		for (int i = left; i <= right; i++) {
			if (B[i - 1] > B[i]) {
				int temp = B[i];
				B[i] = B[i - 1];
				B[i - 1] = temp;
			}
		}
		right--;
	}
	cout << "Сортировка методом шейкера: ";
	for (int i = 0; i < size; i++) cout << B[i] << " ";
}
void BubbleSortFor9(int B[], int size) {
	int i, j, temp;
	for (i = 0; i < size; i++) {
		for (j = i; j > 0; j--) {
			if (B[j] < B[j - 1]) {
				temp = B[j];
				B[j] = B[j - 1];
				B[j - 1] = temp;
			}
		}
	}
	cout << "Сортировка методом пузырька: ";
	for (int i = 0; i < size; i++) cout << B[i] << " ";
}
void variant9() {
	int A[str_len], B[str_len], size = 0;
	cout << "Начальный массив: ";
	for (int i = 0; i < str_len; i++) {
		A[i] = rand() % 100;
		cout << A[i] << " ";
	}
	cout << endl;
	cout << "Отсортированный массив: ";
	for (int i = 0; i < str_len; i++) {
		if (((i) % 2 != 0) && (A[i + 1] % 2 != 0)) {
			B[size] = A[i];
			cout << B[size] << " ";
			size++;
		}
	}
	cout << endl;
	BubbleSortFor9(B, size);
	cout << endl;
	ShekSort(B, size);
	cout << endl;
}

void SotrCoiceFor12(int B[], int size) {
	int k, i, j, temp;
	for (i = 0; i < size; i++) {

		for (j = i + 1; j < size; j++) {
			if (B[i] > B[j]) {
				temp = B[i];
				B[i] = B[j];
				B[j] = temp;
			}
		}
	}
	cout << "Сортировка методом выбора: ";
	for (int i = 0; i < size; i++) cout << B[i] << " ";
}
void BubbleSortFor12(int B[], int size){
	int i, j, k, temp;
	for (i = 1; i < size; i++) {
		for (j = 0; j < size - i; j++) {
			if (B[j] > B[j + 1]) {
				temp = B[j];
				B[j] = B[j + 1];
				B[j + 1] = temp;
			}
		}
	}
	cout << "Сортировка методом пузырька: ";
	for (int i = 0; i < size; i++) cout << B[i] << " ";

}
void variant12() {
	int A[str_len], B[str_len], size = 0;
	cout << "Начальный массив: ";
	for (int i = 0; i < str_len; i++) {
		A[i] = rand() % 1000;
		if (i % 2 == 0) {
			B[size] = A[i];
			size++;
		}
		cout << A[i] << " ";
	}
	cout << endl;
	BubbleSortFor12(B, size);
	cout << endl;
	SotrCoiceFor12(B, size);
	cout << endl;

}


int main()
{
	setlocale(LC_ALL, "rus");
	while (true) {
		int switch_on;
		cout << "Выберите действие \n1.Variant 6\n2.Variant 1\n3.Variant 9\n4.Variant 12\n5.Exit" << endl << "Выбор: ";
		cin >> switch_on;
		switch (switch_on)
		{
		case 1: variant6();
			system("pause");
			system("cls");
			break;
		case 2: variant1();
			system("pause");
			system("cls");
			break;
		case 3: variant9();
			system("pause");
			system("cls");
			break;
		case 4: variant12();
			system("pause");
			system("cls");
			break;
		case 5: return 0;
			break;
		default:
			break;
		}

	}

}

