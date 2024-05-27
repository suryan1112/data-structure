#include<bits/stdc++.h>
using namespace std;

class trieNode{
    public:
        char data;
        trieNode**arr;
        bool isTerminal;
        trieNode(char data){
            this->data=data;
            arr=new trieNode*[26];
            for(int i=0;i<26;i++) arr[i]=NULL;
            isTerminal=false;
        }
};
class trie{
    trieNode*root;
    void add_trie2(string s,trieNode*route){
        if(s==""){
            route->isTerminal=true;
            return;
        }
        if(route->arr[s[0]-'a']){
            add_trie2(s.substr(1),route->arr[s[0]-'a']);
        }
        else{
        trieNode*node=new trieNode(s[0]);
        route->arr[s[0]-'a']=node;
        add_trie2(s.substr(1),node);
        }
    }
    bool search2(string s,trieNode*route){
        if(s==""){
            return route->isTerminal;
        }
        if(route->arr[s[0]-'a']){
            return search2(s.substr(1),route->arr[s[0]-'a']);
        }
        else return false;
    }
    void remove2(string s,trieNode*route){
        if(s==""){
            route->isTerminal=false;
            return;
        }
        remove2(s.substr(1),route->arr[s[0]-'a']);
    }
    bool pattern(string s,trieNode*route){
        if(s==""){
            return true;
        }
        if(route->arr[s[0]-'a']){
            return pattern(s.substr(1),route->arr[s[0]-'a']);
        }
        else return false;
    }
    bool isPalindromePresent=false;
    string reverse(string s){
        if(s.size()<=1) return s;
        s=reverse(s.substr(1))+s[0];
        return s;
    }
    public:
    trie(){
        root=new trieNode('\0');
    }/*
    void add_trie(string s){         // for check_pattern.
        if(s=="") return;
        add_trie2(s,root);
        add_trie(s.substr(1));
    }*/
    /*
    void add_trie(string s){             // for check_pallindrome.
        if(search(s)) isPalindromePresent=true;
        add_trie2(s,root);
        add_trie2(reverse(s),root);
    }*/
    void add_trie(string s){
        add_trie2(s,root);
    }
    bool search(string s){
        return search2(s,root);
    }
    void remove(string s){
        remove2(s,root);
    }
    bool check_pattern(string s){
        return pattern(s,root);
    }
        return isPalindromePresent;
    bool isPalindrome(){
    }
    void print_all(string s){
        print_all2(s,root,s);
    }
    void traversal(trieNode*route,string save){
        if(route->isTerminal) cout<<save<<endl;
        int sum=0;
        for(int i=0;i<26;i++){
            if(route->arr[i]){
                traversal(route->arr[i],save+route->arr[i]->data);
                sum++;
            }
        }
    }
    void print_all2(string s,trieNode*route,string save){
        if(s=="") traversal(route,save);
        print_all2(s.substr(1),route->arr[s[0]-'a'],save);
    }
};

int main(){
    trie tri;
    int n; cin>>n;
    for(int i=0;i<n;i++){
        string s; cin>>s;
        tri.add_trie(s);
    }
    string s2; cin>>s2;
    tri.print_all(s2);    
}