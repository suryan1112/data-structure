#include <bits/stdc++.h>
using namespace std;

int power(int x, int n)
{
    if (n)
        return x * power(x, n - 1);
    return 1;
}
int fibonaci(int n)
{
    if (n < 2)
        return n;
    return fibonaci(n - 1) + fibonaci(n - 2);
}
void nodo(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i];
}
int ans[10];
int index = 0;
void firstIndex(int a[], int size, int n)
{
}
int count_zeros(int n)
{
    if (n == 0)
        return 0;
    return count_zeros(n / 10) + ((n % 10) ? 0 : 1);
}
double GSum(int k)
{
    if (k == -1)
        return 0;
    return GSum(k - 1) / 2.0 + 1;
}
bool palindrome(string s)
{
    int n = s.length();
    if (n < 2)
        return true;
    return s[0] == s[n - 1] && palindrome(s.substr(1, n - 2));
}
int digits_sum(int n)
{
    if (n == 0)
        return 0;
    return n % 10 + digits_sum(n / 10);
}
string remove_x(char c[])
{
    if (c[0] == '\0')
        return "\0";
    if (c[0] == 'x')
        return remove_x(c + 1);
    return c[0] + remove_x(c + 1);
}
string rmv_consecutive(char c[],char prev){
    if (c[0] == '\0')
        return "";
    if(c[0]==prev)
        return rmv_consecutive(c+1,prev);
    return prev+rmv_consecutive(c+1,c[0]);
}


int main()
{
    int a[]={2 ,1 ,5, 2, 3};
    merge_sort(a,0,4);
    for(int i=0;i<5;i++) cout<<a[i]<<" ";
}