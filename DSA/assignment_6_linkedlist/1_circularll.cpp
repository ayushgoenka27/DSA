#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;
};

// Function to create a new node
Node* createNode(int val) {
    Node* temp = new Node;
    temp->val = val;
    temp->next = nullptr;
    return temp;
}

// Insert at the beginning
void insertAtStart(Node*& head, int val) {
    Node* newNode = createNode(val);
    if (head == nullptr) {
        head = newNode;
        newNode->next = head;
        return;
    }
    Node* curr = head;
    while (curr->next != head)
        curr = curr->next;

    curr->next = newNode;
    newNode->next = head;
    head = newNode;
}

// Insert at the end
void insertAtEnd(Node*& head, int val) {
    Node* newNode = createNode(val);
    if (head == nullptr) {
        head = newNode;
        newNode->next = head;
        return;
    }
    Node* curr = head;
    while (curr->next != head)
        curr = curr->next;

    curr->next = newNode;
    newNode->next = head;
}

// Insert after a specific value
void insertAfter(Node*& head, int value, int val) {
    if (head == nullptr) {
        cout << "List empty!\n";
        return;
    }
    Node* curr = head;
    do {
        if (curr->val == value) {
            Node* newNode = createNode(val);
            newNode->next = curr->next;
            curr->next = newNode;
            return;
        }
        curr = curr->next;
    } while (curr != head);
    cout << "Value not found!\n";
}

// Delete a specific node
void deleteNode(Node*& head, int value) {
    if (head == nullptr) {
        cout << "List empty!\n";
        return;
    }
    Node* curr = head;
    Node* prev = nullptr;

    // Special case: deleting head
    if (head->val == value) {
        Node* last = head;
        while (last->next != head)
            last = last->next;
        if (head->next == head) {
            delete head;
            head = nullptr;
            return;
        }
        last->next = head->next;
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    // Traverse normally
    do {
        prev = curr;
        curr = curr->next;
        if (curr->val == value) {
            prev->next = curr->next;
            delete curr;
            return;
        }
    } while (curr != head);

    cout << "Value not found!\n";
}

// Search for a node
bool search(Node* head, int value) {
    if (head == nullptr) return false;
    Node* curr = head;
    do {
        if (curr->val == value)
            return true;
        curr = curr->next;
    } while (curr != head);
    return false;
}

// Display list
void display(Node* head) {
    if (head == nullptr) {
        cout << "List empty!\n";
        return;
    }
    Node* curr = head;
    cout << "List: ";
    do {
        cout << curr->val << " ";
        curr = curr->next;
    } while (curr != head);
    cout << endl;
}

// =============================
// MAIN MENU
// =============================
int main() {
    Node* head = nullptr;
    int choice, val, pos;

    do {
        cout << "\n==== Circular Linked List Menu ====\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert After a Node\n";
        cout << "4. Delete a Node\n";
        cout << "5. Search a Node\n";
        cout << "6. Display List\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                insertAtStart(head, val);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> val;
                insertAtEnd(head, val);
                break;
            case 3:
                cout << "Enter value to insert after: ";
                cin >> pos;
                cout << "Enter new value: ";
                cin >> val;
                insertAfter(head, pos, val);
                break;
            case 4:
                cout << "Enter value to delete: ";
                cin >> val;
                deleteNode(head, val);
                break;
            case 5:
                cout << "Enter value to search: ";
                cin >> val;
                cout << (search(head, val) ? "Found!\n" : "Not found!\n");
                break;
            case 6:
                display(head);
                break;
            case 7:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 7);

    return 0;
}
