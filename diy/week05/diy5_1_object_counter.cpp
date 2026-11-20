#include <iostream>

using namespace std;

// DIY 5.1: Object counter
// Add a static member to Counter class that reports how many Counter objects
// have ever been created and how many are currently alive.

class Counter {
private:
    int val;
    static int totalCreated;
    static int currentlyAlive;

public:
    Counter(int v = 0) : val(v) {
        totalCreated++;
        currentlyAlive++;
    }

    ~Counter() {
        currentlyAlive--;
    }

    void increment() { val++; }
    int get() const { return val; }

    static int getTotalCreated() { return totalCreated; }
    static int getCurrentlyAlive() { return currentlyAlive; }
};

// Define and initialize static members outside the class
int Counter::totalCreated = 0;
int Counter::currentlyAlive = 0;

int main() {
    cout << "Initial: Created=" << Counter::getTotalCreated()
         << ", Alive=" << Counter::getCurrentlyAlive() << endl;

    Counter c1, c2;
    cout << "After c1, c2: Created=" << Counter::getTotalCreated()
         << ", Alive=" << Counter::getCurrentlyAlive() << endl;

    {
        Counter c3;
        cout << "Inside block (with c3): Created=" << Counter::getTotalCreated()
             << ", Alive=" << Counter::getCurrentlyAlive() << endl;
    } // c3 is destroyed here

    cout << "After block exit: Created=" << Counter::getTotalCreated()
         << ", Alive=" << Counter::getCurrentlyAlive() << endl;

    return 0;
}
