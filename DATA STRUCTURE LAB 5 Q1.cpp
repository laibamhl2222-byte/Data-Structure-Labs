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

void insertAtBeginning(Node*& head, int value) {
    Node* newNode = createNode(value);
    if (head != nullptr) {
        newNode->next = head;
        head->prev = newNode;
    }
    head = newNode;
}

void insertAfterValue(Node*& head, int value, int afterVal) {
    Node* temp = head;
    while (temp != nullptr && temp->data != afterVal)
        temp = temp->next;

    if (temp == nullptr) {
        cout << "Value " << afterVal << " not found!\n";
        return;
    }

    Node* newNode = createNode(value);
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != nullptr)
        temp->next->prev = newNode;
    temp->next = newNode;
}

void deleteFromBeginning(Node*& head) {
    if (head == nullptr) return;
    Node* temp = head;
    head = head->next;
    if (head != nullptr) head->prev = nullptr;
    delete temp;
}

void deleteAfterValue(Node*& head, int afterVal) {
    Node* temp = head;
    while (temp != nullptr && temp->data != afterVal)
        temp = temp->next;

    if (temp == nullptr || temp->next == nullptr) {
        cout << "Deletion not possible!\n";
        return;
    }

    Node* delNode = temp->next;
    temp->next = delNode->next;
    if (delNode->next != nullptr)
        delNode->next->prev = temp;
    delete delNode;
}

void display(Node* head) {
    cout << "List: ";
    while (head != nullptr) {
        cout << head->data << " <-> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = nullptr;

    int n, val;
    cout << "Enter number of marks: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> val;
        insertAtBeginning(head, val); 
    }

    display(head);

    insertAtBeginning(head, 100); 
    insertAfterValue(head, 200, 45);
    display(head);

    deleteFromBeginning(head);
    deleteAfterValue(head, 45);
    display(head);

    return 0;
}