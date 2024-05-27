#include <bits/stdc++.h>
#include "gour.cpp"
using namespace std;

int findINDEX(Node *head, int x)
{
    if (head == NULL)
        return -1000;
    if (head->data == x)
        return 0;
    return findINDEX(head->next, x) + 1;
}
Node *AppendLastNToFirst(Node *head, int i)
{
    Node *temp = head;
    Node *new_head = NULL;
    while (temp->next)
    {
        Node *save = temp->next;
        if (i == 1)
            temp->next = NULL;
        temp = save;
        i--;
        if (i == 0)
        {
            new_head = temp;
        }
    }
    temp->next = head;
    return new_head;
}
void eliminateDuplicate(Node *head)
{
    if (head->next == NULL)
        return;
    while (head->next)
    {
        if (head->data == head->next->data)
            head->next = head->next->next;
        else
            head = head->next;
    }
}
void printLLR(Node *head)
{
    if (head == NULL)
        return;
    printLLR(head->next);
    cout << head->data << " ";
}
Node *reversed_LL(Node *head)
{
    Node *prev = NULL;
    Node *next= head->next;
    while (head->next)
    {
        head->next=prev;
        prev = head;
        head = next;
        next=next->next;
    }
    head->next=prev;
    return head;
}
int main()
{
    Node *head = takeInput();

    head = reversed_LL(head);
    printLL(head);
}