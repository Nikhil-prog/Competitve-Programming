/*Nikhil*/
#include <iostream>
using namespace std;

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
    for (int i = l; i <= r; i++)
    {
        //permute all possible letters on lth postion
        swap(s, l, i);
        permute(s, l + 1, r);
        swap(s, l, i);
    }
}

int main()
{
    string s = "abcd";
    permute(s, 0, s.size() - 1);
    return 0;
}