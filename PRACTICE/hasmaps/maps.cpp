#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Node
{
    string key;
    T value;
    Node *next;

public:
    Node(string key, T value)
    {
        this->key = key;
        this->value = value;
        next = NULL;
    }
    ~Node()
    {
        delete next;
    }
};

template <typename T>
class HashMAPS
{
    Node<T> **BucketArray;
    int BucketSIZE;
    int count;
    // int occupied;
public:
    HashMAPS()
    {
        BucketSIZE = 5;
        BucketArray = new Node<T> *[BucketSIZE];
        count = 0;
        // occupied=0;
    }
    ~HashMAPS()
    {
        for (int i = 0; i < BucketSIZE; i++)
            delete BucketArray[i];
        delete BucketArray;
    }

private:
    int hashGENERATOR(string key)
    {
        int hash = 0;
        for (int i = key.size() - 1; i > 0; i--)
        {
            hash += key[i] * pow(37, i);
            hash %= BucketSIZE;
        }
        return hash;
    }

public:
    T find(string key)
    {
        int index = hashGENERATOR(key);
        Node<T> *temp = BucketArray[index];

        while (temp)
        {
            if (temp->key == key)
                return temp->value;
            temp = temp->next;
        }
        return (T)-1;
    }

private:
    void pushna(string key, T value, Node<T> *temp)
    {
        if (temp == NULL)
        {
            Node<T> *new_node = new Node<T>(key, value);
            return new_node;
        }
        if (temp->key == key)
        {
            temp->value = value;
            return temp;
        }
        temp->next = pushna(key, value, temp->next);
        return temp;
    }

public:
    void push(string key, T value)
    {
        int index = hashGENERATOR(key);
        BucketArray[index] = pushna(key, value, BucketArray[index]);
    }

private:
    void pop_up(string key, Node<T> *temp)
    {
        if (temp == NULL)
            return;

        if (temp->key == key)
        {
            Node<T> *temp2 = temp->next;
            temp->next = NULL;
            delete temp;
            return temp2;
        }
        pop_up(key, temp->next);
    }

public:
    void pop(string key)
    {
        int index = hashGENERATOR(key);
        pop_up(key, BucketArray[index]);
    }
};

int main()
{
    HashMAPS<int> map;
    // map.push("abc",23);
}