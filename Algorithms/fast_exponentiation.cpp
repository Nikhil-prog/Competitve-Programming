/*Nikhil*/
#include <bits/stdc++.h>
using namespace std;

/*
    following is the recursive solution for calculating exponent
    of a number in O(log n) time.
    It also handles x^n,  with n being negative as well.

    *NOTE:for High constraints use long double instead double.*
*/

double power(double x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    else if (abs(n) == 1)
    {
        return (n > 0) ? x : 1 / x;
    }

    double half = power(x, abs(n) / 2);
    half = half * half;
    if (abs(n) % 2)
    {
        half *= x;
    }
    return (n > 0) ? half : 1 / half;
}

int main()
{
    cout << "2   raised to power 5 is  : " << power(2, 5) << endl;
    cout << "2.5 raised to power 3 is  : " << power(2.5, 3) << endl;
    cout << "3   raised to power -2 is : " << power(3, -2) << endl;
    cout << "10  raised to power 0 is  : " << power(10, 0) << endl;
    cout << "6   raised to power 1 is  : " << power(6, 1) << endl;
    return 0;
}