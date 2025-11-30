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

vector<Node*> split(Node* head) {
    vector<Node*> res;
    if (head == nullptr) return res;

    Node* fast = head;
    Node* slow = head;

    while (fast->next != head && fast->next->next != head) {
        fast = fast->next->next;
        slow = slow->next;
    }

    if (fast->next->next == head)
        fast = fast->next;

    Node* head1 = head;
    Node* head2 = slow->next;

    slow->next = head1;

    fast->next = head2;

    res.push_back(head1);
    res.push_back(head2);

    return res;
}

void printList(Node *head) { 
    Node *curr = head; 
    if (head != nullptr) { 
        do { 
            cout << curr->val << " "; 
            curr = curr->next; 
        } while (curr != head); 
        cout << endl; 
    } 
} 

int main() { 
    Node *head = new Node(1); 
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = head;

    vector<Node*> res = split(head); 
    
    printList(res[0]); 
    printList(res[1]);
    
    return 0; 
}
