/*Nikhil*/
#include <bits/stdc++.h>
using namespace std;

bool ispar(string x)
{
    stack<char> st;
    int n = x.size();
    for (int i = 0; i < n; i++)
    {
        if (st.empty())
        {
            st.push(x[i]);
        }
        else
        {
            if (x[i] == ')')
            {
                if (st.top() == '(')
                {
                    st.pop();
                }
                else
                {
                    st.push(x[i]);
                }
            }
            else if (x[i] == ']')
            {
                if (st.top() == '[')
                {
                    st.pop();
                }
                else
                {
                    st.push(x[i]);
                }
            }
            else if (x[i] == '}')
            {
                if (st.top() == '{')
                {
                    st.pop();
                }
                else
                {
                    st.push(x[i]);
                }
            }
            else
            {
                st.push(x[i]);
            }
        }
    }
    return st.empty();
}

int main()
{
    string a = "{([])}";
    string b = "{([]))";
    cout << "String a is Valid: " << ispar(a) << endl;
    cout << "String b is Valid: " << ispar(b) << endl;
    return 0;
}