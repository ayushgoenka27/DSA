#include <bits/stdc++.h>
using namespace std;
int MAX_SIZE = 10;
struct Queue {
    int arr[10];
    int front;
    int rear;
    Queue() {
        front = -1;
        rear = -1;
    }
    void enqueue(int val) {
        if (rear == MAX_SIZE - 1) {
            cout << "Overflow";
        } else {
            rear++;
            arr[rear] = val;

        }
        if (front == -1) {
            front = 0;
        }
    }

    int dequeue() {
        int temp;
        if (front == rear && rear == -1) {
            cout << "Underflow";
        } else {
            temp = arr[front];
            front++;
        }
        return temp;
    }
    bool isEmpty() {
        if (front == rear && rear == -1) {
            return true;
        } 
        return false;
    }
    bool isFull() {
        if (rear == MAX_SIZE-1) {
            return true;
        }
        return false;
    }
    void display() {
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    int peek() {
        return arr[front];
    }
};



int main() {
    Queue q;
    cout << q.isEmpty();
    cout << q.isFull();
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    cout << q.dequeue() << endl;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    return 0;
}