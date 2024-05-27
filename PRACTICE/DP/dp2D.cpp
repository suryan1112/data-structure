#include <bits/stdc++.h>
using namespace std;
#define mod 1000000009

int minPATH(vector<vector<int>> a, int n, int m)
{
    vector<vector<int>> arr(n,vector<int>(m,-1));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++) 
            arr[i][j]=INT_MAX;
        
    return -1;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n,vector<int>(m,-1));

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++) 
            cin>>a[i][j];
    cout << minPATH(a, n, m);
}