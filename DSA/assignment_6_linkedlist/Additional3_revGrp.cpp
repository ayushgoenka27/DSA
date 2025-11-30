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

Node* reverseKGroup(Node* head, int k) {
    if (!head || k <= 1) return head;

    Node* curr = head;
    Node* newHead = nullptr;
    Node* groupPrev = nullptr;

    while (curr != nullptr) {
        Node* groupStart = curr;
        int count = 0;

        // Count k nodes in this group
        while (curr != nullptr && count < k) {
            curr = curr->next;
            count++;
        }

        Node* groupEnd = curr;
        Node* prev = groupEnd;
        Node* temp = groupStart;
        for (int i = 0; i < count; i++) {
            Node* nextNode = temp->next;
            temp->next = prev;
            if (prev) prev->prev = temp;
            temp->prev = nextNode;
            prev = temp;
            temp = nextNode;
        }

        if (!newHead) newHead = prev;

        if (groupPrev) groupPrev->next = prev;
        prev->prev = groupPrev;

        groupPrev = groupStart;
    }

    return newHead;
}

void printList(Node *head) { 
    Node *curr = head; 
    while (curr != nullptr) { 
        cout << curr->val << " "; 
        curr = curr->next; 
    } 
    cout << endl;
} 

int main() {
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);

    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;
    third->next = fourth;
    fourth->prev = third;
    fourth->next = fifth;
    fifth->prev = fourth;

    cout << "Original list: ";
    printList(head);

    int k = 2;
    head = reverseKGroup(head, k);

    cout << "After reversing every " << k << " nodes: ";
    printList(head);

    return 0;
}
