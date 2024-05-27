#include<bits/stdc++.h>
using namespace std;

class MIN_Heap{
    public:
    vector<int> heap;
    public:
    bool isEmpty(){
        return heap.size()==0;
    }
    int size(){
        return heap.size();
    }
    void bottom_up_heapify(){
        int childINDEX=heap.size()-1;
        while (childINDEX>0)
        {
            int parentINDEX=(childINDEX-1)/2;
            if(heap[parentINDEX]>heap[childINDEX]){
                int temp=heap[parentINDEX];
                heap[parentINDEX]=heap[childINDEX];
                heap[childINDEX]=temp;
            }
            else return;
            childINDEX=parentINDEX;
        }
    }
    void top_down_heapify(){
        int parentINDEX=0;
        while(parentINDEX<(heap.size()-1)/2){
            child1INDEX=parentINDEX*2+1;
            child2INDEX=parentINDEX*2+2;
            
            if(heap[child1INDEX]<heap[parentINDEX] && heap[child1INDEX]<heap[child2INDEX]){
                int temp=heap[parentINDEX];
                heap[parentINDEX]=heap[child1INDEX];
                heap[child1INDEX]=temp;
                parentINDEX=child1INDEX;
            }
            else if(heap[child2INDEX]<heap[parentINDEX]){
               int temp=heap[parentINDEX];
                heap[parentINDEX]=heap[child2INDEX];
                heap[child2INDEX]=temp; 
                parentINDEX=child2INDEX;
            }
            else return;
        }
    }
    void insert(int data){
        heap.push_back(data);
        this.up_heapify();
    }
    int get_min(){
        if(isEmpty()) return -1;
        return heap[0];
    }
    int remove_min(){
        if(isEmpty()) return -1;
        int saved=heap[0];
        heap[0]=heap[heap.size()-1];
        heap.pop_back();
        top_down_heapify();
        return saved;
    }
};


class MAX_Heap{
    public:
    vector<int> heap;
    public:
    bool isEmpty(){
        return heap.size()==0;
    }
    int size(){
        return heap.size();
    }
    void insert(int data){
        heap.push_back(data);

        int child_index=heap.size()-1;
        while(child_index){
        int parent_index=(child_index-1)/2;
        
        if(heap[parent_index]<heap[child_index]){
            int temp=heap[parent_index];
            heap[parent_index]=heap[child_index];
            heap[child_index]=temp;
        }
        else return;
        child_index=parent_index;}
    }
    int get_max(){
        if(isEmpty()) return -1;
        return heap[0];
    }
    int remove_max(){
        if(isEmpty()) return -1;
        int saver=heap[0];
        heap[0]=heap[heap.size()-1];
        heap.pop_back();
        if(size()<=1) return saver;
        // heap[heap.size()-1]=saver;
        int parent_index=0;
        while(parent_index <= (heap.size()-2)/2){
        int child1=parent_index*2+1;
        int child2=parent_index*2+2;
        if(heap[parent_index]>=heap[child1] && child2<heap.size() && heap[parent_index]>=heap[child2]) 
            return saver;
        else if(heap[parent_index]<heap[child2] && child2<heap.size() && heap[child2]>heap[child1]){
            int temp=heap[parent_index];
            heap[parent_index]=heap[child2];
            heap[child2]=temp;
            parent_index=child2;
        }
        else if(heap[parent_index]<heap[child1] || (child2<heap.size() && heap[child1]>heap[child2])){
            int temp=heap[parent_index];
            heap[parent_index]=heap[child1];
            heap[child1]=temp;
            parent_index=child1;
        }
        else parent_index=child1;  //heap.size()-1;
        }
        // heap.pop_back();
        return saver;
    }
};
void k_sorted(int a[],int n,int k){
    priority_queue<int> q;
    for(int i=0;i<k;i++) q.push(a[i]);
    for(int i=0;i<n;i++){
        a[i]=q.top();
        q.pop();
        if(i+k<n) q.push(a[i+k]);
    }
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
}
priority_queue<int> k_smallest(int a[],int n,int k){
    priority_queue<int> q;
    for(int i=0;i<k;i++) q.push(a[i]);
    for(int i=k;i<n;i++){
        if(q.top()>a[i]){
            q.pop();
            q.push(a[i]);
        }
    }
    return q;
}
priority_queue<int,vector<int>,greater<int>> k_largest(int a[],int n,int k){
    priority_queue<int,vector<int>,greater<int>> q;
    for(int i=0;i<k;i++) q.push(a[i]);
    for(int i=k;i<n;i++){
        if(q.top()<a[i]){
            q.pop();
            q.push(a[i]);
        }
    }
    return q;
}
void median(int a[],int n){
    priority_queue<int,vector<int>,greater<int>> second;
    priority_queue<int> first;
    second.push(1000);
    first.push(0);
    for(int i=0;i<n;i++){
        
        if(first.size()==second.size()){
            if(a[i]>second.top()){
                second.push(a[i]);
                cout<<second.top()<<endl;
            }
            else if(a[i]<first.top()){
                first.push(a[i]);
                cout<<first.top()<<endl;
            }
            else {
                second.push(a[i]);
                cout<<second.top()<<endl;
            }
        }
        else if(first.size()<second.size()){
            if(a[i]>second.top()){
                second.push(a[i]);
                first.push(second.top());
                second.pop();
                cout<<(first.top()+second.top())/2<<endl;
            }
            else if(a[i]<first.top()){
                first.push(a[i]);
                cout<<(first.top()+second.top())/2<<endl;
            }
            else {
                first.push(a[i]);
                cout<<(first.top()+second.top())/2<<endl;
            }
        }
        else if(first.size()>second.size()){
            if(a[i]>second.top()){
                second.push(a[i]);
                cout<<(first.top()+second.top())/2<<endl;
            }
            else if(a[i]<first.top()){
                first.push(a[i]);
                second.push(first.top());
                first.pop();
                cout<<(first.top()+second.top())/2<<endl;
            }
            else {
                second.push(a[i]);
                cout<<(first.top()+second.top())/2<<endl;
            }
        }
    }
}
int main(){
    int n; cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    MIN_Heap heap=a;
}