#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

Node* bubbleSortLinkedList(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    bool swapped;
    Node* current;
    Node* previous = nullptr;
    Node* tail = nullptr;

    do {
        swapped = false;
        current = head;

        while (current->next != tail) {
            if (current->data > current->next->data) {
                if (previous != nullptr) {
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
        tail = current;
    } while (swapped);

    return head;
}

void printLinkedList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void deleteLinkedList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}

int main() {
    // Create a sample linked list
    Node* head = new Node(5);
    head->next = new Node(3);
    head->next->next = new Node(8);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(6);

    cout << "Original linked list: ";
    printLinkedList(head);

    // Perform bubble sort on the linked list
    head = bubbleSortLinkedList(head);

    cout << "Sorted linked list: ";
    printLinkedList(head);

    // Clean up the linked list
    deleteLinkedList(head);

    return 0;
}
