/*Nikhil*/
#include <bits/stdc++.h>
using namespace std;

string traverse(vector<vector<int>> &tab, string &s, int n)
{
    int i = n, j = n;
    string res = "";
    while (i > 0 && j > 0)
    {
        if (tab[i][j] == 1 + tab[i - 1][j - 1])
        {
            res.push_back(s[i - 1]);
            i--;
            j--;
        }
        else if (tab[i][j] == tab[i - 1][j])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    reverse(res.begin(), res.end());
    return res;
}

string longest_rep_subseq(string &a)
{
    string b = a;
    int n = a.size(), m = b.size();
    vector<vector<int>> tab(n + 1, vector<int>(m + 1));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[j - 1] && i != j)
            {
                tab[i][j] = tab[i - 1][j - 1] + 1;
            }
            else
            {
                tab[i][j] = max(tab[i - 1][j], tab[i][j - 1]);
            }
        }
    }
    return traverse(tab, a, n);
}

string print_longest_rep_subseq(string &s)
{
    return longest_rep_subseq(s);
}

int main()
{
    string s = "AABEBCDD";
    cout << "The length of longest repeating subsequence: " << print_longest_rep_subseq(s) << endl;
    return 0;
}