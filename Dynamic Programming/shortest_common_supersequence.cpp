#include <bits/stdc++.h>
using namespace std;

string lcs(string &a, string &b)
{
    int n = a.size(), m = b.size();
    vector<vector<string>> dp(n + 1, vector<string>(m + 1, ""));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + a[i - 1];
            }
            else
            {
                dp[i][j] = (dp[i - 1][j].size() > dp[i][j - 1].size()) ? dp[i - 1][j] : dp[i][j - 1];
            }
        }
    }
    return dp[n][m];
}

string shortestCommonSupersequence(string str1, string str2)
{
    int i = 0, j = 0;
    string res = "";
    for (char c : lcs(str1, str2))
    {
        while (str1[i] != c)
            res.push_back(str1[i++]);
        while (str2[j] != c)
            res.push_back(str2[j++]);
        res.push_back(str1[i++]);
        j++;
    }
    return res + str1.substr(i) + str2.substr(j);
}

int main()
{
    string a = "abac";
    string b = "cab";
    cout << "The shortest common supersequence : " << shortestCommonSupersequence(a, b) << "\n";
    return 0;
}