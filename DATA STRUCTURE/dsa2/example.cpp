#include<iostream>
using namespace std;

class trieNode{
    public:
        char data;
        bool isTerminal;
        trieNode**arr;
        trieNode(char data){
            this->data=data;
            isTerminal=false;
            arr=new trieNode*[26];
            for(int i=0;i<26;i++) arr[i]=NULL;
        }
};
class WordDictionary {
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
        if(s=="") return route->isTerminal;
        if(s[0]=='.'){
            bool b=false;
            for(int i=0;i<26;i++) 
                if(route->arr[i]) b=max(b,search2(s.substr(1),route->arr[i]));
            return b;
        }
        if(route->arr[s[0]-'a'])
            return search2(s.substr(1),route->arr[s[0]-'a']);
        else return false;
    }
    void print_all(string s){
        for(int i=0;i<10;i++)
    }
public:
    WordDictionary(){
        root=new trieNode('\0');
    } 
    void addWord(string word) {
        add_trie2(word,root);
    }
    bool search(string word) {
        return search2(word,root);
    }
    vector<int> lexographical(int n){
        for(int i=1;i<=n;i++) addWord(i);
        printlexographical()
    }
};
int main(){
    WordDictionary wordDictionary;
    wordDictionary.addWord("bad");
    wordDictionary.addWord("dad");
    wordDictionary.addWord("mad");
    cout<<wordDictionary.search("pad"); // return False
    cout<<wordDictionary.search("bad"); // return True
    cout<<wordDictionary.search(".ad"); // return True
    cout<<wordDictionary.search("b.."); // return True
}