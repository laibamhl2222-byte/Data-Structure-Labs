#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* front = nullptr;
Node* rear = nullptr;

void enqueue(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    if (rear == nullptr) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    cout << value << " inserted into queue.\n";
}

void dequeue() {
    if (front == nullptr) {
        cout << "Queue Underflow!\n";
        return;
    }
    Node* temp = front;
    cout << front->data << " removed from queue.\n";
    front = front->next;
    if (front == nullptr) rear = nullptr;
    delete temp;
}

void display() {
    if (front == nullptr) {
        cout << "Queue is empty.\n";
        return;
    }
    cout << "Queue elements: ";
    Node* temp = front;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    display();
    return 0;
}
