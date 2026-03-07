#include <iostream>
#include <string>
using namespace std;

struct Player {
    string name;
    int score;
    Player* prev;
    Player* next;
};

Player* createPlayer(string name, int score) {
    Player* newP = new Player();
    newP->name = name;
    newP->score = score;
    newP->prev = nullptr;
    newP->next = nullptr;
    return newP;
}

void insertPlayer(Player*& head, string name, int score) {
    Player* newP = createPlayer(name, score);
    if (head == nullptr || score < head->score) {
        newP->next = head;
        if (head != nullptr) head->prev = newP;
        head = newP;
        return;
    }
    Player* temp = head;
    while (temp->next != nullptr && temp->next->score <= score)
        temp = temp->next;
    newP->next = temp->next;
    if (temp->next != nullptr) temp->next->prev = newP;
    temp->next = newP;
    newP->prev = temp;
}

void deletePlayer(Player*& head, string name) {
    Player* temp = head;
    while (temp != nullptr && temp->name != name)
        temp = temp->next;
    if (temp == nullptr) {
        cout << "Player not found!\n";
        return;
    }
    if (temp->prev) temp->prev->next = temp->next;
    else head = temp->next;
    if (temp->next) temp->next->prev = temp->prev;
    delete temp;
}

void displayAll(Player* head) {
    cout << "Players list:\n";
    while (head != nullptr) {
        cout << head->name << " - " << head->score << endl;
        head = head->next;
    }
}

void displayLowest(Player* head) {
    if (head == nullptr) return;
    cout << "Lowest score: " << head->name << " - " << head->score << endl;
}

void displaySameScore(Player* head, int score) {
    cout << "Players with score " << score << ":\n";
    while (head != nullptr) {
        if (head->score == score)
            cout << head->name << endl;
        head = head->next;
    }
}

void displayBackward(Player* head, string name) {
    Player* temp = head;
    while (temp != nullptr && temp->name != name)
        temp = temp->next;
    if (temp == nullptr) {
        cout << "Player not found!\n";
        return;
    }
    cout << "Backward from " << name << ":\n";
    while (temp != nullptr) {
        cout << temp->name << " - " << temp->score << endl;
        temp = temp->prev;
    }
}

int main() {
    Player* head = nullptr;

    insertPlayer(head, "Ali", 70);
    insertPlayer(head, "Sara", 65);
    insertPlayer(head, "Ahmed", 80);
    insertPlayer(head, "Laiba", 65);

    displayAll(head);
    displayLowest(head);
    displaySameScore(head, 65);
    displayBackward(head, "Ahmed");

    deletePlayer(head, "Sara");
    displayAll(head);

    return 0;
}