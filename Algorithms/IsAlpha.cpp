/*Nikhil*/
#include <iostream>
using namespace std;

bool isAlpha(char x)
{
    return ((65 <= x && x <= 90) || (97 <= x && x <= 122));
}

int main()
{
    char c = 'A';
    if (isAlpha(c))
    {
        cout << "It is an ALPHABET" << endl;
    }
    else
    {
        cout << "It is NOT an ALPHABET" << endl;
    }
    return 0;
}