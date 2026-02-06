#include <iostream>
using namespace std;

int main() {
    int arr[5] = { 10, 20, 30, 40, 50 };

    int* ptr = arr;

    cout << "Array elements using pointer: ";
    for (int i = 0; i < 5; i++) {
        cout << *(ptr + i) << " ";  
    }
    cout << endl;

    return 0;
}
