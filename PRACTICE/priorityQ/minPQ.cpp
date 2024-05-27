#include <bits/stdc++.h>
using namespace std;

class MinPRIORITYQ
{
    vector<int> pq;
    // [0, 1,2  ,3,4  5,6 ] child-> child*2+1, child*2+2;
    void upheapify(int child)
    {
        if (child == 0)
            return;

        int parent = (child - 1) / 2;
        if (pq[parent] > pq[child])
        {
            int save = pq[child];
            pq[child] = pq[parent];
            pq[parent] = save;
        }
        else
            return;
        upheapify(parent);
    }
    void downheapify(int parent)
    {
        int child1 = parent * 2 + 1;
        int child2 = parent * 2 + 2;

        int mini_index = 0;
        if (child1 < pq.size() && child2 < pq.size())
            mini_index = (pq[child1] < pq[child2]) ? child1 : child2;
        else if (child1 < pq.size())
            mini_index = child1;
        else
            return;
        if (pq[parent] > pq[mini_index])
        {
            int save = pq[mini_index];
            pq[mini_index] = pq[parent];
            pq[parent] = save;
        }
        else
            return;
        downheapify(mini_index);
    }

public:
    int getMin()
    {
        if (pq.empty())
            return -1;
        return pq[0];
    }
    void push(int data)
    {
        pq.push_back(data);
        upheapify(pq.size() - 1);
    }
    int remove_min()
    {
        if (pq.empty())
            return -1;
        int data = pq[0];
        pq[0] = pq.back();
        pq.pop_back();
        downheapify(0);

        return data;
    }
};
void helperupheapify(int child, int pq[], int n)
{
    if (child == 0)
        return;

    int parent = (child - 1) / 2;
    if (pq[parent] > pq[child])
    {
        int save = pq[child];
        pq[child] = pq[parent];
        pq[parent] = save;
    }
    else
        return;
    helperupheapify(parent, pq, n);
}
void helperINPLACE(int parent, int pq[], int n)
{
    int child1 = parent * 2 + 1;
    int child2 = parent * 2 + 2;

    int mini_index = 0;
    if (child1 < n && child2 < n)
        mini_index = (pq[child1] < pq[child2]) ? child1 : child2;
    else if (child1 < n)
        mini_index = child1;
    else
        return;
    
    if (pq[parent] > pq[mini_index])
    {
        int save = pq[mini_index];
        pq[mini_index] = pq[parent];
        pq[parent] = save;
    }
    else
        return;
    helperINPLACE(mini_index, pq, n);
}
void remove_min(int pq[],int n,int i)
{
    int data = pq[0];
    pq[0] = pq[i];
    pq[i]=data;

    helperINPLACE(0,pq,i);

}
void inplaceheapSORT(int a[], int n)
{

    for (int i = n - 1; i > 0; i--)
    {
        helperupheapify(i, a, n);
    }
    for (int i = n - 1; i > 0; i--)
        remove_min(a,n,i);
}
// int main()
// {
//     int n;
//     cin >> n;
//     int a[n];
//     for (int i = 0; i < n; i++)
//         cin >> a[i];

//     inplaceheapSORT(a, n);
//     for (int i = 0; i < n; i++)
//         cout << a[i] << " ";
// }
