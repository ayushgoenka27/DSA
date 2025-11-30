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

bool isEvenParity(int x) {
    int parity = 0;
    while(x != 0) {
        if(x & 1){
            parity++;
        }
        x = x >> 1;
    }
    return (parity % 2 == 0);
}

Node* deleteNodes(Node* head) {
    Node* curr = head;

    while (curr != nullptr) {
        if (isEvenParity(curr->val)) {
            Node* toDelete = curr;

            if (curr->prev != nullptr)
                curr->prev->next = curr->next;
            else
                head = curr->next;

            if (curr->next != nullptr)
                curr->next->prev = curr->prev;

            curr = curr->next;
            delete toDelete;
        } else {
            curr = curr->next;
        }
    }
    return head;
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
    Node* head = new Node(20);
    Node* second = new Node(100);
    Node* third = new Node(100);
    Node* fourth = new Node(20);

    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;
    third->next = fourth;
    fourth->prev = third;

    cout << "Original list: ";
    printList(head);

    head = deleteNodes(head);

    cout << "After deletion: ";
    printList(head);

    return 0;
}
