#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class GarageSystem {
private:
    queue<int> road;
    stack<int> garage;
public:
    void onRoad(int id) {
        road.push(id);
    }

    void showRoad() {
        cout << "Road Vehicles: ";
        queue<int> temp = road;
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }

    void showGarage() {
        cout << "Garage Vehicles: ";
        stack<int> temp = garage;
        if (temp.empty()) cout << "Empty";
        while (!temp.empty()) {
            cout << temp.top() << " ";
            temp.pop();
        }
        cout << endl;
    }

    void enterGarage(int id) {
        if (road.empty() || road.front() != id) {
            cout << "Error: " << id << " cannot enter garage.\n";
            return;
        }
        road.pop();
        garage.push(id);
        cout << id << " entered garage.\n";
    }

    void exitGarage(int id) {
        if (garage.empty() || garage.top() != id) {
            cout << "Error: " << id << " cannot exit garage.\n";
            return;
        }
        cout << id << " leaving garage.\n";
        garage.pop();
    }
};

int main() {
    GarageSystem g;
    g.onRoad(2);
    g.onRoad(5);
    g.onRoad(10);
    g.onRoad(9);
    g.onRoad(22);

    g.showRoad();
    g.showGarage();

    g.enterGarage(2);
    g.showRoad();
    g.showGarage();

    g.enterGarage(10); 
    g.enterGarage(5);

    g.exitGarage(2);   
    g.exitGarage(5);

    g.showGarage();

    return 0;
}
