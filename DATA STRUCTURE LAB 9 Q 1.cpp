#include <iostream>
using namespace std;

struct Applicant {
    int id;
    float height;
    float weight;
    float eyesight;
    string status;
    Applicant* next;
    Applicant* prev;
};

class ApplicantQueue {
private:
    Applicant* front;
    Applicant* rear;
public:
    ApplicantQueue() {
        front = rear = NULL;
    }

    bool isEmpty() {
        return front == NULL;
    }

    void enqueue(int id, float h, float w, float e, string s) {
        Applicant* temp = new Applicant;
        temp->id = id;
        temp->height = h;
        temp->weight = w;
        temp->eyesight = e;
        temp->status = s;
        temp->next = NULL;
        temp->prev = rear;

        if (rear != NULL) rear->next = temp;
        rear = temp;
        if (front == NULL) front = temp;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue empty\n";
            return;
        }
        Applicant* temp = front;
        cout << "Applicant " << temp->id << " leaves queue.\n";
        front = front->next;
        if (front != NULL) front->prev = NULL;
        else rear = NULL;
        delete temp;
    }

    void removeSecond() {
        if (front == NULL || front->next == NULL) {
            cout << "No second applicant to remove.\n";
            return;
        }
        Applicant* second = front->next;
        cout << "Applicant " << second->id << " had urgency and left.\n";
        front->next = second->next;
        if (second->next != NULL) second->next->prev = front;
        else rear = front;
        delete second;
    }

    void display() {
        Applicant* temp = front;
        cout << "Queue: ";
        while (temp != NULL) {
            cout << temp->id << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    ApplicantQueue q;
    q.enqueue(1, 5.8, 70, 6, "waiting");
    q.enqueue(2, 5.7, 65, 6, "waiting");
    q.enqueue(3, 6.0, 80, 6, "waiting");
    q.enqueue(4, 5.6, 60, 6, "waiting");

    q.display();
    q.removeSecond();
    q.display();
    q.dequeue();
    q.display();

    return 0;
}
