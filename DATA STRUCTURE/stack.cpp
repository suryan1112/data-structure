#include<iostream>
using namespace std;
#include<stack>
#include<queue>

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
template <typename T>
class stack_arrey{
    T*arr;
    int capacity;
    int next_index;
    public:
        stack(){
            arr=new int[1];
            capacity=1;
            next_index=0;
        }
        int size(){return next_index;}
        bool isEmpty(){return next_index==0;}

        void push(T data){
            if(next_index==capacity){
                T*arr2=new T[2*capacity];
                for(int i=0;i<capacity;i++) arr2[i]=arr[i];
                arr=arr2;
                capacity*=2;
            }
            arr[next_index++]=data;
            // next_index++;
        }
        T pop(){
            if(next_index==0){ cout<<"stack is empty ";}
            else
            {if(next_index < capacity/2){
                T*arr2=new T[capacity/2];
                for(int i=0;i<capacity/2;i++) arr2[i]=arr[i];
                arr=arr2;
                capacity/=2;
            }
            // --next_index;
             return arr[--next_index];}
        }
        T top(){
            if(next_index==0){ cout<<"stack is empty ";}
            else return arr[next_index-1];
        }
};
class queue_arrey{
    int*arr;
    int capacity;
    int count;
    int first_index;
    int last_index;
    public:
        queue_arrey(){
            arr=new int[1];
            capacity=1;
            first_index=-1;
            last_index=0;
            count=0;
        }
        int size(){return count;}
        bool isEmpty() {return count==0;}

        void push(int data){
            if(first_index==last_index){
                int*arr2=new int[2*capacity];
                for(int i=first_index,j=0;i!=last_index,j<capacity;j++) 
                    {arr2[j]=arr[i]; i=(i+1)%capacity;}
                arr=arr2;
                first_index=0; last_index=capacity;
                capacity*=2;
            }
            if(first_index==-1) first_index++;
            arr[last_index]=data;count++;
            last_index=(last_index+1)%capacity;
        }
        int pop(){
            if(isEmpty()){ cout<<"queue is empty"; return -1;}
            if(size()<=capacity/2){
                capacity/=2;
                int*arr2=new int[capacity];
                for(int i=first_index,j=0;i!=last_index,j<capacity;j++) 
                    {arr2[j]=arr[i]; i=(i+1)%capacity;}
                arr=arr2;
                first_index=0; last_index=capacity;
            }
            int a=arr[first_index];
            first_index=(first_index+1)%capacity;count--;
            return a;
        }
        int top(){
            if(isEmpty()) {cout<<"queue is empty"; return -1;}
            return arr[first_index];
        }
};
template <typename T>
class queue_ll{
    Node<T>*head;
    Node<T>*tail;
    int count;
    public:
        queue_ll(){
            head=NULL;
            count=0;
        }
        int size() {return count;}
        bool isEmpty() {return count==0;}

        void push(T data){
            Node<T>*new_node=new Node<T>(data);
            if(head==NULL){
                head=new_node;
                tail=new_node;
            }
            else{
                tail->next=new_node;
                tail=new_node;
            } 
            count++;
        }
        T pop(){
            if(isEmpty()) cout<<"queue is empty";
            else{
                T a=head->data;
                head=head->next;
                return a; count--;
            }
        }
        T top(){
            if(isEmpty()) cout<<"queue is empty";
            else
                return head->data;
        }
};

void reverse_queue(queue<int>&q){
    if(q.empty()) return;
    int data=q.front();
    q.pop();
    reverse_queue(q);
    cout<<data<<" ";
    q.push(data);
}
int main(){
    stack<char> q;
    string s; cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]==')'){
            int count=0;
            while(q.top()!='(') {q.pop();count++;}
            if(count<=1) {cout<<"true";break;}
            q.pop(); 
        }
        else q.push(s[i]);
        if(i==s.size()-1) cout<<"false";
    }
}