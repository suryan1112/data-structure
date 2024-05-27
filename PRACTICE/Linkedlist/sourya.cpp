#include <bits/stdc++.h>
#include "gour.cpp"
using namespace std;

Node *midNode(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast && fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node *mergeTwoLists(Node *list1, Node *list2)
{
    if (list1 == NULL)
        return list2;
    if (list2 == NULL)
        return list1;

    if (list1->data > list2->data)
    {
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }
    else
    {
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    }
}
Node *mergeSort(Node *head)
{
    if (head->next == NULL || head == NULL)
        return head;

    Node *mid = midNode(head);
    Node *head2 = mid->next;
    mid->next = NULL;
    head = mergeSort(head);
    head2 = mergeSort(head2);

    return mergeTwoLists(head, head2);
}
Node *tail = NULL;
void reverseLL(Node *head, Node *prev)
{
    if (head == NULL)
        return;
    if (head->next == NULL)
        tail = head;

    reverseLL(head->next, head);
    head->next = prev;
}

Node *odd_even(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *verified = odd_even(head->next);
    if (head->data % 2 == 0)
    {
        Node *temp = verified;
        if (temp->data % 2 == 0)
        {
            head->next = temp;
            return head;
        }
        while (temp->next && temp->next->data % 2 == 1)
            temp = temp->next;
        Node *save = temp->next;
        temp->next = head;
        head->next = save;
    }
    else
    {
        head->next = verified;
        verified = head;
    }
    return verified;
}
Node *deletemn(Node *head, int m, int n)
{
    Node *main_head = head;
    for (int i = 0; i < m - 1; i++)
    {
        if (head == NULL)
            return main_head;
        head = head->next;
    }
    Node *temp = head->next;
    for (int i = 0; i < n; i++)
    {
        if (temp == NULL)
        {
            head->next = NULL;
            return main_head;
        }
        Node *del = temp;
        temp = temp->next;
        delete del;
    }
    head->next = deletemn(temp, m, n);

    return main_head;
}
Node *swap_saved = NULL;
Node *swap_saved2 = NULL;
Node *swapMN(Node *head, int m, int n)
{
    if (head == NULL)
        return head;
    if (n == 0)
    {
        swap_saved->next = head->next;
        swap_saved2 = head;
        return swap_saved;
    }
    if (m == 0)
    {
        swap_saved = head;
        Node *none = swapMN(head->next, m - 1, n - 1);
        swap_saved2->next = none;
        return swap_saved2;
    }
    head->next = swapMN(head->next, m - 1, n - 1);
    return head;
}
Node *reverse_LL(Node *head)
{
    if (!head || head->next == NULL)
        return head;

    Node *main = reverse_LL(head->next);
    Node *temp = main;

    while (temp->next)
        temp = temp->next;
    temp->next = head;
    head->next = NULL;

    return main;
}
Node *reverseK(Node *head, int k)
{

    if (head == NULL)
        return head;
    Node *temp = head;
    for (int i = 0; i < k - 1; i++)
        if (temp->next)
            temp = temp->next;
    Node *recc = temp->next;
    temp->next = NULL;
    Node *last = reverse_LL(head);
    head->next = reverseK(recc, k);

    return last;
}
Node *bubble_sort(Node *head)
{
    if(!head || !head->next) return head; 
    Node *temp = head;
    Node *prev = NULL;

    while (temp->next)
    {   
        if (temp->data > temp->next->data)
        {
            if (prev)
            {
                prev->next = temp->next;
                temp->next = temp->next->next;
                prev->next->next = temp;
                prev=prev->next;
            }
            else
            {
                Node *save = temp->next;
                temp->next = temp->next->next;
                save->next = temp;
                head = save;
                prev=save;
            }
        }
        else{
            prev=temp;
            temp = temp->next;
        } 
    }
    prev->next=NULL;
    Node* tempo=bubble_sort(head);
    Node*newList=tempo;

    while(newList->next) newList=newList->next;
    newList->next=temp;

    return tempo;
}
int main()
{
    Node *head = takeInput();
    // Node *head2 = takeInput();
    head = bubble_sort(head);
    printLL(head);
}