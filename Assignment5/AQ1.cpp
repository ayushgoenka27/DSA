#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *head=nullptr;

void insertAtBeginning(int val)
{
    Node *newNode=new Node();
    newNode->data=val;
    newNode->next=head;
    head=newNode;
    cout<<val<<" inserted at the beginning.\n";
}

void insertAtEnd(int val)
{
    Node *newNode=new Node();
    newNode->data=val;
    newNode->next=nullptr;
    if (head==nullptr)
    {
        head=newNode;
    }
    else
    {
        Node *temp=head;
        while (temp->next != nullptr)
            temp=temp->next;
        temp->next=newNode;
    }
    cout<<val<<" inserted at the end.\n";
}

void insertBeforeAfter(int val, int target, bool after)
{
    Node *newNode=new Node();
    newNode->data=val;

    if (head==nullptr)
    {
        cout<<"List is empty. Cannot insert.\n";
        delete newNode;
        return;
    }

    Node *temp=head;
    Node *prev=nullptr;
    while (temp != nullptr && temp->data != target)
    {
        prev=temp;
        temp=temp->next;
    }

    if (temp==nullptr)
    {
        cout<<"Target node not found.\n";
        delete newNode;
        return;
    }

    if (after)
    {
        newNode->next=temp->next;
        temp->next=newNode;
        cout<<val<<" inserted after "<<target<<".\n";
    }
    else
    {
        if (temp==head)
        { 
            newNode->next=head;
            head=newNode;
        }
        else
        {
            newNode->next=temp;
            prev->next=newNode;
        }
        cout<<val<<" inserted before "<<target<<".\n";
    }
}

void deleteFromBeginning()
{
    if (head==nullptr)
    {
        cout<<"List is empty.\n";
        return;
    }
    Node *temp=head;
    head=head->next;
    cout<<temp->data<<" deleted from beginning.\n";
    delete temp;
}

void deleteFromEnd()
{
    if (head==nullptr)
    {
        cout<<"List is empty.\n";
        return;
    }
    if (head->next==nullptr)
    {
        cout<<head->data<<" deleted from end.\n";
        delete head;
        head=nullptr;
        return;
    }
    Node *temp=head;
    Node *prev=nullptr;
    while (temp->next != nullptr)
    {
        prev=temp;
        temp=temp->next;
    }
    prev->next=nullptr;
    cout<<temp->data<<" deleted from end.\n";
    delete temp;
}

void deleteSpecificNode(int val)
{
    if (head==nullptr)
    {
        cout<<"List is empty.\n";
        return;
    }
    Node *temp=head;
    Node *prev=nullptr;

    while (temp != nullptr && temp->data != val)
    {
        prev=temp;
        temp=temp->next;
    }

    if (temp==nullptr)
    {
        cout<<"Node "<<val<<" not found.\n";
        return;
    }

    if (temp==head)
    {
        head=head->next;
    }
    else
    {
        prev->next=temp->next;
    }
    cout<<"Node "<<val<<" deleted.\n";
    delete temp;
}

void searchNode(int val)
{
    Node *temp=head;
    int pos=1;
    while (temp != nullptr)
    {
        if (temp->data==val)
        {
            cout<<"Node "<<val<<" found at position "<<pos<<".\n";
            return;
        }
        temp=temp->next;
        pos++;
    }
    cout<<"Node "<<val<<" not found.\n";
}

void displayList()
{
    if (head==nullptr)
    {
        cout<<"List is empty.\n";
        return;
    }
    Node *temp=head;
    cout<<"Linked List: ";
    while (temp != nullptr)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main()
{
    int choice, val, target;
    bool after;

    do
    {
        cout<<"Singly Linked List Menu \n";
        cout<<"1. Insert at Beginning\n";
        cout<<"2. Insert at End\n";
        cout<<"3. Insert Before/After a Node\n";
        cout<<"4. Delete from Beginning\n";
        cout<<"5. Delete from End\n";
        cout<<"6. Delete a Specific Node\n";
        cout<<"7. Search for a Node\n";
        cout<<"8. Display List\n";
        cout<<"9. Exit\n";
        cout<<"Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout<<"Enter value to insert: ";
            cin >> val;
            insertAtBeginning(val);
            break;
        case 2:
            cout<<"Enter value to insert: ";
            cin >> val;
            insertAtEnd(val);
            break;
        case 3:
            cout<<"Enter value to insert: ";
            cin >> val;
            cout<<"Enter target node value: ";
            cin >> target;
            cout<<"Insert after target? (1 for yes, 0 for before): ";
            cin >> after;
            insertBeforeAfter(val, target, after);
            break;
        case 4:
            deleteFromBeginning();
            break;
        case 5:
            deleteFromEnd();
            break;
        case 6:
            cout<<"Enter value to delete: ";
            cin >> val;
            deleteSpecificNode(val);
            break;
        case 7:
            cout<<"Enter value to search: ";
            cin >> val;
            searchNode(val);
            break;
        case 8:
            displayList();
            break;
        case 9:
            cout<<"Exited";
            break;
        default:
            cout<<"Invalid choice. Try again.\n";
        }
    } while (choice != 9);

    return 0;
}
