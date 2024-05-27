#include <bits/stdc++.h>
#include "tree.cpp"
using namespace std;

int nodesCOUNT(BtreeNODE<int> *root)
{
    if (root == NULL)
        return 0;
    return nodesCOUNT(root->left) + nodesCOUNT(root->right) + 1;
}
int treeHEIGHT(BtreeNODE<int> *root)
{
    if (root == NULL)
        return 0;
    return max(treeHEIGHT(root->left), treeHEIGHT(root->right)) + 1;
}
BtreeNODE<int> *MIRRORtree(BtreeNODE<int> *root)
{
    if (root == NULL)
        return root;

    BtreeNODE<int> *new_lefti = MIRRORtree(root->right);
    root->right = MIRRORtree(root->left);
    root->left = new_lefti;
    return root;
}
void preorderBTREE(BtreeNODE<int> *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorderBTREE(root->left);
    preorderBTREE(root->right);
}
void postorderBTREE(BtreeNODE<int> *root)
{
    if (root == NULL)
        return;
    postorderBTREE(root->left);
    postorderBTREE(root->right);

    cout << root->data << " ";
}
BtreeNODE<int> *createTREE_pre_inord(int pre[], int sp, int ep, int in[], int si, int ei)
{

    if (sp > ep || si > ei)
        return NULL;
    // cout<<pre[sp]<<" ";
    BtreeNODE<int> *root = new BtreeNODE<int>(pre[sp]);
    int index;
    for (int i = si; i <= ei; i++)
        if (in[i] == pre[sp])
        {
            index = i;
            break;
        }
    int shift = index - si;
    root->left = createTREE_pre_inord(pre, sp + 1, sp + shift, in, si, index - 1);
    root->right = createTREE_pre_inord(pre, sp + shift + 1, ep, in, index + 1, ei);

    return root;
}
BtreeNODE<int> *createTREE_post_inord(int pre[], int sp, int ep, int in[], int si, int ei)
{

    if (sp > ep || si > ei)
        return NULL;
    // cout<<pre[sp]<<" ";
    BtreeNODE<int> *root = new BtreeNODE<int>(pre[ep]);
    int index;
    for (int i = si; i <= ei; i++)
        if (in[i] == pre[ep])
        {
            index = i;
            break;
        }
    int shift = index - si;
    root->left = createTREE_post_inord(pre, sp, sp + shift - 1, in, si, index - 1);
    root->right = createTREE_post_inord(pre, sp + shift, ep - 1, in, index + 1, ei);

    return root;
}
int max_diameter = 0;
int height(BtreeNODE<int> *root)
{
    if (root == NULL)
        return 0;
    // if(roo)
    int lh = height(root->left);
    int rh = height(root->right);

    max_diameter = max(max_diameter, lh + rh);
    return max(lh, rh) + 1;
}
int maxi = INT16_MIN;
int mini = INT16_MAX;
void iterating(BtreeNODE<int> *root)
{
    if (!root)
        return;

    maxi = max(maxi, root->data);
    mini = min(mini, root->data);

    iterating(root->left);
    iterating(root->right);
}

int main()
{
    BtreeNODE<int> *root = takeInputLEVEL();
    printLEVELwise(root);
    iterating(root);
    cout << mini << " " << maxi;
}