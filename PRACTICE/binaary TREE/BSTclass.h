#include "BST.cpp"

class BST
{

public:
    BtreeNODE<int> *root;
    BST()
    {
        root = NULL;
    }
    ~BST()
    {
        delete root;
    }

private:
    BtreeNODE<int> *deleteDATAP(int data, BtreeNODE<int> *node)
    {
        if (node == NULL)
        {
            return NULL;
        }

        if (data < node->data)
            node->left = deleteDATAP(data, node->left);
        else if (data > node->data)
            node->right = deleteDATAP(data, node->right);
        else
        {
            if (node->left && node->right)
            {
                BtreeNODE<int> *righti = node->right;
                while (righti->left)
                    righti = righti->left;
                int new_data = righti->data;
                node->right = deleteDATAP(new_data, node->right);
                node->data = new_data;
            }
            else if (node->left)
            {
                BtreeNODE<int> *lefti = node->left;
                node->left = NULL;
                delete node;
                return lefti;
            }
            else if (node->right)
            {
                BtreeNODE<int> *righti = node->right;
                node->right = NULL;
                delete node;
                return righti;
            }
            else
            {
                delete node;
                return NULL;
            }
        }
        return node;
    }

public:
    void *deleteDATA(int data)
    {
        this->root = deleteDATAP(data, this->root);
    }

private:
    BtreeNODE<int> *insertDATAP(int data, BtreeNODE<int> *node)
    {
        if (node == NULL)
        {
            BtreeNODE<int> *node = new BtreeNODE<int>(data);
            return node;
        }

        if (data < node->data)
            node->left = insertDATAP(data, node->left);
        else
            node->right = insertDATAP(data, node->right);
    }

public:
    void *insertDATA(int data)
    {
        this->root = insertDATAP(data, this->root);
    }

private:
    bool hasDATAP(int x, BtreeNODE<int> *node)
    { // searching
        if (node == NULL)
            return false;

        if (x == node->data)
            return true;
        if (x < node->data)
            return hasDATAP(x, node->left);

        return hasDATAP(x, node->right);
    }

public:
    bool hasDATA(int data)
    {
        return hasDATAP(data, this->root);
    }
};