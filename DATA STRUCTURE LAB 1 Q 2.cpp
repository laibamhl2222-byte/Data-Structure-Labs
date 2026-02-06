#include <iostream>
#include <vector>
using namespace std;

int main() {

    vector<int> arr = { 10, 20, 30 };

    cout << "Original array: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int index, newValue;
    cout << "Enter the index to update (0-" << arr.size() - 1 << "): ";
    cin >> index;
    cout << "Enter the new value: ";
    cin >> newValue;

    if (index >= 0 && index < arr.size()) {
        arr[index] = newValue;
    }
    else {
        cout << "Invalid index!" << endl;
        return 0;
    }

    cout << "Updated array: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}