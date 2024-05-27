#include <bits/stdc++.h>
using namespace std;

int all_substrings(string s, string arr[])
{
    if (s == "")
    {
        arr[0] = "";
        return 1;
    }
    int t = all_substrings(s.substr(1), arr);
    for (int i = 0; i < t; i++)
    {
        arr[i + t] = s[0] + arr[i];
    }
    return 2 * t;
}
const string keypad[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

int pad(int n, string arr[])
{
    if (n == 0)
    {
        arr[0] = "";
        return 1;
    }
    int count = pad(n / 10, arr);
    int str_size = keypad[n % 10 - 2].length();
    string arr2[str_size * count];
    for (int i = 0; i < str_size; i++)
    {
        for (int j = 0; j < count; j++)
            arr2[i * count + j] = arr[j] + keypad[n % 10 - 2][i];
    }
    for (int i = 0; i < str_size * count; i++)
        arr[i] = arr2[i];
    return str_size * count;
}
bool check_AB(string s)
{
    if (s == "")
        return true;
    if (s[0] == 'a')
        return check_AB(s.substr(1));
    if (s.size() >= 2 && s[0] == 'b' && s[1] == 'b')
        return check_AB(s.substr(2));

    return false;
}
int steps_hopping(int n)
{
    if (n <= 2)
        return n;
    if (n == 3)
        return 4;
    return steps_hopping(n - 1) + steps_hopping(n - 2) + steps_hopping(n - 3);
}
int binary_search(int a[], int s, int e, int x)
{
    if (s > e)
        return -1;

    int mid = (s + e) / 2;
    if (a[mid] == x)
        return mid;
    if (a[mid] < x)
        return binary_search(a, mid + 1, e, x);
    else
        return binary_search(a, s, mid - 1, x);
}
int subset_arr(int a[], int b[][10], int n)
{
    if (n == 0)
        return 1;
    int si = subset_arr(a + 1, b, n - 1);
    for (int i = si; i < 2 * si; i++)
    {
        b[i][0] = a[0];
        for (int j = 1; j < n; j++)
            b[i][j] = b[i - si][j - 1];
    }
    return 2 * si;
}
vector<vector<int>> sum_subseq(int a[], int n, int k)
{
    vector<vector<int>> v;
    if (n == 0)
        return v;
    if (k == 0)
    {
        v.push_back(vector<int>());
        return v;
    }
    vector<vector<int>> v2 = sum_subseq(a + 1, n - 1, k - a[0]);
    for (int i = 0; i < v2.size(); i++)
    {
        v2[i].push_back(a[0]);
        v.push_back(v2[i]);
    }
    vector<vector<int>> v3 = sum_subseq(a + 1, n - 1, k);
    for (int i = 0; i < v3.size(); i++)
        v.push_back(v3[i]);

    return v;
}
vector<vector<int>> code_generator(string s)
{
    vector<vector<int>> v;
    if (s.size() == 0)
        return v;
    if (s.size() == 1)
    {
        vector<int> u = {s[0] - '1' + 'a'};
        v.push_back(u);
        return v;
    }
    vector<vector<int>> v2 = code_generator(s.substr(1));
    for (int i = 0; i < v2.size(); i++)
    {
        int c=s[0] + 'a' - '1';
        v2[i].insert(v2[i].begin(),c);
        v.push_back(v2[i]);
    }
    if (s.size() >= 2 && (s[0] < '2' || (s[0] == '2' && s[1] <= '6')))
    {
        vector<vector<int>> v3 = code_generator(s.substr(2));
        for (int i = 0; i < v3.size(); i++)
        {
            int c=(s[0] - '0') * 10 + (s[1] - '0') + 'a' - 1;
            v3[i].insert(v3[i].begin(),c);
            v.push_back(v3[i]);
        }
    }
    return v;
}
int main()
{
    string s = "12345";
    vector<vector<int>> v = code_generator(s);
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++)
            cout<<v[i][j]<<" ";
        cout<<endl;}
}

// int main()
// {
//     int n; cin>>n;
//     int a[n];
//     for(int i=0;i<n;i++) cin>>a[i];
//     int size; cin>>size;

//     vector<vector<int>> v=sum_subseq(a,n,size);
//     for(int i=0;i<v.size();i++){
//         for(int j=0;j<v[i].size();j++)
//             cout<<v[i][j]<<" ";
//         cout<<endl;}
// }