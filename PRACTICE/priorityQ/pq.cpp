#include <bits/stdc++.h>
#include <queue>
using namespace std;

void K_sorted(int a[], int n, int k)
{
    priority_queue<int> pq;
    for (int i = 0; i < k; i++)
        pq.push(a[i]);

    for (int i = k; i < n; i++)
    {
        a[i - k] = pq.top();
        pq.pop();
        pq.push(a[i]);
    }
    for (int t = k; t > 0; t--)
    {
        a[n - t] = pq.top();
        pq.pop();
    }
}
vector<int> k_greater(int a[], int n, int k)
{
    priority_queue<int> pq;
    vector<int> v;
    for (int i = 0; i < n; i++)
        pq.push(a[i]);
    while (k--)
    {
        v.push_back(pq.top());
        // cout << pq.top() << " ";
        pq.pop();
    }
    return v;
}
vector<int> k_smallest(int a[], int n, int k)
{
    priority_queue<int,vector<int>,greater<int>> pq;
    vector<int> v;
    for (int i = 0; i < n; i++)
        pq.push(a[i]);
    while (k--)
    {
        v.push_back(pq.top());
        // cout << pq.top() << " ";
        pq.pop();
    }
    return v;
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int k;
    cin >> k;
    // K_sorted(a, n, k);
    // for (int i = 0; i < n; i++)
    //     cout << a[i] << " ";
    k_smallest(a, n, k);
}
