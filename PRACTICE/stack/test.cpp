#include <bits/stdc++.h>
#include "../Linkedlist/gour.cpp"
using namespace std;

int carry = 0;
void increment(Node *head)
{   
    if (head->next == NULL)
    {
        head->data = (head->data + 1);
        carry = head->data / 10;
        head->data =head->data % 10;
        return;
    }
    increment(head->next);
    head->data = (head->data + carry);
    carry = head->data / 10;
    head->data %= 10;
}
Node *main_increment(Node *head)
{   if(!head) return head;
    increment(head);

    if (carry)
    {
        Node *new_head = new Node(carry);
        new_head->next = head;
        head = new_head;
    }
    return head;
}
void deleteAlternate(Node*head){
    while(head && head->next){
        Node*save=head->next;
        head->next=head->next->next;
        delete save;
        head=head->next;
    }
}
int main()
{
    Node *head = takeInput();
    deleteAlternate(head);
    printLL(head);
}