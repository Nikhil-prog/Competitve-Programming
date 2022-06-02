/*Nikhil*/
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
/*
Problem statement:
Modular Inverse – Modular Inverse of an integer ‘a’ modulo ‘M’ is an integer ‘x’ such that,  (a * x) % M = 1
*/

int exponential_power(int a, int n, int MOD)
{
    int res = 1;
    while (n)
    {
        if (n & 1)
        {
            res = (res * 1ll * a) % MOD;
        }
        a = (a * 1ll * a) % MOD;
        n = n >> 1;
    }
    return res;
}

// using the information that 1 <= x <= M - 1
// TIME COMPLEXITY - O(M)
int modular_inverse_brute_force(int a, int M)
{
    // modular inverse does not exists if a and m are NOT co-prime
    if (__gcd(a, M) != 1)
        return -1;

    int x;
    for (int i = 1; i <= M - 1; i++)
    {
        if ((a * i) % M == 1)
        {
            x = i;
            break;
        }
    }
    return x;
}

// using FERMAT's LITTLE THEOREM
// assumption: M is a prime number (else we cannot caluclate it)
// TIME COMPLEXITY - O(log M)
int modular_inverse_fermat(int a, int M)
{
    // modular inverse does not exists if a and m are NOT co-prime
    if (__gcd(a, M) != 1)
        return -1;
    return exponential_power(a, M - 2, M);
}

int main()
{
    int a = 2, M = 1e9 + 7;

    auto start1 = high_resolution_clock::now();
    int inv1 = modular_inverse_brute_force(a, M);
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(stop1 - start1);

    auto start2 = high_resolution_clock::now();
    int inv2 = modular_inverse_fermat(a, M);
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(stop2 - start2);

    cout << "Modular inverse using brute force    : " << inv1 << " | TIME: " << (duration1.count()) << " ms \n";
    cout << "Modular inverse using Fermat theorem : " << inv2 << " | TIME: " << (duration2.count()) << " ms\n";
    return 0;
}