#include<bits/stdc++.h>
using namespace std;

int max_frequency(int* a,int size){
    unordered_map<int,int> m;
    int key=0,value=0;
    for(int i=0;i<size;i++){
        m[a[i]]++;
        if(m[a[i]]>value){
            key=a[i];
            value=m[a[i]];
        }
    }
    return key;
}
int main(){
    int n; cin>>n;
    int a[n];
    for( int i=0;i<n;i++) cin>>a[i];
    cout<<max_frequency(a,n);
}