#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

void print(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* input() {
    Node* head = NULL;
    Node* tail = NULL;
    int data;
    cin >> data;
    while (data != -1) {
        Node* newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
            tail = head;
        } else {
            tail->next = newNode;
            tail = tail->next;
        }
        cin >> data;
    }
    return head;
}

Node* RR_insert_ith(Node* head, int i, Node* newNode) {
    if (i == 0) {
        newNode->next = head;
        head = newNode;
    } else {
        head->next = RR_insert_ith(head->next, --i, newNode);
    }
    return head;
}

int main() {
    Node* head = input();
    int i, data;
    cin >> i >> data;
    Node* node = new Node(data);
    head = RR_insert_ith(head, i, node);
    print(head);
}
