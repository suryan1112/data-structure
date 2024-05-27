#include<iostream>
using namespace std;
#include "node.cpp"

void print(Node*head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }cout<<endl;
}
Node*input(){
    Node*head=NULL;
    Node*tail=NULL;
    int data; cin>>data;
    while(data!=-1){
        Node*newNode=new Node(data);
        if(head==NULL){
            head=newNode;
            tail=head;
        }
        else{
            tail->next=newNode;
            tail=tail->next;
        }
        cin>>data;
    }
    return head;
}
int count_nodes(Node*head){
    int count=0;
    while(head!=NULL){
        count++;
        head=head->next;
    }return count;
}
Node*print_ith_node(Node*head,int i){
    while(i--){
        head=head->next;
    }return head;
}
Node*insert_at_ith(Node*head,int data,int i){
    Node*newNode=new Node(data);
    Node*temp=head;
    if(i==0){
        newNode->next=head;
        head=newNode;
    }else{
        while(i!=1){
            temp=temp->next;
            i--;
        }Node*var=temp->next;
        temp->next=newNode;
        newNode->next=var;
    }
    return head;
}
Node*delete_at_ith(Node*head,int i){
    Node*temp=head;
    if(i==0){
        head=head->next;
    }else{
        while(i!=1){
            temp=temp->next;
            i--;
    }temp->next=temp->next->next;
}
    return head;
}
int RR_length(Node*head){
    if(head==NULL) return 0;
    return RR_length(head->next)+1;
}
Node*RR_insert_ith(Node*head,int i,Node*newNode){
    if(i==0){
        newNode->next=head;
        head=newNode;
        return head;
    }
    head->next=RR_insert_ith(head->next,--i,newNode);
    return head;
}
Node*RR_delete(Node*head,int i){
    if(i==0){
        return head->next;
    }
    head->next=RR_delete(head->next,--i);
    return head;
}
int searching(Node*head,int data){
    if(head==NULL) return -1;
    if(head->data==data) return 0;
    if(searching(head->next,data)==-1)return -1;
    else return searching(head->next,data)+1;
}
Node*shifting(Node*head,int i){
    if(i==0) return head;
    Node*temp=head;
    Node*savenode;
    while(temp->next!=NULL){
        if(i==1){
            savenode=temp->next;
            temp->next=NULL;
            temp=savenode;
        }
        else temp=temp->next;
        i--;
    }temp->next=head;
    return savenode;
}
void remove_duplicate(Node*head){
    Node*temp=head;
    Node*last=head;
    while(temp!=NULL){   
        if(temp->data==last->data){
            last=last->next;
        }
        else {
            temp->next=last;
            temp=temp->next;
        }
    }
}
void print_reverse(Node*head){
    if(head==NULL) return;
    print_reverse(head->next);
    cout<<head->data<<" ";
}
void check_palindrome(Node* head, int i) {
    if (i == 0 || i == 1) {
        cout << "true";
        return;
    }

    Node* temp = head;
    while (i != 1) {
        temp = temp->next;
        i--;
    }

    if (head->data != temp->data) {
        cout << "false";
        return;
    }
    else
    check_palindrome(head->next, i - 2);
}
Node*reverse(Node*head){
    if(head->next==NULL ||head==NULL) return head;
    Node*temp=reverse(head->next);
    Node*mainhead=temp;
    while(temp->next!=NULL) temp=temp->next;
    temp->next=head;
    head->next=NULL;
    return mainhead;
}
void check_palindrome2(Node*head,int i){
    int a=i/2;
    Node*temp=head;
    while(a>1){
        temp=temp->next;
        i--;
    }Node*secondary=reverse(temp->next);
    temp->next=NULL;
    while(head!=NULL && temp!=NULL){
        if(head->data!=secondary->data) {cout<<"false"; return;}
    }cout<<"true";
}
bool isPalindrome(Node* head) {
    if (head == NULL || head->next == NULL)
        return true;

    // Find the middle of the linked list
    Node* slow = head;
    Node* fast = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse the second half of the linked list
    Node* secondHalf = reverse(slow->next);
    Node* firstHalf = head;

    // Compare the reversed second half with the first half
    while (secondHalf != NULL) {
        if (firstHalf->data != secondHalf->data)
            return false;
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    return true;
}
Node*mid_point(Node*head){
    Node*slow=head;
    Node*fast=head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }return slow;
}
Node*merge(Node*head_a,Node*head_b){
    if(head_a==NULL) return head_b;
    else if(head_b==NULL) return head_a;
    Node*main_head;
    if(head_a->data < head_b->data){ 
        main_head=head_a;
        head_a->next=merge(head_a->next,head_b);
    }
    else{
        main_head=head_b;
        head_b->next=merge(head_a,head_b->next);
    }
    return main_head;
}
Node*merge_sort(Node*head){
    if(head==NULL || head->next==NULL) return head;
    Node*slow=head;
    Node*fast=head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    Node*head_a=head;
    Node*head_b=slow->next;
    slow->next=NULL;
    return merge(merge_sort(head_a),merge_sort(head_b));
}
Pair*reverse2(Node*head){
    if(head==NULL || head->next==NULL){
        Pair*pair=new Pair();
        pair->head=head;
        pair->tail=head;
        return pair;
    }
    Pair*pair_final=reverse2(head->next);
    pair_final->tail->next=head;
    pair_final->tail=head;
    head->next=NULL;
    return pair_final;
}
Node*reverse3(Node*head){
    if(head->next==NULL ||head==NULL) return head;
    Node*temp=reverse(head->next);
    Node*tail=head->next;
    tail->next=head;
    head->next=NULL;
    return temp;
}
Node*input_odd_even(){
    int data; cin>>data;
    Node*head_odd=NULL;
    Node*tail_odd=NULL;
    Node*head_even=NULL;
    Node*tail_even=NULL;
    while(data!=-1){
        Node*new_node=new Node(data);
        if(head_odd==NULL && data%2!=0){
            head_odd=new_node;
            tail_odd=new_node;
        }
        else if(data%2!=0){
            tail_odd->next=new_node;
            tail_odd=tail_odd->next;
        }
        else if(head_even==NULL && data%2==0){
            head_even=new_node;
            tail_even=new_node;
        }
        else if(data%2==0){
            tail_even->next=new_node;
            tail_even=tail_even->next;
        }
        cin>>data;
    }
    tail_odd->next=head_even;
    return head_odd;
}
Node*remove(Node*head,int n,int m){
    if(head==NULL) return head;
    if(n==0 && m>0) return NULL;
    else if (n==0 && m==0) return head;

    Node*temp=head;
    while(n!=1 && temp->next!=NULL) {temp=temp->next; n--;}

    Node*temporary=temp->next;
    while(m!=0 && temporary!=NULL) {temporary=temporary->next; m--;}

    temp->next=remove(temporary,n,m);
    return head;
}
Node*swap(Node*head,int i,int j){
    if(head==NULL || head->next==NULL) return head;

    Node*temp=head;
    Node*prev1,*prev2,*cont1,*cont2;

    if(i==0){
        while(j!=1){
            j--; temp=temp->next;
        }
        Node*prev2=temp;
        Node*cont2=temp->next;
        Node*saver=temp->next->next;
        cont1=head;
        head=temp->next; head->next=cont1->next;
        temp->next=cont2; cont2->next=saver;
        return head;
    }
    while(j!=0){
        if(i==1){
            Node*prev1=temp;
            Node*cont1=temp->next;
        }else if(j==1){
            Node*prev2=temp;
            Node*cont2=temp->next;
        }
        i--;j--;
        temp=temp->next;
    }
    Node*cont2_saver=cont2->next;
    prev1->next=cont2; cont2->next=cont1->next;
    prev2->next=cont1; cont1->next=cont2_saver;
    return head;
}
Node*reverse_k(Node*head,int k){
    if(head==NULL || head->next==NULL) return head;

    Node*temp=head;
    while(k!=1 && temp->next!=NULL){
        temp=temp->next; k--;
    }
    Node*last=temp->next;
    temp->next=NULL;
    reverse3(head);
    
    // Node*new_node=reverse(head);
    head->next=reverse_k(last,k);
    return temp;
}
Node*bubble_sort(Node*head){
    if(head==NULL || head->next==NULL) return head;
    
    int i=count_nodes(head);
    Node*main_head=head;
    while(i!=1){
        Node*prev=NULL;
        Node*first=main_head;
        Node*second=main_head->next;

        while(second!=NULL){
            if(first->data > second->data){
                    if(prev!=NULL) {prev->next=second;}
                    else main_head=second;
                    first->next=second->next;
                    second->next=first;
                    prev=second;
                    second=first->next;
                    first=second;
            }
            else{
                prev=first;
                first=second;
                second=second->next;
            }
        }i--;
    }return main_head;
}
Node* bubble_sort2(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    bool swapped;
    Node* current;
    Node* previous = NULL;

    do {
        swapped = false;
        current = head;

        while (current->next != NULL) {
            if (current->data > current->next->data) {
                // Swap nodes
                if (previous != NULL) {
                    previous->next = current->next;
                } else {
                    head = current->next;
                }

                Node* nextNode = current->next;
                current->next = nextNode->next;
                nextNode->next = current;
                previous = nextNode;
                swapped = true;
            } else {
                previous = current;
                current = current->next;
            }
        }
    } while (swapped);

    return head;
}
int increase(Node*head){
    if(head->next==NULL){
        head->data++;
        if((head->data)>9){
            head->data%=10;
            return 1;
        }
        else return 0;
    } 
    if(increase(head->next)==1) head->data++;
    if((head->data)>9){
            head->data%=10;
            return 1;
        }
    else return 0;
}
int main(){
    Node*head=input();
    Node*temp=head;
    while(temp->next!=NULL && temp!=NULL){
        if(temp->next->next==NULL) {temp->next=NULL; break;}
        temp->next=temp->next->next;
        temp=temp->next;
    }
    print(head);
}