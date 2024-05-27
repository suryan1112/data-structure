#include <bits/stdc++.h>
#include "ll.h"
using namespace std;

Node *takeInput()
{
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;
    while (data != -1)
    {
        Node *node = new Node(data);
        if (head == NULL)
        {
            head = node;
            tail = node;
        }
        else
        {
            tail->next = node;
            tail = tail->next;
        }
        cin >> data;
    }
    return head;
}
int lengthLL(Node *head){
    int count=0;
    while (head)
    {
        count++;
        head = head->next;
    }
    return count;
}
void printLL(Node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
}
int ithNodeData(Node*head,int i){
    if(i==0) return head->data;
    return ithNodeData(head->next,i-1);
}
Node* ithNodeData(Node*head,int i,int x){
    if(i==0){
        Node* new_node=new Node(x);
        new_node->next=head;
        return new_node;
    }
    head->next=ithNodeData(head->next,i-1,x);
    return head;
}
// Node* ithNodeData(Node*head,int i,int x){
//     if(i==0){
//         Node* new_node=new Node(x);
//         new_node->next=head;
//         return new_node;
//     }
//     head->next=ithNodeData(head->next,i-1,x);
//     return head;
// }
Node* DeleteithNodeData(Node*head,int i){
    if(i==0){
        return head->next;
    }
    head->next=DeleteithNodeData(head->next,i-1);
    return head;
}
