/*Nikhil*/
#include <iostream>
using namespace std;

//Print all permutation of "ABC" that does not contain "AB" as substring
bool isSafe(string s, int l, int i, int r)
{
    if (l != 0 && s[l - 1] == 'A' && s[i] == 'B')
    {
        return false;
    }
    if ((l + 1) == r && s[l] == 'B' && s[i] == 'A')
    {
        return false;
    }
    return true;
}

void swap(string &s, int i, int j)
{
    char temp = s.at(i);
    s.at(i) = s.at(j);
    s.at(j) = temp;
}

void permute(string s, int l, int r)
{
    if (l == r)
    {
        cout << s << endl;
        return;
    }
    else
    {
        for (int i = l; i <= r; i++)
        {
            if (isSafe(s, l, i, r))
            {
                swap(s, l, i);
                permute(s, l + 1, r);
                swap(s, l, i);
            }
        }
    }
}

int main()
{
    string s = "ABC";
    permute(s, 0, s.size() - 1);
    return 0;
}
