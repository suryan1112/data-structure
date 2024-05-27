#include<bits/stdc++.h>
using namespace std;

int max_occurance(int a[],int n){
    unordered_map<int,int> map;
    int count=0;
    for(int i=0;i<n;i++){
        map[a[i]]++;
        if(map[count]<map[a[i]]) count=a[i];
    }
    return count;
}
vector<int> print_common(unordered_map<int,int> m1,unordered_map<int,int> m2){
    vector<int> v;
    for(unordered_map<int,int>::iterator itr=m1.begin();itr!=m1.end();itr++){
        int count=min(m1[itr->first],m2[itr->first]);
        while(count--){
            v.push_back(itr->first);                                                                                                                                                        
        }
    }sort(v.begin(),v.end());
    return v;
}
int count_sum_zeros(int a[],int n){
    unordered_map<int,int> m;
    int count=0;
    for(int i=0;i<n;i++){
        m[a[i]]++;
        if(m.count(-a[i])) count+=m[-a[i]];
    }
    return count;
}
string unique_characters(string s){
    string str;
    unordered_map<char,int> m;
    for(auto x:s) m[x]++;
    for(int i=0;i<s.size();i++){
        if(m[s[i]]) {str+=s[i]; m[s[i]]==0;}
    }
    return str;
}
vector<int> max_length(int a[],int n){
    unordered_map<int,int> m;
    vector<int> v;
    for(int i=0;i<n;i++) m[a[i]]++;
    int length_max=0;
    for(int i=0;i<n;i++){
        int k=0;
        while(m.count(a[i]+k)) k++;
        k--;
        if(k>length_max){
            v.clear();
            v.push_back(a[i]);
            v.push_back(a[i]+k);
            length_max=max(length_max,k);
        }
    }return v;
}
int pairs(int a[],int n,int k){
    int count=0;
     unordered_map<int,int> m;
    for(int i=0;i<n;i++) m[a[i]]++;
    for(int i=0;i<n;i++){
        if(m.count(a[i]+k)) count+=m[a[i]+k];
        
    }
    return count;
}
int sub_arrey(int a[],int n){
    unordered_map<int,int> m;
    int sum=0,length=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
        if(m.count(sum)){
            // m.erase(sum);
            int t=sub_arrey(a+i+1,n);
            if(t<0)
                return i-m[sum] +abs(t);
            else if(m[sum]==0) return m[sum]-i;
            else return i-m[sum];
        } return i-m[sum];
        m[sum]=i;
    }
    return 0;
}
int main(){
    int n; cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    cout<<abs(sub_arrey(a,n));
}