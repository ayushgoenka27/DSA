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

int getSize(Node* head) {
    int count = 0;
    Node* curr = new Node;
    curr = head;
    do{
        count++;
        curr = curr->next;
    } while(curr!=head);
    return count;
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
    
    cout<<"Size = "<< getSize(head);
    return 0;
}