#include <bits/stdc++.h>
using namespace std;

bool isPallindrome(string s){
    int n=s.size();
    if(s[0]!=s[n-1]) return false;
    if(n<2) return true;
    return isPallindrome(s.substr(1,n-2));
}

int main() {
    string s; cin>>s;
    cout<<isPallindrome(s);
    // cout<<s.substr(1,5);
}
class Solution {
public:
    bool isPalindrome(string s) {
        int l=0,e=s.size()-1;
        while(l<s){
            if(!isalnum(s[l])){l++; continue;}
            if(!isalnum(s[e])){e--; continue;}
            if(tolower)
        }
    }
};