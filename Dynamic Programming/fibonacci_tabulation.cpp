/*Nikhil*/
#include <bits/stdc++.h>
using namespace std;

int fib(int n)
{
    if (n <= 1)
        return 1;

    vector<int> tab(n + 1);
    tab[0] = 0;
    tab[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        tab[i] = tab[i - 1] + tab[i - 2];
    }
    return tab[n];
}

int main()
{
    int n = 10;
    cout << "The " << n << " fibonacci number is : " << fib(n) << endl;
    return 0;
}