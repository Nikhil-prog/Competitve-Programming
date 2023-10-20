/*Nikhil*/
#include <bits/stdc++.h>
using namespace std;

/*
Problem statement:
Given a number n, print all primes smaller than or equal to n. It is also given that n is a small number.
*/

void print_primes(int n)
{
    vector<int> prime(n + 1, true);
    for (int i = 2; i * i <= n; i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= n; j = j + i)
            {
                prime[j] = false;
            }
        }
    }

    cout << "All primes number for given range: ";
    for (int i = 2; i <= n; i++)
    {
        if (prime[i])
            cout << i << " ";
    }
    cout << "\n";
}

int main()
{
    int n = 50;
    print_primes(n);
    return 0;
}