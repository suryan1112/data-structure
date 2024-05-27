#include <bits/stdc++.h>
#include <stack>
using namespace std;

bool check()
{
    stack<char> stc;
    string s;
    cin >> s;
    int i = 0;
    for (i = 0; i < s.size(); i++)
    {
        if (s[i] == '{' || s[i] == '[' || s[i] == '(')
            stc.push(s[i]);
        else
        {
            if (stc.size() && (s[i] == stc.top() + 1 || s[i] == stc.top() + 2))
                stc.pop();
            else
                return false;
        }
    }
    if (stc.empty())
        return true;
    return false;
}
int main()
{
    cout << check();
}
