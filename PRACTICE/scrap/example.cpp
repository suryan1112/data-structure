#include <bits/stdc++.h>
using namespace std;

// int main()
// {
//     int n, m;
//     cin >> n >> m;
//     int **p = new int *[n];
//     for (int i = 0; i < n; i++)
//     {
//         p[i] = new int[m];
//         for (int j = 0; j < m; j++)
//             cin >> p[i][j];
//     }
//     for (int i = 0; i < n; i++)
//         for (int j = 0; j < m; j++)
//             cout << p[i][j]<<" ";
//     for (int i = 0; i < n; i++)
//         delete[] p[i];
//     delete[] p;

//     for (int i = 0; i < n; i++)
//         for (int j = 0; j < m; j++)
//             cout << p[i][j];
// }

void pi_314(string &s)
{
    for (int i = 0; i < s.size() - 1; i++)
    {
        if (s[i] == s[i + 1])
            s = s.substr(0, i + 1) + "*" + s.substr(i + 1);
    }
}
int str_int(string s)
{
    if (s == "")
        return 0;
    int n = s.length();
    return str_int(s.substr(0, n - 1)) * 10 + (s[n - 1] - '0');
}
void tower_of_hanoi(int n, char a, char b, char c)
{
    if (n == 0)
        return;
    tower_of_hanoi(n - 1, a, c, b);
    cout << a << " " << c << endl;
    tower_of_hanoi(n - 1, b, a, c);
}
int main()
{
    vector<int> vct = {
        1};
}