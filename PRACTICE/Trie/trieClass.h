#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode **arr;
    bool isTerminal;
    TrieNode(char data)
    {
        this->data = data;
        arr = new TrieNode *[26];

        for (int i = 0; i < 26; i++)
            arr[i] = NULL;
        isTerminal = false;
    }
    ~TrieNode()
    {
        for (int i = 0; i < 26; i++)
            delete arr[i];
    }
};

class Tries
{
    TrieNode *root;
    int size;

public:
    Tries()
    {
        root = new TrieNode('\0');
        size = 0;
    }

private:
    TrieNode *insert(string s, TrieNode *node)
    {
        cout << "insertion....  " << s << endl;
        if (node == NULL)
            node = new TrieNode(s[0]);

        if (s.size() == 1)
        {
            size++;
            node->isTerminal = true;
            return node;
        }
        int index = s[1] - 'a';
        node->arr[index] = insert(s.substr(1), node->arr[index]);

        return node;
    }

public:
    void insert(string s)
    {
        int index = s[0] - 'a';
        root->arr[index] = insert(s, root->arr[index]);
    }
    void insertFORCE(string s)
    {
        for(int i=0;i<s.size();i++){
            int index = s[i] - 'a';
            root->arr[index] = insert(s.substr(i), root->arr[index]);
        }
    }

private:
    bool search(string s, TrieNode *node,bool pattern=false)
    {
        cout << "searching....  " << s << endl;
        if (node == NULL)
            return false;

        if (s.size() == 1)
        {   
            if (node->isTerminal || pattern)
                return true;
            else
                return false;
        }
        return search(s.substr(1), node->arr[s[1] - 'a'],pattern);
    }

public:
    bool search(string s)
    {
        return search(s, root->arr[s[0] - 'a']);
    }
    bool pattern(string s){
        return search(s, root->arr[s[0] - 'a'],true);
    }

private:
    void deleta(string s, TrieNode *node)
    {
        if (s.size() == 1)
        {
            node->isTerminal = false;
            return;
        }
        deleta(s.substr(1), node->arr[s[1] - 'a']);
    }

public:
    void deleta(string s)
    {
        deleta(s, root->arr[s[0] - 'a']);
    }


    vector<string> AUTO(string s, TrieNode *node){

        vector<string> v;
        if (node == NULL)
            return v;

        if (s.size() <= 1){
            for (int i = 0; i < 26; i++){
                vector<string> vc=AUTO(s,node->arr[i]);
                
                for (int i = 0; i < vc.size(); i++)
                    v.push_back(node->data+vc[i]);
            }
            if( node->isTerminal){
                string str(1,node->data);
                v.push_back(str);
            }
            return v;
        }        

        vector<string> vc= AUTO(s.substr(1), node->arr[s[1] - 'a']);
        for (int i = 0; i < vc.size(); i++){
            string stra=node->data+vc[i];
            v.push_back(stra);
        }
        return v;
    }
    vector<string> autoComplete(string s){
        return AUTO(s, root->arr[s[0] - 'a']);
    }
};