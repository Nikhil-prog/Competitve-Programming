/*Nikhil*/
#include <bits/stdc++.h>
using namespace std;

vector<string> traverse(vector<vector<int>> &tab, string &a, string &b, int n, int m)
{
    if (n == 0 || m == 0)
    {
        return {""};
    }

    if (a[n - 1] == b[m - 1])
    {
        vector<string> lcs_list = traverse(tab, a, b, n - 1, m - 1);
        for (string &x : lcs_list)
        {
            x.push_back(a[n - 1]);
        }
        return lcs_list;
    }
    else
    {
        if (tab[n - 1][m] == tab[n][m - 1])
        {
            vector<string> top_lcs_list = traverse(tab, a, b, n - 1, m);
            vector<string> left_lcs_list = traverse(tab, a, b, n, m - 1);

            // merge both vectors
            top_lcs_list.insert(top_lcs_list.end(), left_lcs_list.begin(), left_lcs_list.end());
            return top_lcs_list;
        }
        else if (tab[n - 1][m] > tab[n][m - 1])
        {
            return traverse(tab, a, b, n - 1, m);
        }
        else
        {
            return traverse(tab, a, b, n, m - 1);
        }
    }
}

void lcs(vector<vector<int>> &tab, string &a, string &b, int n, int m)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                tab[i][j] = tab[i - 1][j - 1] + 1;
            }
            else
            {
                tab[i][j] = max(tab[i - 1][j], tab[i][j - 1]);
            }
        }
    }
}

void printLCS(string &a, string &b)
{
    int n = a.size(), m = b.size();
    vector<vector<int>> tab(n + 1, vector<int>(m + 1));
    lcs(tab, a, b, n, m);
    vector<string> lcs_list = traverse(tab, a, b, n, m);

    // to remove duplicates lcs
    set<string> final_lcs(make_move_iterator(lcs_list.begin()), make_move_iterator(lcs_list.end()));

    for (string lcs : final_lcs)
    {
        cout << lcs << "\n";
    }
    cout << "\n";
}

int main()
{
    string x = "TYABYZC";
    string y = "AABCXY";
    printLCS(x, y);
    return 0;
}