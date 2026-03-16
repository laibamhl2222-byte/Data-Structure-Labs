#include <iostream>
using namespace std;

class Inventory {
public:
    int serialNum;
    int manufactYear;
    int lotNum;

    Inventory() {}
    Inventory(int s, int y, int l) {
        serialNum = s;
        manufactYear = y;
        lotNum = l;
    }

    void display() {
        cout << "Serial: " << serialNum
            << ", Year: " << manufactYear
            << ", Lot: " << lotNum << endl;
    }
};

class Node {
public:
    Inventory data;
    Node* next;

    Node(Inventory inv) {
        data = inv;
        next = nullptr;
    }
};

class InventoryStack {
private:
    Node* top;

public:
    InventoryStack() { top = nullptr; }

    void push(Inventory inv) {
        Node* newNode = new Node(inv);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (top == nullptr) {
            cout << "Stack Underflow!" << endl;
            return;
        }
        cout << "Popped Part: ";
        top->data.display();
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    void displayAll() {
        if (top == nullptr) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "\nRemaining Inventory:\n";
        Node* current = top;
        while (current != nullptr) {
            current->data.display();
            current = current->next;
        }
    }
};

int main() {
    InventoryStack invStack;
    int choice;

    do {
        cout << "\n1. Add Part\n2. Remove Part\n3. Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            int s, y, l;
            cout << "Enter Serial Number: ";
            cin >> s;
            cout << "Enter Manufacture Year: ";
            cin >> y;
            cout << "Enter Lot Number: ";
            cin >> l;
            invStack.push(Inventory(s, y, l));
        }
        else if (choice == 2) {
            invStack.pop();
        }
    } while (choice != 3);

    // Display remaining parts
    invStack.displayAll();

    return 0;
}