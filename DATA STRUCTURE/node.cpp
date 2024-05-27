#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
    Node(int data){
        this->data=data;
        next=NULL;
    }
};
class Pair{
    public:
        Node*head;
        Node*tail;
        Pair(){
            head=NULL;
            tail=NULL;
        }
};
class double_Node{
    public:
        int data;
        double_Node*prev;
        double_Node*next;
        double_Node(int data){
            this->data=data;
            prev=NULL;
            next=NULL;
        }
};
