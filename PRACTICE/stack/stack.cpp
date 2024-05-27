#include <bits/stdc++.h>
#include "../Linkedlist/ll.h"
using namespace std;

template <typename T>
class StackUsingArray
{
public:
    int arr_size = 0;
    int index;
    T *arr;
    StackUsingArray()
    {
        arr_size = 2;
        index = 0;
        delete[] arr;
        arr = new T[arr_size];
    }
    void push(T val)
    {
        if (index < arr_size)
        {
            arr[index] = val;
            index++;
        }
        else
        {
            arr_size *= 2;
            T *arr2 = new T[arr_size];
            for (int i = 0; i < arr_size; i++)
            {
                arr2[i] = arr[i];
            }
            delete[] arr;
            arr = arr2;
            push(val);
        }
    }
    T pop()
    {
        index--;
        if (index < arr_size / 2)
        {
            arr_size /= 2;
            T *arr2 = new T[arr_size];
            for (int i = 0; i < arr_size; i++)
            {
                arr2[i] = arr[i];
            }
            delete[] arr;
            arr = arr2;
        }
        return arr[index];
    }
};
class StackUsingLL
{
public:
    Node *head;
    int size;
    StackUsingLL()
    {
        head = NULL;
        size = 0;
    }
    void push(int data)
    {
        Node *node = new Node(data);
        node->next = head;
        head = node;
        size++;
    }
    int top()
    {
        if (size == 0)
            return -1;
        return head->data;
    }
    int pop()
    {
        if (size == 0)
            return -1;
        int data = head->data;
        Node *saver = head;
        head = head->next;
        delete saver;
        size--;
        return data;
    }
};

int main()
{
    StackUsingLL s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    Node *temp = s.head;
    // while (temp)
    // {
    //     cout << temp->data << " ";
    //     temp = temp->next;
    // }
    int t = 10;
    do
    {
        t = s.pop();
        cout << t << " ";
    } while (t != -1);
}
