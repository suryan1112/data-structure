#include <bits/stdc++.h>
#include "treeNODE.h"
#include <queue>
using namespace std;

BtreeNODE<int> *takeInput()
{
    int data;
    cin >> data;
    if (data == -1)
        return NULL;

    BtreeNODE<int> *root = new BtreeNODE<int>(data);
    root->left = takeInput();
    root->right = takeInput();
    return root;
}
void print_Btree(BtreeNODE<int> *root)
{
    if (root == NULL)
        return;
    cout << root->data << " : ";
    if (root->left)
        cout << "L" << root->left->data << " ";
    if (root->right)
        cout << "R" << root->right->data << " ";
    cout << endl;

    print_Btree(root->left);
    print_Btree(root->right);
}

BtreeNODE<int> *takeInputLEVEL()
{
    int data;
    cin >> data;
    if (data == -1)
        return NULL;

    BtreeNODE<int> *root = new BtreeNODE<int>(data);
    queue<BtreeNODE<int> *> q;
    q.push(root);
    while (q.size())
    {
        BtreeNODE<int> *node = q.front();
        q.pop();
        cout << "enter child of " << node->data << " : ";
        int child1, child2;
        cin >> child1 >> child2;

        if (child1 != -1)
        {
            BtreeNODE<int> *children1 = new BtreeNODE<int>(child1);
            node->left = children1;
            q.push(children1);
        }
        if (child2 != -1)
        {
            BtreeNODE<int> *children2 = new BtreeNODE<int>(child2);
            node->right = children2;
            q.push(children2);
        }
    }
    return root;
}
void printLEVELwise(BtreeNODE<int> *root)
{
    queue<BtreeNODE<int> *> q;
    q.push(root);
    int train = 1;

    while (q.size())
    {   int traan=0;
        for(int i=0;i<train;i++){

            BtreeNODE<int> *node = q.front();
            q.pop();
            cout << node->data << " ";
            if (node->left){
                q.push(node->left);
                traan++;}
            if (node->right){
                q.push(node->right);
                traan++;}
        }
        train=traan;
        cout<<endl;
    }
}

