#include <bits/stdc++.h>
#include "../Linkedlist/ll.h"
using namespace std;

class QueueUsingArray
{
public:
    int ih;
    int fh;
    int size;
    int arr_size;
    int *arr;
    QueueUsingArray()
    {
        ih = -1;
        fh = 0;
        size = 0;
        arr_size = 4;
        arr = new int[arr_size];
    }
    void inQueue(int data)
    {
        if (size == arr_size)
        {
            arr_size *= 2;
            int *arr2 = new int[arr_size];
            int i = ih, j = 0;
            do
            {
                arr2[j] = arr[i];
                i = (i + 1) % size;
                j++;
            } while (i != fh);

            delete[] arr;
            ih = 0;
            fh = size;
            arr = arr2;
        }
        if(ih==-1) ih=0;
        arr[fh] = data;
        fh = (fh + 1) % arr_size;
        size++;
    }
    int deQueue()
    {   
        if(size==0) return -1;

        int data = arr[ih];
        ih = (ih + 1) % arr_size;
        size--;
        if (size <= arr_size / 2)
        {
            arr_size /= 2;
            int *arr2 = new int[arr_size];
            int i = ih, j = 0;
            do
            {
                arr2[j] = arr[i];
                i = (i + 1) % (arr_size*2);
                j++;
            } while (i != fh);

            delete[] arr;
            ih = 0;
            fh = size;
            arr = arr2;
        }
        return data;
    }
};
class QueueUsingLL{
    public:
    Node*head;
    Node*tail;
    int size;
    QueueUsingLL(){
        head=NULL;
        tail=NULL;
        size=0;
    }
    void enQueue(int data){
        Node*node=new Node(data);
        if(head==NULL){
            head=node;
            tail=node;
        }
        else {tail->next=node;
        tail=tail->next;}
        size++;
    }
    int deQueue(){
        if(size==0) return -1;
        int data=head->data;
        head=head->next;
        if(size==1) tail=NULL;
        size--;
        return data;
    }
};


int main(){
    QueueUsingLL q;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);

    cout<<q.deQueue()<<endl;
    cout<<q.deQueue()<<endl;
    cout<<q.deQueue()<<endl;
    cout<<q.deQueue()<<endl;

}
// int main()
// {
//     QueueUsingArray q;
//     q.inQueue(1);
//     q.inQueue(2);
//     q.inQueue(3);
//     q.inQueue(4);
//     cout << q.size << " " << q.arr_size << endl;

//     for (int i = 0; i < q.arr_size; i++)
//         cout << q.arr[i] << " ";

//     q.inQueue(5);
//     q.inQueue(6);
//     cout<< "dequed:" <<q.deQueue()<<endl;
//     cout<< "dequed:" <<q.deQueue()<<endl;

//     cout << endl<< q.size << " " << q.arr_size << endl;

//     for (int i = 0; i < q.arr_size; i++)
//         cout << q.arr[i] << " ";
// }