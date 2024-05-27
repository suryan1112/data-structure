#include <bits/stdc++.h>
using namespace std;
#define mod 1000000009

int minSTEPS(int n)
{
    int a[n + 1];
    a[0] = 0;
    a[1] = 1;
    a[2] = 1;
    a[3] = 1;
    for (int i = 4; i <= n; i++)
    {
        a[i] = a[i - 1];
        if (i % 3 == 0)
            a[i] = min(a[i / 3], a[i]);
        if (i % 2 == 0)
            a[i] = min(a[i / 2], a[i]);
        a[i] += 1;
    }
    return a[n];
}
int allPOSSIBLES(int n)
{
    int a[n + 1];
    a[0] = 1;
    a[1] = 1;
    a[2] = 2;
    for (int i = 3; i <= n; i++)
    {
        a[i] = a[i - 1] + a[i - 2] + a[i - 3];
    }
    return a[n];
}
int minSQUARE(int n)
{
    // Create a DP array to store the minimum number of perfect squares
    vector<int> a(n + 1, INT_MAX);

    // Base cases
    a[0] = 0;

    // Loop over all numbers from 1 to n
    for (int i = 1; i <= n; i++)
    {
        // Check every square number j^2 less than or equal to i
        for (int j = 1; j * j <= i; j++)
        {
            a[i] = min(a[i], a[i - j * j] + 1);
        }
        // Debug output
        cout << "For i = " << i << ", minimum squares = " << a[i] << endl;
    }

    return a[n];
}
int countBST(int n)
{
    vector<int> a(n + 1, 0);
    a[0] = 1; // Base case: one way to arrange zero nodes (empty tree)
    a[1] = 1; // Base case: one way to arrange one node

    // Calculate number of distinct BSTs for each number of nodes
    for (int i = 2; i <= n; i++)
    {
        long d1 = ((long)a[i - 1] * a[i - 1]) % mod;
        long d2 = ((long)2 * a[i - 1] * a[i - 2]) % mod;
        a[i] = (d1 + d2) % mod;
    }
    return a[n];
}
int lootHOUSE(int a[], int n)
{
    int arr[n];
    arr[0] = a[0];
    arr[1] = a[1];
    for (int i = 2; i < n; i++)
    {
        arr[i] = max(arr[i - 1], arr[i - 2] + a[i]);
    }
    return arr[n - 1];
}
int longestSUBSEQ(int a[], int n)
{
        int arr[n];
        int maxi=0;
        for (int i = 1; i < n; i++)
        {   
            arr[i]=1;
            for (int j = i - 1; j >= 0; j--)
            {
                if (a[j] < a[i])
                    arr[i] = max(arr[i],arr[j]+1);
                cout << a[j] << " " << a[i]<<"-->"<<arr[i] << endl;
                
            }
            maxi=max(maxi,arr[i]);
        }
        return maxi;
}
    int main()
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        cout <<endl<< longestSUBSEQ(a, n);
    }