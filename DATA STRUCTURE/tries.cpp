#include<bits/stdc++.h>
using namespace std;

class trieNode{
    public:
        char data;
        bool isTerminal;
        trieNode**child;
        trieNode(char data){
            this->data=data;
            isTerminal=false;
            child=new trieNode*[26];
            for(int i=0;i<26;i++) child[i]=NULL;
        }
};
class trie{
    trieNode*root;
    void insert2(string s,trieNode*node){
        if(s.size()==0){
            node->isTerminal=true;
            return;
        }
        if(node->child[s[0]-'a']) insert2(s.substr(1),node->child[s[0]-'a']);
        else{
            trieNode*new_node=new trieNode(s[0]);
            node->child[s[0]-'a']=new_node;
            insert2(s.substr(1),new_node);
        }
    }
    bool search2(string s,trieNode*node){
        if(s.size()==0 && node->isTerminal){
            return true;
        }else if(s.size()==0 && !node->isTerminal) return false;
        if(node->child[s[0]-'a']) return search2(s.substr(1),node->child[s[0]-'a']);
        else return false;
    }
    void remove2(string s,trieNode*node){
        if(s.size()==0 && node->isTerminal){
            node->isTerminal=false;
            return;
        }
        if(node->child[s[0]-'a']) remove2(s.substr(1),node->child[s[0]-'a']);
        else return;
    }
    bool pattern2(string s,trieNode*node){
        if(s.size()==0 ){
            return true;
        }
        if(node->child[s[0]-'a']) return pattern2(s.substr(1),node->child[s[0]-'a']);
        else return false;
    }
    void traversal(string s,trieNode*node,bool&b){
        if(node->child[s[0]-'a']){
            if(pattern2(s,node)) {b=true; return;}
        }
        for(int i=0;i<26;i++) 
            if(node->child[i]) traversal(s,node->child[i],b);
        // return false;
    }
    
    void traversal2(trieNode*node,string&str){

        if(node->isTerminal){
            cout<<str<<endl;
        }
        for(int i=0;i<26;i++) 
            if(node->child[i]) {
            str+=node->child[i]->data;
            traversal2(node->child[i],str);
            str=str.substr(0,str.size()-1);
            }
    }
    void similar2(string str,trieNode*node,string&save){
        if(str.size()==0){
            traversal2(node,save);
        }
        if(node->child[str[0]-'a']) similar2(str.substr(1),node->child[str[0]-'a'],save);

    }
    public:
    trie(){
        root=new trieNode('\0');
    }
    void insert(string s){
        insert2(s,root);
    }   
    bool search(string s){
        return search2(s,root);
    }
    void remove(string s){
        remove2(s,root);
    }
    bool pattern(string s){
        bool b=false;
        traversal(s,root,b);
        return b;
    }
    void similar(string str){
        string s=str;
        similar2(str,root,s);
    }
    bool checking(string s){
        if(s=="") return true;
        return checking2(s,root);
    }
    bool checking2(string s,trieNode*route){
        if(route->isTerminal){ 
            if(s.size() && route->child[s[0]-'a']){}
            else return checking(s);
        }
        if(s=="") return false;
        if(route->child[s[0]-'a']) return checking2(s.substr(1),route->child[s[0]-'a']);
        else return false;
    }
};
int main(){
    trie t;
    // int n; cin>>n;
    // string s[n];
    // for(int i=0;i<n;i++){
    //     cin>>s[i];
    //     t.insert(s[i]);
    // }
    // string str;cin>>str;
    // t.similar(str);

    t.insert("aaaa");
    t.insert("aaa");
    cout<<t.checking("aaaaaaa");
}