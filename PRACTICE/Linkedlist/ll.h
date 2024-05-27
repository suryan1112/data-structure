#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data=data;
        this->next=NULL;
    }
    // ~Node(){
    //     if(Node==NULL) return;
    //     delete Node->next;
    // }
};

