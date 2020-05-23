#include <iostream>
#include<stdio.h>
#include <math.h>

using namespace std;
//double  f(const double& x)
//{
//    return x * x - 81;
//}



//Функция Аккермана
static int recursion(int m, int n) {

    if (m == 0) {
        return n + 1;
    } 
    else if (n == 0 && m > 0) {
        return (recursion(m - 1, 1));
    }
    else {
        return recursion(m - 1, recursion(m, n - 1));
    }
}

//double recursionSecond(const double &a, const double &b, const double &e) {
//    double  ksi = (a + b) / 2;
//    if ((fabs(f(a) - f(b)) <= e) || (fabs(f(ksi)) <= e))
//        return (a + b) / 2;
//
//    if (f(a) * f(ksi) <= 0.0)
//        recursionSecond  (a, ksi, e);
//    else
//        recursionSecond(ksi, b, e);
//}

    int main() {
        const double a = 10;
        const double b = -10;
        const double e =0.001 ;

        
        cout << recursion(3, 5);

   /* cout << recursionSecond(a,b, e);*/
    }

