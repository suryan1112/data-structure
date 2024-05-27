#include <bits/stdc++.h>
using namespace std;

// vector<vector<char>> code_generator(string s)
// {
//     vector<vector<char>> v;
//     if (s.size() == 0)
//         return v;
//     if (s.size() == 1)
//     {
//         vector<char> u = {s[0] - '1' + 'a'};
//         v.push_back(u);
//         return v;
//     }
//     vector<vector<char>> v2 = code_generator(s.substr(1));
//     for (int i = 0; i < v2.size(); i++)
//     {
//         int c = s[0] + 'a' - '1';
//         v2[i].insert(v2[i].begin(), c);
//         v.push_back(v2[i]);
//     }
//     if (s.size() >= 2 && (s[0] < '2' || (s[0] == '2' && s[1] <= '6')))
//     {
//         vector<vector<char>> v3 = code_generator(s.substr(2));
//         for (int i = 0; i < v3.size(); i++)
//         {
//             int c = (s[0] - '0') * 10 + (s[1] - '0') + 'a' - 1;
//             v3[i].insert(v3[i].begin(), c);
//             v.push_back(v3[i]);
//         }
//     }
//     return v;
// }

vector<string> permutation(string s)
{
    vector<string> v;
    if (s.size() == 0)
    {
        vector<string> u = {""};
        return u;
    }
    vector<string> v1 = permutation(s.substr(1));

    for (int i = 0; i < v1.size(); i++)
        for (int j = 0; j <= v1[i].size(); j++)
            v.push_back(v1[i].substr(0, j) + s[0] + v1[i].substr(j));
    return v;
}
int duplicate(int a[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];
    return (n) * (n - 1) / 2 - sum;
}

int main()
{
    int a[] = {0, 3, 1, 5, 4, 3, 2};
    cout << duplicate(a, 7);
}
// int main()
// {
//     string s = "abcdef";
//     vector<string> v = permutation(s);
//     for (int i = 0; i < v.size(); i++)
//     {
//         cout << v[i] << endl;
//     }
// }