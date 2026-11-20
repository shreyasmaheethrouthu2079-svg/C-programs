#include <iostream>
#include <string>

using namespace std;

// DIY 5.3: Unique ID factory
// Use a static member so every new Order object automatically receives
// the next ID (1001, 1002, ...) in its constructor.

class Order {
private:
    int orderId;
    string item;
    double amount;

    static int nextId; // static ID generator

public:
    Order(const string &itm, double amt) : item(itm), amount(amt) {
        orderId = nextId++; // automatically mint next unique ID
    }

    void display() const {
        cout << "Order ID: " << orderId
             << " | Item: " << item
             << " | Amount: Rs. " << amount << endl;
    }
};

// Initialize starting ID
int Order::nextId = 1001;

int main() {
    Order o1("Oscilloscope", 35000.0);
    Order o2("FPGA Development Board", 12500.0);
    Order o3("Logic Analyzer", 8200.0);

    o1.display();
    o2.display();
    o3.display();

    return 0;
}
