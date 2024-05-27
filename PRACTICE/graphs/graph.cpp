#include <bits/stdc++.h>
#include <queue>
using namespace std;

vector<int> printDFS(int **a, int n, int sv, bool visited[])
{
    vector<int> v;
    cout << sv << " ";
    visited[sv] = true;

    for (int i = 0; i < n; i++)
        if (a[sv][i] && !visited[i])
        {
            vector<int> u = printDFS(a, n, i, visited);
            v.insert(v.end(), u.begin(), u.end());
        }
    return v;
}
vector<vector<int>> disjointDFS(int **a, int n, bool visited[])
{
    vector<vector<int>> Vmain;
    for (int i = 0; i < n; i++)
        if (!visited[i])
        {
            vector<int> v = printDFS(a, n, i, visited);
            Vmain.push_back(v);
        }
    return Vmain;
}
vector<int> pathDFS(int **a, int n, int sv, int ev, bool visited[])
{
    vector<int> v;
    visited[sv] = true;
    if (sv == ev)
    {
        v.push_back(ev);
        return v;
    }
    bool b = false;
    for (int i = 0; i < n; i++)
        if (a[sv][i] && !visited[i])
        {
            vector<int> u = pathDFS(a, n, i, ev, visited);
            if (u.size())
            {
                u.push_back(sv);
                return u;
            }
        }
    return {};
}

void printBFS(int **a, int n, int sv, bool visited[])
{
    queue<int> q;
    q.push(sv);
    visited[sv] = true;
    while (q.size())
    {
        int current = q.front();
        cout << current << " ";
        q.pop();
        for (int i = 0; i < n; i++)
            if (a[current][i] && !visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
    }
}
void disjointBFS(int **a, int n, bool visited[])
{
    for (int i = 0; i < n; i++)
        if (!visited[i])
            printDFS(a, n, i, visited);
}
vector<int> pathBFS(int **a, int n, int sv, int ev, bool visited[], unordered_map<int, int> map)
{
    vector<int> v{ev};
    int d = ev;
    while (d != sv)
    {
        if (map[d] == 0)
            return {};
        d = map[d];
        v.push_back(d);
    }
    return v;
}

bool hasPATH(int **a, int n, int sv, int ev, bool visited[])
{

    if (sv == ev)
        return true;
    visited[sv] = true;
    bool b = false;
    for (int i = 0; i < n; i++)
        if (a[sv][i] && !visited[i])
            b = b | hasPATH(a, n, i, ev, visited);
    return b;
}

int main()
{
    int n;
    cin >> n;
    int edges;
    cin >> edges;

    int **a = new int *[n];
    bool visited[n];

    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
        a[i] = new int[n];
        for (int j = 0; j < n; j++)
            a[i][j] = 0;
    }
    unordered_map<int, int> map;
    while (edges--)
    {
        int m, n;
        cin >> m >> n;
        map[n] = m;
        a[m][n] = 1;
        a[n][m] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    vector<vector<int>> Vmain = disjointDFS(a, n, visited);
    cout << Vmain.size();
    // // cout<<endl;
    // printBFS(a, n, 0, visited);
    // int sv, ev;
    // cin >> sv >> ev;
}