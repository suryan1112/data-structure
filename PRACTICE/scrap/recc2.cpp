#include<bits/stdc++.h>
using namespace std;

void merge_sort(int a[],int si,int ei){
    if(si>=ei) return;
    int mid=(si+ei)/2;
    merge_sort(a,si,mid);
    merge_sort(a,mid+1,ei);

    int savi[ei-si+1];
    int i=si,j=mid+1,k=0;
    while(i<mid+1 && j<ei+1){
        if(a[i]>a[j])
            savi[k++]=a[j++];
        else savi[k++]=a[i++];
    }
    while(i<mid+1) savi[k++]=a[i++];
    while(j<ei+1) savi[k++]=a[j++];

    for(int i=si;i<=ei;i++) a[i]=savi[i-si];

}


void quick_sort2(int a[], int si, int ei) {
    if (si >= ei)
        return;

    int i = si, j = ei;
    int first = a[si];
    
    while (i < j) {
        while (i < j && a[j] > first)
            j--;
        while (i < j && a[i] <= first)
            i++;
        if (i < j) {
            int save = a[j];
            a[j] = a[i];
            a[i] = save;
        }
    }
    a[si] = a[i];
    a[i] = first;

    quick_sort2(a, si, i - 1);
    quick_sort2(a, i + 1, ei);
}
int main(){
    int n; cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    quick_sort2(a,0,n-1);
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
}