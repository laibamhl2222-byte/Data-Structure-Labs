#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    return newNode;
}

void insertAtEnd(Node*& head, int value) {
    Node* newNode = createNode(value);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

void display(Node* head) {
    cout << "Rainfall data: ";
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    int rainfall, total = 0;

    cout << "Enter rainfall for 7 days:\n";
    for (int i = 1; i <= 7; i++) {
        cin >> rainfall;
        if (rainfall < 0) {
            cout << "Invalid input! Enter non-negative.\n";
            i--; continue;
        }
        insertAtEnd(head, rainfall);
        total += rainfall;
    }

    display(head);

    cout << "Total rainfall: " << total << endl;
    cout << "Average rainfall: " << total / 7.0 << endl;

    Node* temp = head;
    int high = temp->data, low = temp->data, dayHigh = 1, dayLow = 1, day = 1;
    while (temp != nullptr) {
        if (temp->data > high) { high = temp->data; dayHigh = day; }
        if (temp->data < low) { low = temp->data; dayLow = day; }
        temp = temp->next; day++;
    }
    cout << "Highest rainfall: " << high << " on day " << dayHigh << endl;
    cout << "Lowest rainfall: " << low << " on day " << dayLow << endl;

    temp = head;
    for (int i = 1; temp != nullptr && i < 6; i++) temp = temp->next;
    if (temp != nullptr)
        cout << "Rainfall after 5th day: " << temp->data << endl;

    return 0;
}