#include <bits/stdc++.h>
using namespace std;

void comparision(int a[], int n1, int b[], int n2)
{
    int i = 0, j = 0;
    while (i < n1 && j < n2)
    {
        if (a[i] == b[j])
            cout << a[i] << " ";
        if (a[i] < b[j])
            i++;
        else
            j++;
    }
}
int pair_sum(int a[], int n, int x)
{
    int i = 0, j = n - 1;
    int count = 0;
    while (i < j)
    {
        int sum = a[i] + a[j];
        if (sum < x)
            i++;
        else if (sum > x)
            j--;
        else
        {
            int ct1 = i;
            while (i < j && a[i] == a[i + 1])
                i++;
            ct1 = i - ct1 + 1;

            int ct2 = j;
            while (i < j && a[j] == a[j - 1])
                j--;
            ct2 = ct2 - j + 1;

            i++;
            j--;
            count += ct1 * ct2;
        }
    }
    return count;
}

void array_Rotation(int a[],int s,int n){
    if(n<=0) return;

    int key=a[0];
    for(int i=0;i<s-1;i++) a[i]=a[i+1];
    a[s-1]=key;

    array_Rotation(a,s,n-1);
}

int sortK(int a[],int n){

    for(int i=0;i<n-1;i++)
        if(a[i]>a[i+1])
            return i+1;
    return 0;
}
int TripletSum(int a[], int n, int x)
{   int count=0;
    for(int i=0;i<n-2;i++){
        int l=i+1,r=n-1;
        while (l<r)
        {
            int sum=a[i]+a[l]+a[r];
            if(sum==x){
                count++;
                l++;r--;
            }
            else if(sum<x) l++;
            else r--;
        }
    }
    return count;
}
int main()
{
    int n1;
    cin >> n1;
    int a[n1];
    for (int i = 0; i < n1; i++)
        cin >> a[i];
    int x; cin>>x;
    sort(a,a+n1);
    cout<<TripletSum(a,n1,x);
    
}