#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *head=nullptr;

void insertAtEnd(int val)
{
    Node *newNode=new Node();
    newNode->data=val;
    newNode->next=nullptr;
    if (head==nullptr)
    {
        head=newNode;
        return;
    }
    Node *temp=head;
    while (temp->next != nullptr)
        temp=temp->next;
    temp->next=newNode;
}

int countKey(int key)
{
    int count=0;
    Node *temp=head;
    while (temp != nullptr)
    {
        if (temp->data==key)
            count++;
        temp=temp->next;
    }
    return count;
}

void deleteAllOccurrences(int key)
{
    while (head != nullptr && head->data==key)
    {
        Node *temp=head;
        head=head->next;
        delete temp;
    }
    Node *curr=head;
    Node *prev=nullptr;
    while (curr != nullptr)
    {
        if (curr->data==key)
        {
            prev->next=curr->next;
            delete curr;
            curr=prev->next;
        }
        else
        {
            prev=curr;
            curr=curr->next;
        }
    }
}

void displayList()
{
    if (head==nullptr)
    {
        cout<<"List is empty.\n";
        return;
    }
    Node *temp=head;
    while (temp != nullptr)
    {
        cout<<temp->data;
        if (temp->next != nullptr)
            cout<<"->";
        temp=temp->next;
    }
    cout<<endl;
}

int main()
{
    int n, val, key;
    cout<<"Enter number of elements in linked list: ";
    cin >> n;
    cout<<"Enter elements:\n";
    for (int i=0; i < n; i++)
    {
        cin >> val;
        insertAtEnd(val);
    }

    cout<<"Enter key to count and delete: ";
    cin >> key;

    int count=countKey(key);
    cout<<"Count: "<<count<<endl;

    deleteAllOccurrences(key);

    cout<<"Updated Linked List: ";
    displayList();

    return 0;
}
