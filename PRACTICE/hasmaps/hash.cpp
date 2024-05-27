#include <bits/stdc++.h>
using namespace std;

vector<int> arrayINTERSECTION()
{
    unordered_map<int, int> map;
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        map[a[i]]++;
    }
    cin >> n;
    int b[n];
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        if (map[b[i]])
        {
            v.push_back(b[i]);
            map[b[i]]--;
        }
    }
    return v;
}
void pairSUM(int a[], int n)
{
    unordered_map<int, int> map;
    for (int i = 0; i < n; i++)
    {
        map[a[i]]++;
        if (map[-a[i]])
            cout << a[i] << " ";
    }
}
string uniqueCHARS(string s)
{
    string s2;
    unordered_map<char, int> map;
    for (int i = 0; i < s.size(); i++)
    {
        if (map[s[i]] == 0)
            s2 = s2 + s[i];
        map[s[i]]++;
    }
    return s2;
}
int pairDIFFERENCE(int a[], int n, int diff)
{

    unordered_map<int, int> map;
    for (int i = 0; i < n; i++)
    {
        map[a[i]]++;
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (map[a[i] - diff])
            count += map[a[i] - diff] - ((diff) ? 0 : 1);
    }
    if (diff == 0)
        return count / 2;
    return count;
}
int longestSUBSET(int a[], int n)
{
    unordered_map<int, int> map;
    int sum = 0, range = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        if (map[sum])
        {
            range = max(i - map[sum], range);
            continue;
        }
        map[sum] = i;
    }
    return range;
}
int longestCONSECUTIVE(int a[], int n)
{
    unordered_map<int, false> map;
    int cons = 0;
    for (int i = 0; i < n; i++)
    {
        map[a[i]] = true;
    }
    unordered_map<int, false>::iterator it = map.begin();
    for ( : it != map.end(); it++)
    {
        int d = it->first;
        int conta = 1;
        while (map[d++])
        {
            conta++;
            map.erase(d);
        }
        d = it->first;
        while (map[d--])
        {
            conta++;
            map.erase(d);
        }
        map.erase(it->first);
        cons = max(cons, d);
    }
    return cons;
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << longestSUBSET(a, n);
}