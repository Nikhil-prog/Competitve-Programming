/*Nikhil*/
#include <bits/stdc++.h>
using namespace std;

vector<int> memo;

int fib(int n)
{
    if (memo[n] == -1)
    {
        if (n <= 1)
            memo[n] = n;
        else
            memo[n] = fib(n - 1) + fib(n - 2);
    }
    return memo[n];
}

int main()
{
    int n = 10;
    memo.resize(n + 1, -1);
    cout << "The " << n << " fibonacci number is : " << fib(n) << endl;
    return 0;
}