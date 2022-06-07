/*Nikhil*/
#include <bits/stdc++.h>
using namespace std;
/*

Problem statement:

Extended Euclidean Algorithm:
Extended Euclidean algorithm also finds integer coefficients x and y such that:   ax + by = gcd(a, b)

*/

int extended_gcd(int a, int b, int *x, int *y)
{
    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }

    int x1, y1;
    int gcd = extended_gcd(b % a, a, &x1, &y1);

    *x = y1 - (b / a) * x1;
    *y = x1;
    return gcd;
}

int main()
{
    int x, y;
    int a = 1547, b = 560;
    int gcd_a_b = extended_gcd(a, b, &x, &y);
    cout << "The linear combination equation: \n";
    cout << a << "*(" << x << ") + " << b << "*(" << y << ") = " << gcd_a_b << endl;
    return 0;
}