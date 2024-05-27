#include<bits/stdc++.h>
using namespace std;

template<typename V>
class Node{
    public:
    string key;
    V value;
    Node*next;
    Node(string key,V value){
        this->key=key;
        this->value=value;
        next=NULL;
    }
    ~Node(){
        delete next;
    }
};
template<typename V>
class Hash_map{
    Node<V>**arr;
    int size_arr;
    int count_nodes;
  //hash function---
    int get_index(string key){
        int count=0;
        for(int i=0;i<key.size();i++){
            int prd=1,k=i;
            while(k--) prd=prd*31%size_arr;
            count=count+(key[i]-'a'+1)*prd;
        }
        return count%size_arr;
    }
    void expand(){
        Node<V>**arr2=arr;
        size_arr*=2;
        arr= new Node<V>*[size_arr];
        for(int i=0;i<size_arr;i++) arr[i]=NULL;
        count_nodes=0;
        for(int i=0;i<size_arr/2;i++){                                                                                                                
            Node<V>*head=arr2[i];
            while(head){
                insert(head->key,head->value);
                head=head->next;
            }
        }
        delete arr2;
    }
    public:
    
    Hash_map(){
        size_arr=5;
        arr=new Node<V>*[size_arr];
        count_nodes=0;
        for(int i=0;i<size_arr;i++) arr[i]=NULL;
    }
    ~Hash_map(){
        for(int i=0;i<size_arr;i++) delete arr[i];
    }
    void insert(string key,V value){
        int index=get_index(key);
        Node<V>*head=arr[index];
        while(head!=NULL){
            if(head->key==key){
                head->value=value;
                return;
            }
            head=head->next;
        }
        Node<V>* new_node=new Node<V>(key,value);
        head=arr[index];
        new_node->next=head;
        arr[index]=new_node;
        count_nodes++;
        // if((1.0*count_nodes)/size_arr >0.7) expand();
    }
    V search(string key){
        int index=get_index(key);
        Node<V>*head=arr[index];
        while(head!=NULL){
            if(head->key==key){
                return head->value;
            }
            head=head->next;
        }
        return -1;
    }
    V remove(string key){
        int index=get_index(key);
        Node<V>*head=arr[index];
        Node<V>*prev=NULL;
        while(head!=NULL){
            if(head->key==key){
                V value=head->value;
                Node<V>*saver=head->next;
                head->next=NULL;
                delete head;
                arr[index]=saver;
                return value;
            }
            else if(head->next->key==key){
                V value=head->next->value;
                Node<V>*saver=head->next->next;
                head->next->next=NULL;
                delete head->next;
                head->next=saver;
                return value;
            }
            head=head->next;
        }
        return -1;
    }
};
int main(){
    Hash_map<int> h1;
    h1.insert("abc",10);
    h1.insert("def",20);
    h1.insert("ghi",30);
    h1.insert("jkl",40);
    h1.insert("mno",50);
    
    cout<<h1.search("jkl")<<" "<<h1.search("def")<<endl;
    h1.remove("jkl");
    cout<<" "<<h1.search("jkl")<<endl;
    
    cout<<h1.remove("abc")<<" "<<h1.search("abc");
    cout<<h1.search("abc");
}