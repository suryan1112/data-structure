#include <bits/stdc++.h>
#include "treestrct.h"
using namespace std;

Tree<int> *takeInput()
{
    int data;
    cin >> data;
    Tree<int> *root = new Tree<int>(data);
    int size;
    cout << "enter size of " << data << ":";
    cin >> size;

    for (int i = 0; i < size; i++)
        root->child.push_back(takeInput());
    return root;
}
void print_tree(Tree<int> *root)
{
    cout << root->data << " : ";
    for (int i = 0; i < root->child.size(); i++)
        cout << root->child[i]->data << " ";
    cout << endl;
    for (int i = 0; i < root->child.size(); i++)
        print_tree(root->child[i]);
}
int main()
{
    Tree<int> *root = takeInput();
    // cout << root->data;
    print_tree(root);
}
