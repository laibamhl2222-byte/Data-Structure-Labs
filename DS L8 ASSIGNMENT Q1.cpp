#include <iostream>
using namespace std;

class CircularQueue {
    int size;
    int front, rear;
    int* arr;

public:
    CircularQueue(int s) {
        size = s;
        arr = new int[size];
        front = -1;
        rear = -1;
        for (int i = 0; i < size; i++) arr[i] = -1;
    }

    ~CircularQueue() {
        delete[] arr; // free memory
    }

    bool isFull() {
        return (front == (rear + 1) % size);
    }

    bool isEmpty() {
        return (front == -1);
    }

    void enQueue(int value) {
        if (isFull()) {
            cout << "Queue is full! Cannot insert " << value << endl;
            return;
        }
        if (isEmpty()) {
            front = 0;
            rear = 0;
        }
        else {
            rear = (rear + 1) % size;
        }
        arr[rear] = value;
        display("enQueue", value);
    }

    void deQueue() {
        if (isEmpty()) {
            cout << "Queue is empty! Cannot dequeue" << endl;
            return;
        }
        int removed = arr[front];
        arr[front] = -1;
        if (front == rear) {
            front = -1;
            rear = -1;
        }
        else {
            front = (front + 1) % size;
        }
        display("deQueue", removed);
    }

    void display(string operation, int value) {
        cout << operation << "(" << value << ")" << endl;
        cout << "Array: ";
        for (int i = 0; i < size; i++) {
            if (arr[i] == -1) cout << "[ ] ";
            else cout << "[" << arr[i] << "] ";
        }
        cout << endl;

        if (!isEmpty()) {
            cout << "Front value: " << arr[front] << endl;
            cout << "Rear value: " << arr[rear] << endl;
        }
        else {
            cout << "Queue is empty" << endl;
        }
        cout << "-----------------------------------" << endl;
    }
};

int main() {
    CircularQueue q(5);

    q.enQueue(10);
    q.enQueue(20);
    q.enQueue(30);
    q.deQueue();
    q.enQueue(40);
    q.enQueue(50);
    q.enQueue(60); // works in circular queue
    q.deQueue();
    q.enQueue(70);

    return 0;
}

