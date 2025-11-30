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

int getSize(Node* head) {
    int count = 0;
    Node* curr = new Node;
    curr = head;
    while(curr) {
        count++;
        curr = curr->next;
    }
    return count;
}

int main() {
    Node* head = new Node(20);
    Node* second = new Node(100);
    Node* third = new Node(30);
    Node* fourth = new Node(80);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = nullptr;
    
    cout<<"Size = "<< getSize(head);
    return 0;
}