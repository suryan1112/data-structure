#include <bits/stdc++.h>
#include "BSTclass.h"
using namespace std;

BtreeNODE<int> *duplicate(BtreeNODE<int> *root)
{
    if (root == NULL)
        return NULL;

    BtreeNODE<int> *node = new BtreeNODE<int>(root->data);
    node->left = duplicate(root->left);
    root->left = node;

    root->right = duplicate(root->right);
    return root;
}
void sumPAIRS(BtreeNODE<int> *root, BST roota, int sum)
{
    if (root == NULL)
        return;
    int d1 = root->data;
    int d2 = sum - d1;

    if (roota.hasDATA(d2))
    {
        cout << d1 << " " << d2 << endl;
    }

    sumPAIRS(root->left, roota, sum);
    sumPAIRS(root->right, roota, sum);
}
int ansistor = -1;
void ansistors(BtreeNODE<int> *root, int k1, int k2)
{
    if (!root)
        return;

    if (k1 <= root->data && k2 >= root->data)
    {
        BST new_root;
        new_root.root = root;
        bool b1 = new_root.hasDATA(k1);
        bool b2 = new_root.hasDATA(k2);

        if (b1 && b2)
            ansistor = root->data;
        else if (b1)
            ansistor = k1;
        else if (b2)
            ansistor = k2;
        else
            ansistor = -1;
    }
    else if (root->data < k1)
        ansistors(root->right, k1, k2);
    else if (root->data > k2)
        ansistors(root->left, k1, k2);
}

class isBST
{
public:
    int min;
    int max;
    bool isbst;
    int height;

    isBST(int min, int max, bool isbst, int height)
        : min(min), max(max), isbst(isbst), height(height) {}
};

isBST max_size_BST(BtreeNODE<int> *root)
{
    if (!root)
    {
        // Handle null nodes by returning an appropriate isBST object
        return isBST(INT_MAX, INT_MIN, true, 0);
    }

    if (!root->left && !root->right)
    {
        // If the node is a leaf, it is a BST of height 1
        return isBST(root->data, root->data, true, 1);
    }

    isBST leftSubtree = max_size_BST(root->left);
    isBST rightSubtree = max_size_BST(root->right);

    bool isBSTNow = leftSubtree.isbst && rightSubtree.isbst &&
                    (root->data > leftSubtree.max && root->data <= rightSubtree.min);

    int currentMin = min(root->data, min(leftSubtree.min, rightSubtree.min));
    int currentMax = max(root->data, max(leftSubtree.max, rightSubtree.max));
    int currentHeight = (isBSTNow) ? max(leftSubtree.height, rightSubtree.height) + 1 : max(leftSubtree.height, rightSubtree.height);

    return isBST(currentMin, currentMax, isBSTNow, currentHeight);
}

int replacingGREATESTsum(BtreeNODE<int> *root, int s = 0)
{

    if (!root)
        return 0;
    int sum = root->data;
    sum += replacingGREATESTsum(root->right, s);
    root->data = sum + s;
    sum += replacingGREATESTsum(root->left, root->data);

    return sum;
}
vector<vector<BtreeNODE<int> *>> PATHsum(BtreeNODE<int> *root, int sum)
{
    vector<vector<BtreeNODE<int> *>> v;
    if (root == NULL)
        return v;
    if (root->left == NULL && root->right == NULL)
    {
        if (root->data == sum)
            v.push_back({root});
        return v;
    }
    vector<vector<BtreeNODE<int> *>> V1 = PATHsum(root->left, sum - root->data);
    for (int i = 0; i < V1.size(); i++)
    {
        if (V1[i].front() == root->left)
            V1[i].insert(V1[i].begin(), root);
        v.push_back(V1[i]);
    }
    vector<vector<BtreeNODE<int> *>> V2 = PATHsum(root->right, sum - root->data);
    for (int i = 0; i < V2.size(); i++)
    {
        if (V2[i].front() == root->right)
            V2[i].insert(V2[i].begin(), root);
        v.push_back(V2[i]);
    }
    return v;
}

// TEST-3..
bool cousins(BtreeNODE<int> *root, int p, int q)
{
    queue<BtreeNODE<int> *> que;
    que.push(root);
    int train = 1;
    while (que.size())
    {
        bool b1 = false, b2 = false;
        int train2 = 0;
        for (int i = 0; i < train; i++)
        {
            BtreeNODE<int> *node = que.front();
            que.pop();
            if (p == node->data)
                b1 = true;
            if (q == node->data)
                b2 = true;

            if (node->left)
            {
                que.push(node->left);
                train2++;
            }
            if (node->right)
            {
                que.push(node->right);
                train2++;
            }
        }
        if (b1 && b2)
            return true;
        train = train2;
    }
    return false;
}
vector<BtreeNODE<int> *> LEaf_TO_node(BtreeNODE<int> *root)
{

    vector<BtreeNODE<int> *> v;
    if (root == NULL)
        return v;

    vector<BtreeNODE<int> *> v1 = LEaf_TO_node(root->left);
    vector<BtreeNODE<int> *> v2 = LEaf_TO_node(root->right);

    if (v1.size() > v2.size())
    {
        v1.push_back(root);
        return v1;
    }
    v2.push_back(root);
    return v2;
}
BtreeNODE<int> *removeLEAF(BtreeNODE<int> *root)
{
    if (!root)
        return root;
    if (!root->left && !root->right)
        return NULL;

    root->left = removeLEAF(root->left);
    root->right = removeLEAF(root->right);

    return root;
}
int main()
{
    BtreeNODE<int> *root = takeInput();

    // vector<BtreeNODE<int> *> v = LEaf_TO_node(root);
    // for (int i = 0; i < v.size(); i++)
    //     cout << v[i]->data << " ";

    root = removeLEAF(root);
    cout << root->data << endl;
    printLEVELwise(root);
}