#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, searchElement, index = -1;

    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> arr(n); 

  
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the element to search: ";
    cin >> searchElement;

    for (int i = 0; i < n; i++) {
        if (arr[i] == searchElement) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        cout << "Element found at index: " << index << endl;
    }
    else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}