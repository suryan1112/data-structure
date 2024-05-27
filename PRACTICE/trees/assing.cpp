#include <bits/stdc++.h>
#include "trees_levelwise.cpp"
using namespace std;

bool isPRESENT(Tree<int> *root, int x)
{
    if (root->data == x)
        return true;
    for (int i = 0; i < root->child.size(); i++)
        if (isPRESENT(root->child[i], x))
            return true;
    return false;
}
int greaterTHEN(Tree<int> *root, int x)
{
    int count = 0;
    for (int i = 0; i < root->child.size(); i++)
        count += greaterTHEN(root->child[i], x);
    if (root->data > x)
        count++;
    return count;
}
int max_child_sum(Tree<int> *root)
{
    int max_sum = INT16_MIN;
    int child_sum = 0;
    for (int i = 0; i < root->child.size(); i++)
    {
        max_sum = max(max_sum, max_child_sum(root->child[i]));
        child_sum += root->child[i]->data;
    }
    return max(max_sum, root->data + child_sum);
}
bool Structurally_Identical(Tree<int> *root1, Tree<int> *root2)
{

    if (root1->data != root2->data || root1->child.size() != root2->child.size())
        return false;
    for (int i = 0; i < root1->child.size(); i++)
        if (!Structurally_Identical(root1->child[i], root2->child[i]))
            return false;
    return true;
}
int next_larger(Tree<int> *root, int x)
{

    int next_max = INT16_MAX;
    for (int i = 0; i < root->child.size(); i++)
        next_max = min(next_max, next_larger(root->child[i], x));
    if (root->data < x)  
        return next_max;
    return root->data;
}
int next_smaller(Tree<int> *root, int x)
{
    int next_max = INT16_MIN;
    for (int i = 0; i < root->child.size(); i++)
        next_max = max(next_max, next_smaller(root->child[i], x));
    if (root->data >= x)  
        return next_max;
    return max(root->data,next_max);
}
void *replace(Tree<int> *root, int x){

    root->data=x;
    for (int i = 0; i < root->child.size(); i++)
        replace(root->child[i],x+1);
}
int main()
{
    Tree<int> *root = takeInput();
    int x=largest_nodes(root);
    // Tree<int> *root2 = takeInput();
    print_tree(root);
    cout << "next_larger" << next_smaller(root, x);
}