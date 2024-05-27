#include <bits/stdc++.h>
#include <queue>
using namespace std;

bool checkPQ(int a[], int n)
{

    for (int i = n - 1; i > 0; i--)
    {
        int p = (i - 1) / 2;
        if (a[p] < a[i])
            return false;
    }
    return true;
}
vector<int> mergeKsorted(vector<vector<int>> v, int n, unordered_map<int, int> map)
{

    vector<int> u;
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++)
    {
        pq.push(v[i][0]);
    }
    int a[n];
    for (int i = 0; i < n; i++)
        a[i] = 0;

    while (pq.size())
    {
        // cout << pq.top() << " ";
        u.push_back(pq.top());
        int index = map[pq.top()];
        a[index]++;

        if (v[index].size() > a[index])
            pq.push(v[index][a[index]]);
        pq.pop();
    }
    return u;
}
vector<int> Running_median(int a[], int n)
{
    double t=0;
    vector<int> v;
    v.push(a[t]);
    for(int i=2;i<n;i++){
        t+=1/2;
        if(t*10%10==0){
            v.push_back(a[t]);
        }
        int value=(a[t-1/2]+a[t+1/2])/2
        v.push_back(value);

        cout<<v.back()<<" ";
    }
    
}
int main(){
    int n;cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];

    Running_median(a,n);
}
// int main()
// {
//     int n;cin>>n;
//     vector<vector<int>> v;
//     unordered_map<int, int> map;
//     for (int i = 0; i < n; i++)
//     {
//         int m;
//         cin >> m;
//         vector<int> u;
//         for (int j = 0; j < m; j++)
//         {
//             int l;
//             cin >> l;
//             map[l] = i;
//             u.push_back(l);
//         }
//         v.push_back(u);
//     }
//     mergeKsorted(v, n, map);
// }