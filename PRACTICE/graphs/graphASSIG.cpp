#include <bits/stdc++.h>
#include <queue>
using namespace std;

bool coding_ninjas(vector<vector<char>> a, int n, int m, string s)
{
    if (s.size() == 0)
        return true;
    cout << s << " ";
    for (int i = -1; i <= 1; i++)
        for (int j = -1; j <= 1; j++)
            if (n + i >= 0 && m + j >= 0 && n + i < a.size() && m + j < a[0].size())
                if (a[n + i][m + j] == s[0])
                {
                    a[n + i][m + j] = '+';
                    if (coding_ninjas(a, n + i, m + j, s.substr(1)))
                        return true;
                }
    return false;
}
int sn = -1, sm = -1;
int ssn, ssm;
bool isCYCLE(vector<vector<char>> a, int ppn, int ppm, int pn, int pm, int n, int m)
{
    if (n == sn && m == sm)
        return true;
    sn = ssn;
    sm = ssm;
    cout << pn << a[pn][pm] << pm << "--->" << n << a[n][m] << m << endl;
    for (int i = -1; i <= 1; i++)
        for (int j = -1; j <= 1; j++)
            if (n + i >= 0 && m + j >= 0 && n + i < a.size() && m + j < a[0].size() && (i != 0 || j != 0))
                if (a[n + i][m + j] == a[n][m] && (n + i != pn || m + j != pm) && (n + i != ppn || m + j != ppm))
                {
                    // cout<<a[n + i][m + j] <<" "<< a[n][m]<<endl;
                    if (isCYCLE(a, pn, pm, n, m, n + i, m + j))
                        return true;
                }
    return false;
}
bool is_there_cycle(vector<vector<char>> a, int n, int m)
{
    unordered_map<char, int> map;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (map[a[i][j]] == 0)
            {
                ssn = i;
                ssm = j;
                if (isCYCLE(a, i, j, i, j, i, j))
                    return true;
                map[a[i][j]]++;
            }
    return false;
}
bool find_matching(vector<vector<char>> a, int n, int m)
{
    string s = "CODINGNINJA";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (a[i][j] == s[0])
                if (coding_ninjas(a, i, j, s.substr(1)))
                    return true;
    return false;
}
int cake(vector<vector<int>>& a, int n, int m)
{
    // cout << a[n][m] << " ";
    a[n][m]=0;
    int sum = 0;

    int direction[4][2] = {{0, 1}, {-1, 0}, {1, 0}, {0, -1}};
    for (int i = 0; i < 4; i++)
    {
        int x = n + direction[i][0];
        int y = m + direction[i][1];

        if (x >= 0 && y >= 0 && x < a.size() && y < a[0].size())
            if (a[x][y] == 1)
                sum += cake(a, x, y);
    }
    return sum+1;
}
int cake_count(vector<vector<int>> a, int n, int m)
{
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (a[i][j] == 1)
                maxi = max(maxi, cake(a, i, j));
    return maxi;
}
int main()
{
    int n, m;
    cin >> n;
    m=n;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    cout << cake_count(a, n, m) ;
}