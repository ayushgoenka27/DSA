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
void displayCirculr(Node* head) {
    Node* curr = new Node;
    curr = head;
    if (head == nullptr){
        cout << " ";
        return;
    } 
    curr = curr->next;
    cout << head->val<< " ";
    while(curr!=head) {
        cout << curr->val<< " ";
        curr = curr->next;
    }
    cout << curr->val;
}

int main() {
    Node* head = new Node(20);
    Node* second = new Node(100);
    Node* third = new Node(30);
    Node* fourth = new Node(80);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = head;
    
    displayCirculr(head);
    return 0;
}