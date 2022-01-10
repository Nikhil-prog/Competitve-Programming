/*Nikhil*/
#include <bits/stdc++.h>
using namespace std;

// string to be only consists of: +, -, *, /, (, ), small english aplhabets as operands

bool isOperator(char c)
{
	return c == '+' || c == '-' || c == '*' || c == '/';
}

int precedence(char c)
{
	if (c == '(' || c == ')')
		return 0;
	else if (c == '+' || c == '-')
		return 1;
	else if (c == '*' || c == '/')
		return 2;
	return -1;
}

string infix_to_postfix(string s)
{
	stack<char> st;
	string postfix_exp = "";
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(')
		{
			st.push(s[i]);
		}
		else if (s[i] == ')')
		{
			while (!st.empty())
			{
				if (st.top() == '(')
				{
					st.pop();
					break;
				}
				else
				{
					postfix_exp.push_back(st.top());
					st.pop();
				}
			}
		}
		else if (isOperator(s[i]))
		{
			if (st.empty())
			{
				st.push(s[i]);
			}
			else
			{
				bool flag = true;
				while (!st.empty())
				{
					if (precedence(st.top()) == precedence(s[i]))
					{
						postfix_exp.push_back(st.top());
						st.pop();
					}
					else if (precedence(st.top()) > precedence(s[i]))
					{
						postfix_exp.push_back(st.top());
						st.pop();
					}
					else
					{
						flag = false;
						st.push(s[i]);
						break;
					}
				}
				if (flag)
				{
					st.push(s[i]);
				}
			}
		}
		else
		{
			postfix_exp.push_back(s[i]);
		}
	}

	while (!st.empty())
	{
		postfix_exp.push_back(st.top());
		st.pop();
	}
	return postfix_exp;
}

int main()
{
	string infix = "a+(b/c-d)*e";
	cout << infix_to_postfix(infix) << endl;
	return 0;
}