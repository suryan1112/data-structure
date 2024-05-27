#include <bits/stdc++.h>
#include "tree.cpp"
#include "../Linkedlist/ll.h"
using namespace std;

bool binarySEARCH(BtreeNODE<int> *root, int x)
{
    if (root == NULL)
        return false;

    if (x < root->data)
        return binarySEARCH(root->left, x);
    if (x == root->data)
        return true;
    else
        return binarySEARCH(root->right, x);
}
void print_range(BtreeNODE<int> *root, int k1, int k2)
{
    if (root == NULL)
        return;

    if (root->data <= k2 && root->data >= k1)
        cout << root->data << " ";
    if (root->data <= k2)
        print_range(root->right, k1, k2);
    if (root->data >= k1)
        print_range(root->left, k1, k2);
}
bool checkBST(BtreeNODE<int> *root, int k1 = INT16_MIN, int k2 = INT16_MAX)
{
    if (root == NULL)
        return true;

    if (root->data < k1 || root->data > k2)
        return false;
    return checkBST(root->left, k1, root->data) && checkBST(root->right, root->data, k2);
}
BtreeNODE<int> *createBST(int a[], int s, int e)
{
    if (s > e)
        return NULL;

    int mid = (s + e) / 2;
    BtreeNODE<int> *root = new BtreeNODE<int>(a[mid]);

    root->left = createBST(a, s, mid - 1);
    root->right = createBST(a, mid + 1, e);

    return root;
}
Node *tail = NULL;
Node *main_head = NULL;
void BSTtoLL(BtreeNODE<int> *root)
{
    if (root == NULL)
        return;

    Node *node = new Node(root->data);
    BSTtoLL(root->left);
    if (!tail)
    {
        tail = node;
        main_head = tail;
    }
    else
    {
        tail->next = node;
        tail = tail->next;
    }
    BSTtoLL(root->right);
}
vector<int> printPATH(BtreeNODE<int> *root, int x)
{
    vector<int> v;
    if (root == NULL)
        return v;

    if (root->data == x)
    {
        v.push_back(x);
        return v;
    }
    if (x < root->data)
        v = printPATH(root->left, x);
    else
        v = printPATH(root->right, x);

    if (v.size())
        v.push_back(root->data);
    return v;
}
// int main()
// {
//     BtreeNODE<int> *root = takeInputLEVEL();
//     printLEVELwise(root);

//     int x;
//     cin >> x;
//     vector<int> v = printPATH(root, x);
//     for (int i = 0; i < v.size(); i++)
//         cout << v[i] << " ";

//     // cout << checkBST(root);
//     // int k1,k2; cin>>k1>>k2;
//     // print_range(root,k1,k2);
// }