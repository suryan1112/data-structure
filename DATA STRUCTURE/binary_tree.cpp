#include<bits/stdc++.h>
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
class treeBinary{
    public:
        int data; 
        treeBinary*left;
        treeBinary*right;
        treeBinary(int data){
            this->data=data;
            left=NULL;
            right=NULL;
        }
        ~treeBinary(){
            delete left;
            delete right;
        }
};
treeBinary*input(){
    int data; 
    cin>>data;
    if(data==-1) return NULL;
    treeBinary*root=new treeBinary(data);
    root->left=input();
    root->right=input();
    return root;
}
treeBinary*input_level(){
    int data;
    cout<<"enter root : "; cin>>data;
    if(data==-1) return NULL;
    treeBinary*root=new treeBinary(data);
    queue<treeBinary*> q;
    q.push(root);
    
    while(!q.empty()){
        treeBinary*front=q.front();
        q.pop();
        cout<<"enter left child of "<<front->data<<" : ";
        cin>>data; if(data!=-1){
        treeBinary*left_node=new treeBinary(data);
        front->left=left_node;
        q.push(left_node);}

        cout<<"enter right child of "<<front->data<<" : ";
        cin>>data; if(data!=-1){
        treeBinary*right_node=new treeBinary(data);
        front->right=right_node;
        q.push(right_node);}

    }
    return root;
}
void print(treeBinary*root){
    if(!root) return;
    cout<<endl<<root->data<<" : ";
    if(root->left) cout<<"L"<<root->left->data<<" ";
    if(root->right) cout<<"R"<<root->right->data;
    print(root->left);
    print(root->right);
}
int count_nodes(treeBinary*root){
    if(!root) return 0;
    return count_nodes(root->left)+count_nodes(root->right)+1;
}
int height_nodes(treeBinary*root){
    if(!root) return 0;
    return max(height_nodes(root->left),height_nodes(root->right))+1;
}
treeBinary*mirror_image(treeBinary*root){
    if(!root) return root;
    treeBinary*saver=root->left;
    root->left=mirror_image(root->right);
    root->right=mirror_image(saver);
    return root;
}

void preorder(treeBinary*root){
    if(!root) return;
    
    preorder(root->left);
    preorder(root->right);
    cout<<root->data<<" ";
}
treeBinary*pre_inorder(int pre[],int in[],int pre_first,int pre_last, int in_first,int in_last){
    if(pre_first>=pre_last && in_first>=in_last) return NULL;

    treeBinary*root=new treeBinary(pre[pre_first]);
     int a=in_first;
    for(int i=in_first;i<=in_last;i++) 
        if(pre[pre_first]==in[i]) {a=i; break;}
    root->left=pre_inorder(pre,in,pre_first+1,pre_first+a,in_first,a-1);
    root->right=pre_inorder(pre,in,pre_first+a+1,pre_last,a+1,in_last);
    return root;
}
int diameter(treeBinary*root){
    if(!root) return 0;
    int leftheight=height_nodes(root->left);
    int rightheight=height_nodes(root->right);
    int dim=leftheight+rightheight;
    return max(max(diameter(root->left),diameter(root->right)),dim);
}
void min_max(treeBinary*root,int&minimum,int&maximum){
    if(!root) return;
    maximum=max(maximum,root->data);
    minimum=min(minimum,root->data);
    min_max(root->left,minimum,maximum);
    min_max(root->right,minimum,maximum);
}
int sum(treeBinary*root){
    if(!root) return 0;
    return sum(root->left)+sum(root->right)+root->data;
}
bool balance(treeBinary*root){
    if(!root) return true;
    
    if(abs(height_nodes(root->left)-height_nodes(root->right))>1) return false;
    bool b=true;
    b=balance(root->left);
    b=balance(root->right);
    return b;
}
void level_traversal(treeBinary*root){
    if(!root) return ;
    queue<treeBinary*> q;
    q.push(root);
    q.push(NULL);
    while(q.size()!=1 || q.front()){
        if(q.front()){
        treeBinary* front=q.front();
        cout<<front->data<<" ";
        q.pop();
        if(front->left) q.push(front->left);
        if(front->right) q.push(front->right);
        }
        else{
            q.pop();
            q.push(NULL);
            cout<<endl;
        }
    }
}
void ll_traversal(treeBinary*root,vector<Node*>&v){//zig-zag-traversal
    if(!root) return ;
    queue<treeBinary*> q;
    q.push(root);
    q.push(NULL);
    int i=1;
    Node*head=NULL,*tail=NULL;
    while(q.size()!=1 || q.front()){
        if(q.front()){
        treeBinary* front=q.front();
        Node*new_node=new Node(front->data);
        if(head==NULL) {
            head=new_node; 
            tail=new_node;
            v.push_back(head);
        }
        else if(i%2!=0){tail->next=new_node; tail=tail->next;}
        else if(i%2==0){
            new_node->next=head;
            head=new_node;
            v.pop_back();v.push_back(head);
        }
        q.pop();
        if(front->left) q.push(front->left);
        if(front->right) q.push(front->right);
        }
        else{
            i++;
            q.pop();
            head=NULL; tail=NULL;
            q.push(NULL);
        }
    }
}
treeBinary* delete_leafNode(treeBinary*root){
    if(!root) return NULL;
    if(!root->left && !root->right) return NULL;
    root->left=delete_leafNode(root->left);
    root->right=delete_leafNode(root->right);
    return root;
}

void no_sibling(treeBinary*root){
    if(!root) return;
    if(root->left && !root->right) cout<<root->left->data<<" ";
    if(!root->left && root->right) cout<<root->right->data<<" ";
    no_sibling(root->left);
    no_sibling(root->right);
    
}

void print_kk(treeBinary*root,int k1,int k2){
    if(!root) return;
    if(root->data < k1){
        print_kk(root->right,k1,k2);
    }
    else if(root->data > k2){
        print_kk(root->left,k1,k2);
    }
    else{
        treeBinary*left_node=root;
        treeBinary*right_node=root;
        while(left_node->left->data >=k1) left_node=left_node->left;
        left_node->left=NULL;
        while(right_node->right->data <=k2) right_node=right_node->right;
        right_node->right=NULL;
        print(root);
    }
}
int max_node(treeBinary*root){
    if(!root) return INT_MIN;
    return max(root->data,max(max_node(root->left),max_node(root->right)));
} 
int min_node(treeBinary*root){
    if(!root) return INT_MAX;
    return min(root->data,min(min_node(root->left),min_node(root->right)));
} 
bool check_BST(treeBinary*root){
    if(root==NULL) return true;
    bool b=true;
    if(root->left)
        b=max_node(root->left)<root->data && check_BST(root->left);
    if(root->right)
        b=min_node(root->right)<root->data && check_BST(root->right);
    return b;
}
bool check_BST2(treeBinary*root,int minimum,int maximum){
    if(root==NULL) return true;
    
    return (minimum<=root->data) && (root->data<maximum) && check_BST2(root->left,minimum,root->data) && check_BST2(root->right,root->data,maximum);
}
treeBinary*construct_BST(int arr[],int start,int end){
    if(start > end) return NULL;
    int mid=(start+end)/2;
    treeBinary*root=new treeBinary(arr[mid]);
    root->left=construct_BST(arr,start,mid-1);
    root->right=construct_BST(arr,mid+1,end);
    return root;
}

void add_ll(treeBinary*root,Node*head,Node*tail){
    if(root==NULL) return;
    add_ll(root->left,head,tail);
    if(head==NULL){
        cout<<"fucking";
        Node*new_node=new Node(root->data);
        head=new_node; tail=new_node;
    }
    else{
        Node*new_node=new Node(root->data);
        tail->next=new_node;
        tail=new_node;
    }
    add_ll(root->right,head,tail);
}
Node*create_ll(treeBinary*root){
    if(!root) return NULL;
    Node*head;
    Node*temp;
    if(root->left){ 
    head=create_ll(root->left);
    temp=head;
    while(temp->next) temp=temp->next;}

    Node*root_node=new Node(root->data);
    if(root->left) temp->next=root_node;
    else head=root_node;
    root_node->next=create_ll(root->right);
    return head;
}
Node*create_ll2(treeBinary*root){
    if(!root) return NULL;

    Node*head=create_ll2(root->left);
    Node*temp=head;
    while(temp->next) temp=temp->next;

    Node*root_node=new Node(root->data);
    temp->next=root_node;
    root_node->next=create_ll2(root->right);

    return head;
}

void path(treeBinary*root,vector<int>&v,int x){
    if(root==NULL) return;
    if(root->data==x) v.push_back(x);

    path(root->left,v,x);
    path(root->right,v,x);

    if (root->left && root->left->data == v[v.size() - 1])
        v.push_back(root->data);
    else if (root->right && root->right->data == v[v.size() - 1])
        v.push_back(root->data);
}
class BST{
    public:
    treeBinary*root;
    bool is_present(treeBinary*root,int x){
        if(root==NULL) return false;
        if(root->data==x) return true;
        else if(root->data<x) return is_present(root->right,x);
        else return is_present(root->right,x);
    }
    treeBinary*insert_private(treeBinary*node,int data){
        if(node==NULL){
            treeBinary*new_Node=new treeBinary(data);
            return new_Node;
        }
        if(data< node->data){
            node->left=insert_private(node->left,data);
            return node;
        }
        else{
            node->right=insert_private(node->right,data);
            return node;
        }
    }
    void print_private(treeBinary*node){
        if(node==NULL) return;
        cout<<node->data<<": ";
        if(node->left) cout<<"L"<<node->left->data;
        if(node->right) cout<<" R"<<node->right->data;
        cout<<endl;
        print_private(node->left);
        print_private(node->right);
    }
    treeBinary*delete_private(treeBinary*node,int data){
        if(node==NULL) return NULL;
        if(data<node->data){
            node->left=delete_private(node->left,data);
        }
        else if(data > node->data){
            node->right=delete_private(node->right,data);
        }
        else{
            if(node->right==NULL && node->left==NULL){
                delete node; 
                return NULL;
            }
            else if(node->right==NULL){
                treeBinary*left_root=node->left;
                node->left=NULL;
                delete node;
                return left_root;
            }
            else if(node->left==NULL){
                treeBinary*right_root=node->right;
                node->right=NULL;
                delete node;
                return right_root;
            }
            else{
                treeBinary*temp=node->right;
                while(temp->left!=NULL){
                    temp=temp->left;
                }
                node->data=temp->data;
                delete_private(node->right,temp->data);
                return node;
            }
        }
    }
    public:
    // BST(treeBinary*root){
    //     this->root=root;
    // }
    ~BST(){
        delete root;
    }
    bool isPresent(int x){
        return is_present(root,x);
    }
    void insert(int data){
        root=insert_private(root,data);
    }
    void deleter(int data){
        root=delete_private(root,data);
    }
    void print_tree(){
        print_private(root);
    }
};
void duplicate(treeBinary*root){
    if(root==NULL ) return;
    treeBinary*root_copy=new treeBinary(root->data);
    root_copy->left=root->left;
    root->left=root_copy;
    duplicate(root_copy->left);
    duplicate(root->right);
}
bool binary_search(treeBinary*root,int x){
    if(root==NULL) return false;
    if(root->data==x) return true;
    else if(root->data > x) return binary_search(root->left,x);
    else return binary_search(root->right,x);
}
bool searching(treeBinary*root,int x){
    if(root==NULL) return false;

    if(root->data==x) return true;
    if(searching(root->left,x)) return true;
    if(searching(root->right,x)) return true;
    return false;
}
void sum_pairs(treeBinary*root, int sum){
    if(root==NULL) return ;
    sum_pairs(root->left,sum);
    sum_pairs(root->right,sum);

    if(searching(root,sum-root->data)){
        cout<<root->data<<" "<<sum-root->data<<endl;
        root->data=INT_MAX;
    }
}
bool LCA(treeBinary*root,int x,int y){
    if(root==NULL) return false;
    bool b=false;
    if(LCA(root->left,x,y)) b=true;
    if(LCA(root->right,x,y))b=true;
    if(!b && searching(root,x) && searching(root,y)){
        cout<<root->data;
        return true;
    }
    return b;
}
void find_lca(treeBinary*root,int x,int y){
    if(searching(root,x) && searching(root,y)) LCA(root,x,y);
    else if(searching(root,x) || searching(root,y)){
        if(searching(root,x)) cout<<x;
        else cout<<y;
    }
    else cout<<-1;
}
bool isValidBST(treeBinary* root) {
        if(root) return true;
        
        if(root->left && root->left->data >= root->data) return false;
        else if(root->right && root->right->data < root->data) return false;
        
        if(!isValidBST(root->left)) return false;
        if(!isValidBST(root->right)) return false;
        
        return true;
    }
treeBinary* left_shift(treeBinary*root){
    if(root==NULL) return NULL;
   treeBinary*node=new treeBinary(root->data);
   node->left=left_shift(root->left);
   root->left=node;
   root->right=left_shift(root->right);
   return root; 
}
void print_level(treeBinary*root){
    if(root==NULL) return; 
    queue<treeBinary*> q;
    q.push(root);
    q.push(NULL);
    while(q.size()!=1 || q.front()){
        treeBinary*temp=q.front();
        q.pop();
        if(temp==NULL){
            cout<<endl;
            q.push(NULL);
            continue;
        }
        cout<<temp->data<<" ";
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
}
void maxbst(treeBinary*root,int&maxi){
    if(check_BST(root)) {maxi=max(maxi,height_nodes(root)); return;}
    if(height_nodes(root->left)>maxi) maxbst(root->left,maxi);
    if(height_nodes(root->right)>maxi) maxbst(root->right,maxi);
}
void replace(treeBinary*root,int&sum){
    if(root==NULL) return;
    replace(root->right,sum);
    root->data+=sum;
    sum=root->data;
    replace(root->left,sum);
}
void path_sum(treeBinary*root,int&sum,vector<int>&v,int k){
    if(root==NULL) return;
    sum+=root->data;
    v.push_back(root->data);
   
     if(sum==k && !root->left && !root->right){ 
        for(auto x:v) cout<<x<<" ";
        cout<<endl;}

    path_sum(root->left,sum,v,k);
    path_sum(root->right,sum,v,k);

    sum-=root->data;
    v.pop_back();
}
void path2(treeBinary*root,vector<int>&v,int target){
    
    if(root==NULL) return;
    if(v.size() && v[v.size()-1]==target) return;

    if(v.size() && v[v.size()-1]!=target){
        v.push_back(root->data);
    }
    if(v.size()==0) 
        v.push_back(root->data);

    path2(root->left,v,target);
    path2(root->right,v,target);
    
    if(v.size() && v[v.size()-1]!=target){
        v.pop_back();
    }
}
void kth_node(treeBinary*root,int k){
    if(k<1) return;
    if(k==1) {cout<<root->data<<endl; return;}
    kth_node(root->left,k-1);
    kth_node(root->right,k-1);
}
void traverse(treeBinary*root,vector<int>&v,int k){
    if(root==NULL) return;
    traverse(root->left,v,k);
    traverse(root->right,v,k);

    for(int i=0;i<v.size();i++){
        if(root->data==v[i]){
            if(i==0) kth_node(root,k+1-i);
            else if(root->right->data==v[i-1]) kth_node(root->left,k+1-i);
            else if(root->left->data==v[i-1]) kth_node(root->right,k+1-i);
        }
    }
}
bool cousin(treeBinary*root,int data1,int data2){
    if(root==NULL) return false;
    queue<treeBinary*> q;
    q.push(root);
    q.push(NULL);
    bool d1=false,d2=false;
    while(q.size()!=1 || q.front()){
        treeBinary*temp=q.front();
        q.pop();
        if(!temp){
            if(d1 && d2) return true;
            else if(d1 || d2) return false ;
            q.push(NULL);
            continue;
            d1=false;
            d2=false;
        }
        
        if(temp->data==data1){
            d1=true;
            if(q.front() && q.front()->data==data2) return false;
        }
        else if(temp->data==data2) d2=true; 
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
}
void lefroot(treeBinary*root){
    if(root==NULL) return;
    if(height_nodes(root->left)>height_nodes(root->right)) lefroot(root->left);
    else lefroot(root->right);
    cout<<root->data<<endl;
}
int main(){
     treeBinary*root=input_level();
    //  int data1,data2; cin>>data1>>data2;
    //  cout<<cousin(root,data1,data2);
    lefroot(root);
    //  vector<int> v;
    //  int target; cin>>target;
    //  int k; cin>>k;
    //  path2(root,v,target);
    //  for(auto x: v) cout<<x<<" ";
    //  vector<int> v2;
    //  for(int i=v.size()-1;i>=0;i--) v2.push_back(v[i]);
    //  for(auto x: v2) cout<<x<<" ";
    //  traverse(root,v2,k);

}
//5 2 10 0 1 -1 15 -1 -1 -1 -1 -1 -1
