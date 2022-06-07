/*Nikhil*/
#include <bits/stdc++.h>
using namespace std;
/*

Problem statement:

Basic Euclidean Algorithm for GCD
The algorithm is based on the below facts.
1.If we subtract a smaller number from a larger (we reduce a larger number), GCD doesn’t change. So if we keep subtracting repeatedly the larger of two, we end up with GCD.
2.Now instead of subtraction, if we divide the smaller number, the algorithm stops when we find remainder 0.

*/

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    int a = 1547, b = 560;
    cout << "The GCD of " << a << " and " << b << " is : " << gcd(a, b) << endl;
    return 0;
}