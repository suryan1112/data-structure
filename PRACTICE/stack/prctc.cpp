#include <bits/stdc++.h>
#include <stack>
#include <queue>
using namespace std;

void rev_stc(stack<int> &stc1, stack<int> &stc2)
{
    if (stc1.empty())
        return;
    int data = stc1.top();
    stc1.pop();
    rev_stc(stc1, stc2);
    stc2.push(data);
}
void do_noting(stack<int> &stc1, stack<int> &stc2)
{
    rev_stc(stc1, stc2);
    while (stc2.size())
    {
        stc1.push(stc2.top());
        stc2.pop();
    }
}
void reverse_queue(queue<int> &q)
{
    if (q.empty())
        return;
    int data = q.front();
    q.pop();
    reverse_queue(q);
    q.push(data);
}
bool redundancy(string s)
{
    stack<int> stc;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ')')
        {
            int count = 0;
            while (stc.top() != '(')
            {
                stc.pop();
                count++;
            }
            if (count < 2)
                return true;
            stc.pop();
        }
        stc.push(s[i]);
    }
    return false;
}
int bracket_reversal(string s)
{
    stack<int> stc;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '}' && stc.top() == '{')
            stc.pop();
        else stc.push(s[i]);
    }
    cout << stc.top();
    if (stc.size() % 2 == 0)
        return true;
    else
        return false;
}
int main()
{
    string s;
    cin >> s;
    cout << bracket_reversal(s);
}
// int main()
// {
//     queue<int> stc;
//     int n;
//     cin >> n;
//     while (n--)
//     {
//         int t;
//         cin >> t;
//         stc.push(t);
//     }
//     reverse_queue(stc);
//     while (stc.size())
//     {
//         cout << stc.front();
//         stc.pop();
//     }
// }