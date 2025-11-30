#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int value = 0) {
        val = value;
        next = nullptr;
    }
};

bool isCircular(Node* head) {
    if (head == nullptr) return false;

    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }

    return false; 
}


int main() {
    Node* head = new Node(20);
    Node* second = new Node(100);
    Node* third = new Node(30);
    Node* fourth = new Node(80);
    Node* fifth = new Node(50);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth -> next = head;

    cout << isCircular(head);
    return 0;
}