#include<bits/stdc++.h>
using namespace std;

template <typename T>
class treeNode{
 public:
    T data;
    vector<treeNode*> vect;
    treeNode(int data){
        this->data=data;
    }
};
template <typename T>
treeNode<T>*input(){
    T data; 
    cout<<"enter data : "; cin>>data;
    treeNode<T>*new_node=new treeNode<T>(data);
    int child_count;
    cout<<"no. of childerns of "<<data<<" : "; cin>>child_count;
    for(int i=0;i<child_count;i++){
        new_node->vect.push_back(input<T>());
    }
    return new_node;
}
template <typename T>
treeNode<T>*input_level(){
    T data; 
    cout<<"enter root data : "; cin>>data;
    treeNode<T>*root_node=new treeNode<T>(data);
    queue<treeNode<T>*> q;
    q.push(root_node);
    while(!q.empty()){
        treeNode<T>*front=q.front();
        q.pop();
        int child_count;
        cout<<"~~enter no. of childs of "<<front->data<<" : "; cin>>child_count;
        T child_data[child_count];

        for(int i=0;i<child_count;i++){
            cout<<"   enter "<<i+1<<"th child of "<<front->data<<" : "; cin>>child_data[i];
            treeNode<T>*child_node=new treeNode<T>(child_data[i]);
            q.push(child_node);
            front->vect.push_back(child_node);
        }
    }
    return root_node;
}
template<typename T>
int count_nodes(treeNode<T>*root){
    int sum=0;
    for(int i=0;i<root->vect.size();i++){
        sum+=count_nodes(root->vect[i]);
    }
    return sum+1;
}
template<typename T>
int sum_nodes(treeNode<T>*root){
    int sum=0;
    for(int i=0;i<root->vect.size();i++){
        sum+=sum_nodes(root->vect[i]);
    }
    return sum+root->data;
}
template <typename T>
void print(treeNode<T>*root){
    if(root==NULL) return;
    cout<<root->data<<" : ";
    for(int i=0;i<root->vect.size();i++) cout<<root->vect[i]->data<<",";
    cout<<endl;
    for(int i=0;i<root->vect.size();i++) print(root->vect[i]);
}
template<typename T>
int max_node(treeNode<T>*root){
    int sum=-INFINITY;
    for(int i=0;i<root->vect.size();i++){
        sum=max(sum,max_node(root->vect[i]));
    }
    return max(sum,root->data);
}
template<typename T>
int max_height(treeNode<T>*root){
    if(root==NULL) return 0;
    int sum=0;
    for(int i=0;i<root->vect.size();i++){
        sum=max(sum,max_height(root->vect[i]));
    }
    return sum+1;
}
template<typename T>
void print_at_depth(treeNode<T>*root,int k){
    if(k==0){ cout<<root->data<<" "; return;}
    for(int i=0; i<root->vect.size();i++){
        print_at_depth(root->vect[i],k-1);
    }
}
template<typename T>
int count_leaf_node(treeNode<T>*root){
    if(root==NULL) return 0;
    if(root->vect.size()==0) return 1;
    int sum=0;
    for(int i=0;i<root->vect.size();i++){
        sum+=count_leaf_node(root->vect[i]);
    }
    return sum;
}
template<typename T>
void post_order(treeNode<T>*root){
    if(root==NULL) return ;
    for(int i=0; i<root->vect.size();i++){
        post_order(root->vect[i]);
    }
    cout<<root->data<<" ";
}
template<typename T>
void delete_tree(treeNode<T>*root){
    if(root==NULL) return ;
    for(int i=0; i<root->vect.size();i++){
        post_order(root->vect[i]);
    }
    delete root;
}
template<typename T>
bool contains(treeNode<T>*root,int k){
    if(root==NULL) return false;
    if(root->data==k) return true;
    bool b=0;
    for(int i=0; i<root->vect.size();i++){
        b=max(contains(root->vect[i],k),b);
    }
    return b;
}
template<typename T>
int count_x(treeNode<T>*root,int k){
    int sum=0;
    for(int i=0;i<root->vect.size();i++){
        sum+=count_x(root->vect[i],k);
    }
    return (root->data>k)?sum+1:sum;
}
template<typename T>
int max_sum(treeNode<T>*root,int&saver){
    int sum=root->data;
    for(int i=0;i<root->vect.size();i++){
        sum+=root->vect[i]->data;
    }
    for(int i=0;i<root->vect.size();i++){
        if(max_sum(root->vect[i],saver)>sum){
            sum=max_sum(root->vect[i],saver);
            saver=root->vect[i]->data;
        }
    }
    return sum;
} 
template<typename T>
bool identical(treeNode<T>*root1,treeNode<T>*root2){
    bool b=true;
    b=(root1->data==root2->data);
    b=(root1->vect.size()==root2->vect.size());
    if(b)
    for(int i=0;i<root1->vect.size();i++){
        if(!identical(root1->vect[i],root2->vect[i])) {b=false; return b;}
    }
    return b;
}
template<typename T>
void next_larger(treeNode<T>*root,int x){
    
    queue<treeNode<T>*> q;
    q.push(root);
    while(q.size()!=0){
        treeNode<T>*front=q.front(); 
        if(front->data>x) {cout<<front->data; return;}
        q.pop();
        for(int i=0;i<root->vect.size();i++){
            if(front->vect[i]->data > x) {cout<<front->vect[i]->data; return;}
        }
        for(int i=0;i<root->vect.size();i++){
            q.push(front->vect[i]);
        }
    }
}
int main(){
    treeNode<int>*root=input_level<int>();
    int x; cin>>x;
    next_larger(root,x);
}