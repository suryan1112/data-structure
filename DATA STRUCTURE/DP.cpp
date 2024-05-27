#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

int fibo_helper(int n, int *v)
{
    if (n <= 1)
    {
        v[n] = n;
        return n;
    }
    if (v[n] != -1)
        return v[n];
    int a, b;
    a = fibo_helper(n - 1, v);
    b = fibo_helper(n - 2, v);
    v[n] = a + b;
    return v[n];
}
int fibo_memoization(int n)
{ // top-bottom
    int *v = new int[n + 1];
    for (int i = 0; i <= n; i++)
        v[i] = -1;
    fibo_helper(n, v);
    return v[n];
}
int fibo_dynamic_programing(int n)
{
    int a[n + 1];
    a[0] = 0;
    a[1] = 1;
    for (int i = 2; i <= n; i++)
        a[i] = a[i - 1] + a[i - 2];
    return a[n];
}
int min_count(int n)
{
    if (n == 1)
        return 0;
    int a = INT_MAX;
    if (n % 2 == 0)
        a = min_count(n / 2);
    int b = INT_MAX;
    if (n % 3 == 0)
        b = min_count(n / 3);

    return 1 + min(min_count(n - 1), min(a, b));
}

int min_count_memoization(int n, unordered_map<int, int> &m)
{
    if (n == 1)
        return 0;
    int a = INT_MAX;
    if (n % 2 == 0)
    {
        if (m.count(n / 2))
            a = m[n / 2];
        else
        {
            a = min_count(n / 2);
            m[n / 2] = a;
        }
    }
    int b = INT_MAX;
    if (n % 3 == 0)
    {
        if (m.count(n / 3))
            b = m[n / 3];
        else
        {
            b = min_count(n / 3);
            m[n / 3] = b;
        }
    }
    return 1 + min(min_count(n - 1), min(a, b));
}
// int unique_squares_sum(int n, int m) {
//     int a[n + 1];
//     a[0] = 0;
//     a[1] = 1;
//     a[2]=0;
//     for (int i = 3; i <= n; i++) {
//         int sum = 1; // Initialize sum to 1
//         for (int j = 1; pow(j, m) <= i; j++) { // Fix loop condition
//             sum += a[i - static_cast<int>(pow(j, m))]; // Update sum
//         }
//         a[i] = sum; // Update array a
//         cout<<a[i]<<" ";
//     }
//     return a[n];
// }

int uniqueWays(int a, int b)
{
    int dp[a + 1];
    fill(dp, dp + a + 1, 0);
    dp[0] = 1;
    for (int i = 1; pow(i, b) <= a; i++)
    {
        for (int j = a; j >= pow(i, b); j--)
        {
            dp[j] += dp[j - static_cast<int>(pow(i, b))];
        }
    }
    return dp[a];
}
long long int coins_combinations(vector<int> &coins, int amount)
{
    int dp[amount + 1];
    fill(dp, dp + amount + 1, 0);
    dp[0] = 1;
    for (int i = coins[0]; i <= amount; i++)
    {
        for (int coin : coins)
            if (i >= coin)
            {
                dp[i] = dp[i] + dp[i - coin];
            }
    }
    for (int x : dp)
        cout << x << " ";
    return dp[amount];
}
int MCM(vector<int> &v){
    int n=v.size();
    int dp[n];
    dp[0]=0;
    dp[1]=0;
    for(int i=2;i<n;i++){
        dp[i]=v[i]*v[i-1]*
    }
}
int main()
{
    vector<int> coins = {1, 2, 3};
    cout << coins_combinations(coins, 4) << endl;
    return 0;
}
int min_count_DP(int n)
{
    vector<int> **a = new vector<int> *[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = new vector<int>();
    }

    a[0]->push_back(1);

    for (int i = 1; i < n; i++)
    {
        for (auto x : *a[i - 1])
        {
            a[i]->push_back(x + 1);
            a[i]->push_back(x * 2);
            a[i]->push_back(x * 3);

            if (x + 1 == n || x * 2 == n || x * 3 == n)
            {
                return i;
            }
        }
    }

    return 0;
}
int steps(int n)
{
    if (n == 3)
        return 4;
    if (n <= 2)
        return n;
    return steps(n - 1) + steps(n - 2) + steps(n - 3);
}
int steps_DP(int n)
{
    int a[n + 1];
    a[0] = 0;
    a[1] = 1;
    a[2] = 2;
    a[3] = 4;
    for (int i = 4; i <= n; i++)
        a[i] = a[i - 1] + a[i - 2] + a[i - 3];
    return a[n];
}
int square_sum(int n)
{
    if (n <= 3)
        return n;
    int mini = INT_MAX;
    for (int i = 1; i <= n; i++)
    {
        if (pow(i, 2) > n)
            break;
        mini = min(mini, square_sum(n - pow(i, 2)));
    }
    return mini + 1;
}
int square_sum_DP(int n)
{
    int a[n + 1];
    a[0] = 0;
    a[1] = 1;
    a[2] = 2;
    a[3] = 3;
    for (int i = 4; i <= n; i++)
    {
        int j = 1;
        int mini = INT_MAX;
        while (i - pow(j, 2) >= 0)
        {
            int k = i - pow(j, 2);
            mini = min(mini, a[k]);
            j++;
        }
        a[i] = mini + 1;
    }
    return a[n];
}
int BST(int n)
{
    // if(n==2) return 3;
    if (n <= 1)
        return 1;
    int x = BST(n - 1);
    int y = BST(n - 2);
    int p = (int)((long)x * x) % mod;
    int q = (int)(2 * (long)x * x) % mod;
    int ans = (p + q) % mod;
    return ans;
}
long long int BST_DP(int n)
{
    int a[n + 1];
    a[0] = a[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        a[i] = (a[i - 1] * a[i - 1] % mod + 2 * a[i - 1] * a[i - 2] % mod);
    }
    return a[n];
}
long long int countBT(int h)
{

    long long int dp[h + 1];
    // base cases
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= h; i++)
    {
        dp[i] = (dp[i - 1] * ((2 * dp[i - 2]) % mod + dp[i - 1]) % mod) % mod;
    }
    return dp[h];
}
int loot_house(int a[], int n)
{
    if (n == 1)
        return a[0];
    if (n == 0)
        return 0;
    return max(a[0] + loot_house(a + 2, n - 2), loot_house(a + 1, n - 1));
}
int loot_house_DP(int a[], int n)
{
    int b[n];
    b[0] = a[0];
    b[1] = max(a[0], a[1]);
    for (int i = 2; i < n; i++)
    {
        b[i] = max(a[i] + b[i - 2], b[i - 1]);
    }
    return b[n - 1];
}
int longest(int a[], int n)
{
    int b[n];
    b[0] = 1;
    for (int i = 1; i < n; i++)
    {
        int mini = INT_MAX, min_i = 0;
        for (int j = 0; j < i; j++)
        {
            if (a[j] < a[i])
                if (mini > a[j] - a[i])
                {
                    mini = a[j] - a[i];
                    min_i = j;
                }
            b[i] = b[min_i] + 1;
        }
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++)
            maxi = max(maxi, b[i]);
        return maxi;
    }
}
int squares(int n, int m)
{
    unordered_map<int, int> map;
    int count = 0;
    for (int i = 0; i <= pow(n, 1.0 / m); i++)
    {
        int ind = pow(i, m);
        int t = pow(n - ind, 1.0 / m);
        if (pow(t, m) == n - ind && !map.count(n - ind))
        {
            count++;
            map[i];
        }
    }
    return count;
}
int coin_changes(int n, int m)
{
    int a[m + 1];
    for (int i = 0; i < m + 1; i++)
        a[i] = 0;
    a[0] = 0;
    a[1] = 1;
    a[2] = 2;
    for (int i = 3; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
            a[i] += a[j];
        a[i]++;
    }
    for (int i = n + 1; i <= m; i++)
    {
        for (int j = i - 1; j >= i - 6; j--)
            a[i] += a[j];
    }
    return a[m];
}
int possiblitys(int a, int b)
{
    int size = pow(a, 1 / b);
    int arr[size];
    for (int i = 0; i < size; i++)
        arr[i + 1] = pow(i, b);
}
int WaysToMakeCoinChange(int n, int coins[], int amount)
{
    long long int a[amount + 1];
    for (int i = 0; i <= amount; i++)
        a[i] = 0;
    a[0] = 1;
    for (int i = 0; i < n; i++)
        for (int j = coins[i]; j <= amount; j++)
        {
            a[j] += a[j - coins[i]];
        }
}
int possibleWaysToSquare(int n, int m)
{
    int a[n + 1];
    a[0] = 1;
    a[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        int t = static_cast<int>(pow(i, 1.0 / m));
        int sum = 0;
        for (int j = 0; pow(t - j, m) > pow(pow(i / 2, 1.0 / m), m); j++)
        {
            int index = i - static_cast<int>(pow(t - j, m));
            if (index >= 0)
            {
                sum += a[index];
            }
        }
        a[i] = sum;
    }
    return a[n];
}