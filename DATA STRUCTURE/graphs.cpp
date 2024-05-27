#include<bits/stdc++.h>
using namespace std;

void print_DFS(bool**a,int n,int sv,unordered_map<int,bool>&m){
    cout<<sv<<" "; m[sv];
    for(int i=0;i<n;i++){
        if(a[sv][i] && !m.count(i)){
            print_DFS(a,n,i,m);
        }
    }
}
void print_BFS(bool**a,int n,int sv,unordered_map<int,bool>&m){
    queue<int> q;
    q.push(sv); m[sv];
    q.push(-1);
    while(q.size()!=1 || q.front()!=-1){
        int temp=q.front();
        q.pop();
        if(temp==-1){
            // cout<<endl;
            q.push(-1);
            continue;
        }
        cout<<temp<<" ";
        for(int i=0;i<n;i++) 
            if(a[temp][i] && !m.count(i)){
                m[i];
                q.push(i);
            }
    }
}
void DFS(bool**a,int n){
    unordered_map<int,bool> m;
    // print_BFS(a,n,i,m);
    for(int i=0;i<n;i++){

        if(!m.count(i)) print_DFS(a,n,i,m); 
    }
}
void BFS(bool**a,int n){
    unordered_map<int,bool> m;
    // print_BFS(a,n,i,m);
    for(int i=0;i<n;i++){
        if(!m.count(i)) print_BFS(a,n,i,m); 
    }
}
bool has_path(bool**a,int n,int sv,int target,unordered_map<int,bool>&m){
    if(sv==target) return true;
     m[sv];
    for(int i=0;i<n;i++){
        if(a[sv][i] && !m.count(i)){
            if(has_path(a,n,i,target,m)) return true;
        }
        if(i==n-1) return false;
    }
}
void print_path_DFS(bool**a,int n,int sv,int target,unordered_map<int,bool>&m){
    if(!has_path(a,n,sv,target,m)) return;
    cout<<sv<<" "; m[sv];
    if(sv==target) return;
    for(int i=0;i<n;i++){
        if(a[sv][i] && !m.count(i)){
            print_path_DFS(a,n,i,target,m);
        }
    }
}
void print_path_BFS(bool**a,int n,int sv,int target,unordered_map<int,bool>&m){ //shortest
    if(!has_path(a,n,sv,target,m)) return;
    unordered_map<int,int> m2;
    queue<int> q;
    stack<int> stc;
    q.push(sv); m[sv];
    bool b=true;
    while(q.size() && b){
        int temp=q.front();
        q.pop();
        for(int i=0;i<n;i++) 
            if(a[temp][i] && !m.count(i)){
                m[i];
                m2[i]=temp;
                int x=i;
                if(i==target){
                    stc.push(target);
                    while(m2.count(x)){
                        stc.push(m2[x]);
                        x=m2[x];
                    }b=false;
                }
                q.push(i);
            }
    }
    while(stc.size()){
        cout<<stc.top()<<" ";
        stc.pop();
    }
}
vector<int> saver(bool**a,int n,int sv,unordered_map<int,bool>&m){
    queue<int> q;
    q.push(sv); m[sv];
    vector<int> v;
    while(q.size()){
        int temp=q.front();
        q.pop();
        v.push_back(temp);
        for(int i=0;i<n;i++) 
            if(a[temp][i] && !m.count(i)){
                m[i];
                q.push(i);
            }
    }return v;
}
vector<vector<int>> connected_pairs(bool**a,int n){
    vector<vector<int>> v;
    unordered_map<int,bool> m;
    for(int i=0;i<n;i++){
        if(!m.count(i)) v.push_back(saver(a,n,i,m)); 
    }
    return v;
}
int island(bool**a,int n){
    vector<vector<int>> v=connected_pairs(a,n);
    return v.size();
}
void triangle(bool** matrix,int sv,unordered_map<int,int>&m,unordered_map<int,int>&m2,int n,int t,int&count){
    m[sv]; m2[sv]=t;
    for(int i=0;i<n;i++){
        if(matrix[sv][i] && m.count(i) && m2[sv]-m2[i]==2) count++;
        if(matrix[sv][i] && !m.count(i)) triangle(matrix,i,m,m2,n,t+1,count); 
    }
}
int traversal(bool**matrix,int n){
    if(n<2) return 0; 
    unordered_map<int,int> m;
    unordered_map<int,int> m2;
    int count=0;
    for(int i=0;i<n;i++){
        if(!m.count(i)){
            triangle(matrix,i,m,m2,n,0,count);
        }
    }return count;
}
int main(){
    int n; cin>>n;
    bool**a=new bool*[n];
    for(int i=0;i<n;i++){
        a[i]=new bool[n];
        for(int j=0;j<n;j++)
            a[i][j]=false;
    }
    int edges; cin>>edges;
    while(edges--){
        int f,s; cin>>f>>s;
        a[f][s]=true;
        a[s][f]=true;
    }
    unordered_map<int,bool> m;
    cout<<traversal(a,n)<<endl;
    
}