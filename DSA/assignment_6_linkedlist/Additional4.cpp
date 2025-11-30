#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node* prev;
    Node(int value = 0) {
        val = value;
        next = nullptr;
        prev = nullptr;
    }
};

void correctPrevPointers(Node* head) {
    Node* curr = head;
    while (curr && curr->next) {
        if (curr->next->prev != curr)
            curr->next->prev = curr;
        curr = curr->next;
    }
}

void correctNextPointers(Node* head) {
    Node* curr = head;
    while(curr->next!=nullptr) {
        curr = curr->next;
    }
    while(curr->prev) {
    if (curr->prev->next!=curr) {
        curr->prev->next = curr;
    }
        curr = curr->prev;
    }
    
}

void printList(Node* head) {
    Node* curr = head;
    while (curr) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}

void printListReverse(Node* head) {
    Node* curr = head;
    if (!curr) return;
    while (curr->next) curr = curr->next;
    while (curr) {
        cout << curr->val << " ";
        curr = curr->prev;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);

    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = head;  // wrong prev pointer
    third->next = fourth;
    fourth->prev = third;

    cout << "Before correction: ";
    printList(head);
    printListReverse(head);

    correctPrevPointers(head);
    correctNextPointers(head);

    cout << "After correction: ";
    printList(head);
    printListReverse(head);

    return 0;
}
