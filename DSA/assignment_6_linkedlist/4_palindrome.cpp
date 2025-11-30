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

bool checkPalindrome(Node* head) {
    Node* front = new Node;
    Node* back = new Node;
    front = head;
    Node* curr = new Node;
    curr = head;
    
    while(curr->next != nullptr) {
        curr = curr->next;
    }
    back = curr;
    
    while(front != back && front->prev != back) {
        if (front->val != back->val) {
            return false;
        }
        front = front->next;
        back = back->prev;
    }
    return true;
}

int main() {

    Node* head = new Node(20);
    Node* second = new Node(100);
    Node* third = new Node(100);
    Node* fourth = new Node(20);

    head->next = second;
    head->prev = nullptr;
    second->next = third;
    second->prev = head;
    third->next = fourth;
    third->prev = second;
    fourth->next = nullptr;
    fourth->prev= third;

    cout << checkPalindrome(head);

    return 0;
}