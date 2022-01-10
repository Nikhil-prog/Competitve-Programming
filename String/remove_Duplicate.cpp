/*Nikhil*/
#include <iostream>
using namespace std;

string removeDup(string &s)
{
    int size = s.size();
    if (size < 2)
        return s;

    if (s[size - 1] == s[size - 2])
    {
        s.pop_back();
        return removeDup(s);
    }
    else
    {
        char last = s[size - 1];
        s.pop_back();
        return removeDup(s) + last;
    }
}

int main()
{
    string s = "aabbbccccdeee";
    cout << removeDup(s) << endl;
    return 0;
}
