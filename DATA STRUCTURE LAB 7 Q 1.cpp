#include <iostream>
#include <string>
using namespace std;

class Book {
public:
    string title;
    float price;
    int edition;
    int pages;

    Book() {}
    Book(string t, float p, int e, int pg) {
        title = t;
        price = p;
        edition = e;
        pages = pg;
    }

    void display() {
        cout << "Title: " << title
            << ", Price: " << price
            << ", Edition: " << edition
            << ", Pages: " << pages << endl;
    }
};

class BookStack {
private:
    Book stack[10];   // fixed size stack
    int top;

public:
    BookStack() { top = -1; }

    void push(Book b) {
        if (top == 9) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        stack[++top] = b;
    }

    void pop() {
        if (top == -1) {
            cout << "Stack Underflow!" << endl;
            return;
        }
        cout << "Popped Book: ";
        stack[top--].display();
    }

    void peek() {
        if (top == -1) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Top Book: ";
        stack[top].display();
    }

    void displayAll() {
        if (top == -1) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "\nBooks in Stack:\n";
        for (int i = top; i >= 0; i--) {
            stack[i].display();
        }
    }
};

int main() {
    BookStack bs;

    // Push 5 books
    bs.push(Book("C++ Basics", 500, 1, 300));
    bs.push(Book("Data Structures", 700, 2, 450));
    bs.push(Book("Algorithms", 800, 3, 500));
    bs.push(Book("Operating Systems", 650, 2, 400));
    bs.push(Book("Computer Networks", 600, 1, 350));

    // Find top element
    bs.peek();

    // Pop 2 books
    bs.pop();
    bs.pop();

    // Display remaining books
    bs.displayAll();

    return 0;
}