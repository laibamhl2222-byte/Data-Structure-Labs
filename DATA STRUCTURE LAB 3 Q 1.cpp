#include <iostream>
#include <string>
using namespace std;

struct Product {
    string name;
    int code;
    float price;
};

int main() {
    int n;
    cout << "Enter number of products: ";
    cin >> n;

    Product* products = new Product[n]; 

    for (int i = 0; i < n; i++) {
        cout << "Enter product " << i + 1 << " name: ";
        cin >> products[i].name;
        cout << "Enter product " << i + 1 << " code: ";
        cin >> products[i].code;
        cout << "Enter product " << i + 1 << " price: ";
        cin >> products[i].price;
    }

    cout << "\n--- Product List ---\n";
    for (int i = 0; i < n; i++) {
        cout << "Name: " << products[i].name
            << ", Code: " << products[i].code
            << ", Price: " << products[i].price << endl;
    }

    delete[] products; 
    return 0;
}