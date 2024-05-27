#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Tree
{
public:
    T data;
    vector<Tree *> child;
    Tree(T data)
    {
        this->data = data;
    }
};
    