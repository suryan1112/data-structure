#include <bits/stdc++.h>
#include "treestrct.h"
using namespace std;
#include <queue>

Tree<int> *takeInput()
{
    int data;
    cin >> data;
    Tree<int> *root = new Tree<int>(data);

    queue<Tree<int> *> q;
    q.push(root);
    while (q.size())
    {
        Tree<int> *node = q.front();
        q.pop();

        int size;
        cout << "enter size of " << node->data << ":";
        cin >> size;
        if (size)
            cout << "enter childeren of " << node->data << " : ";
        for (int i = 0; i < size; i++)
        {
            cin >> data;
            Tree<int> *child = new Tree<int>(data);
            q.push(child);
            node->child.push_back(child);
        }
    }
    return root;
}
void print_tree(Tree<int> *root)
{
    queue<Tree<int> *> q;
    q.push(root);
    int train = 1;
    while (q.size())
    {
        int train2 = 0;
        for (int j = 0; j < train; j++)
        {
            Tree<int> *node = q.front();
            q.pop();
            cout << node->data << " ";
            int size = node->child.size();
            train2 += size;
            for (int i = 0; i < size; i++)
                q.push(node->child[i]);
        }
        train = train2;
        cout << endl;
    }
}
int num_nodes(Tree<int> *root)
{
    if (root == NULL)
        return 0;

    int sum = 0;
    for (int i = 0; i < root->child.size(); i++)
        sum += num_nodes(root->child[i]);
    return sum + 1;
}
int sum_nodes(Tree<int> *root)
{
    if (root == NULL)
        return 0;

    int sum = 0;
    for (int i = 0; i < root->child.size(); i++)
        sum += sum_nodes(root->child[i]);
    return sum + root->data;
}
int largest_nodes(Tree<int> *root)
{
    if (root == NULL)
        return INT16_MIN;

    int large=INT16_MIN;
    for (int i = 0; i < root->child.size(); i++)
        large=max(large,largest_nodes(root->child[i]));

    return max(large,root->data);
}
int treeHEIGHT(Tree<int> *root)
{
    if (root == NULL)
        return 0;

    int height=0;
    for (int i = 0; i < root->child.size(); i++)
        height=max(height,treeHEIGHT(root->child[i]));

    return height+1;
}
void printDEPTH_K(Tree<int> *root,int k){
    if(root==NULL) return;
    if(k==0){
        cout<<root->data<<" ";
        return;
        }
    for (int i = 0; i < root->child.size(); i++)
        printDEPTH_K(root->child[i],k-1);
}
int leaf_nodes(Tree<int> *root)
{   if(root==NULL) return 0;
    if (root->child.size()==0)
        return 1;

    int leaf = 0;
    for (int i = 0; i < root->child.size(); i++)
        leaf += leaf_nodes(root->child[i]);
    return leaf;
}
// int main()
// {
//     Tree<int> *root = takeInput();
//     // cout << root->data;
//     print_tree(root);
//     cout <<"num:"<< num_nodes(root)<<endl;
//     cout << "sum:" << sum_nodes(root)<<endl;
//     cout << "Greatest:" << largest_nodes(root)<<endl;
//     cout << "height:" << treeHEIGHT(root)<<endl;

//     printDEPTH_K(root,2);
//     cout<<endl<<"leafs:"<<leaf_nodes(root)<<endl;
// }
