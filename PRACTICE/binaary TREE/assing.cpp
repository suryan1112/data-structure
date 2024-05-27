#include <bits/stdc++.h>
#include "tree.cpp"
#include "../Linkedlist/ll.h"
using namespace std;

int sumNODES(BtreeNODE<int> *root)
{
    if (root == NULL)
        return 0;

    return sumNODES(root->left) + sumNODES(root->right) + root->data;
}
bool b = true;
int BTS(BtreeNODE<int> *root)
{
    if (root == NULL)
        return 0;
    int lh = BTS(root->left);
    int rh = BTS(root->right);

    if (abs(lh - rh) > 1)
        b = false;
    return max(lh, rh) + 1;
}
BtreeNODE<int> *REMOVEleaf(BtreeNODE<int> *root)
{
    if (root == NULL)
        return root;
    if (!root->left && !root->right)
        return NULL;

    root->left = REMOVEleaf(root->left);
    root->right = REMOVEleaf(root->right);

    return root;
}
Node *reversed_LL(Node *head)
{
    Node *prev = NULL;
    Node *next = head->next;
    while (head->next)
    {
        head->next = prev;
        prev = head;
        head = next;
        next = next->next;
    }
    head->next = prev;
    return head;
}
vector<Node *> zigzag(BtreeNODE<int> *root)
{
    queue<BtreeNODE<int> *> q;
    q.push(root);
    int train = 1;
    vector<Node *> V;
    bool b = false;
    while (q.size())
    {
        int traan = 0;
        Node *head = NULL;
        for (int i = 0; i < train; i++)
        {

            BtreeNODE<int> *node = q.front();
            q.pop();
            // cout << node->data << " ";
            Node *noda = new Node(node->data);
            if (head == NULL)
            {
                head = noda;
                V.push_back(head);
            }
            else
            {

                head->next = noda;
                head = head->next;
            }
            if (node->left)
            {
                q.push(node->left);
                traan++;
            }
            if (node->right)
            {
                q.push(node->right);
                traan++;
            }
        }
        if (b)
        {
            V[V.size() - 1] = reversed_LL(V[V.size() - 1]);
        }
        b = !b;
        train = traan;
    }
    return V;
}
void noSIBLINGS(BtreeNODE<int> *root, bool sibling = true)
{
    if (!root)
        return;
    if (!sibling)
        cout << root->data<<" ";

    if (root->left && root->right)
    {
        noSIBLINGS(root->left, true);
        noSIBLINGS(root->right, true);
    }
    else
    {
        noSIBLINGS(root->left, false);
        noSIBLINGS(root->right, false);
    }
}
int main()
{
    BtreeNODE<int> *root = takeInputLEVEL();
    // printLEVELwise(root);

    noSIBLINGS(root);
}