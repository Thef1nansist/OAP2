#include <iostream>
#include <algorithm>
using namespace std;
void output(int* m, int n)
{
    for (int i = 0; i < n; ++i)
        cout << m[i] << " ";
    cout << endl;
}
int main()
{
    const int n = 5;
    int mas[n];
    for (int i = 0; i < 5; ++i)
    {
        cout << "Vvedite chislo" << endl;
        cin >> mas[i];
    }
    sort(mas, mas + n);
    do
        output(mas, n);
    while (next_permutation(mas, mas + n));
    return 0;
}