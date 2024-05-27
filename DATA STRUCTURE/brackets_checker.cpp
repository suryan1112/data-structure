#include<iostream>
using namespace std;
#include<stack>
// #include "node.cpp"
template <typename T>
class Node{
    public:
    T data;
    Node*next;
    Node(T data){
        this->data=data;
        next=NULL;
    }
};
// double_Node*double_input(){
//     int data; cin>>data;
//     double_Node*head=NULL;
//     double_Node*temp=NULL;
//     while(data!=-1){
//         double_Node*node=new double_Node(data);
//         if(head==NULL){
//             head=node;
//             temp=node;
//         }else{
//             temp->next=node;
//             node->prev=temp;
//             temp=node;
//         }cin>>data;
//     }
//     temp->next=head;
//     head->prev=temp;
//     return head;
// }
// void print(double_Node*head){
//     double_Node*tail=head;
//     cout<<tail->data<<" ";
//     tail=tail->next;
//     while(tail!=head){
//         cout<<tail->data<<" ";
//         tail=tail->next;
//     }cout<<endl;
// }
template <typename T>
class stack_ll{
    Node<T>*head;
    int count_nodes;
    public:
        stack_ll(){
            head=NULL;
            count_nodes=0;
        }
        int size(){return count_nodes;}
        bool isEmpty(){ return count_nodes=0;}

        void push(T data){
            Node<T>*node=new Node<T>(data);
            node->next=head;
            head=node;
            count_nodes++;
        }
        T pop(){
            if(isEmpty()){ cout<<"stack is empty ";}
            else
            {T data=head->data;
            head=head->next;
            return data;
            count_nodes--;}
        }
        T top(){
            if(isEmpty()){ cout<<"stack is empty ";}
            else return head->data;
        }
};
int main(){
    string s; cin>>s;
    stack<char> stc;
    for(int i=0;i<s.size();i++){
        if(s[i]=='{' || s[i]=='[' || s[i]=='(') stc.push(s[i]);

        if(s[i]==')'){
            if(stc.top()==s[i]-1) stc.pop();
            else {cout<<"false"; break;}
        }
        if(s[i]=='}' || s[i]==']'){
            if(stc.top()==s[i]-2) stc.pop();
            else {cout<<"false"; break;}
        }
        if(i==s.size()-1){
            if(stc.empty()) cout<<"true";
            else cout<<"false"; 
        }
    }
}//64+{23*36[20/(30-12)]}