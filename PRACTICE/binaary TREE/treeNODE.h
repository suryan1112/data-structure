#include<bits/stdc++.h>
using namespace std;

template<typename T>
class BtreeNODE{
    public:
    T data;
    BtreeNODE* left;
    BtreeNODE* right;

    BtreeNODE(T data){
        this->data=data;
        left=NULL; right=NULL;
    }
    ~BtreeNODE(){
        delete left;
        delete right;
    }
};