#include <bits/stdc++.h>
using namespace std;
int max_size = 10;
struct circQueue{
int front;
int rear;
int arr[10];
circQueue() {
    front = -1;
    rear = -1;
}
void enqueue(int val) {
    if (front == (rear + 1) % max_size) {
        cout << "Overflow" << endl;
    } else {
        rear = (rear + 1) % max_size;
        arr[rear] = val;
    }
    if (front == -1) {
        front = 0;
    }
}
int dequeue() {
    if (front == rear && rear == -1) {
        cout << "Underflow";
    } else if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % max_size;
    }
}
bool isEmpty() {
    if (front == rear && rear == -1) {
        return true;
    }
    return false;
}
bool isFull() {
    if (front == (rear + 1) % max_size) {
        return true;
    }
    return false;
}

};
int main() {
cout << "Hello World" << endl;

    return 0;
}