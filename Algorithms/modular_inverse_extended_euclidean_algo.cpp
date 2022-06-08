/*Nikhil*/
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
/*
Problem statement:
Modular Inverse – Modular Inverse of an integer ‘a’ modulo ‘M’ is an integer ‘x’ such that,  (a * x) % M = 1
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

void mod_inverse(int a, int Mod)
{
    int x, y;
    int gcd = extended_gcd(a, Mod, &x, &y);
    if (gcd != 1)
    {
        cout << "Modular inverse does NOT exists\n";
    }
    else
    {
        x = (x + Mod) % Mod;
        cout << "The Modular inverse of " << a << " mod " << Mod << " is : " << x << "\n";
    }
}

int main()
{
    int a = 4, M = 5;
    mod_inverse(a, M);
    return 0;
}