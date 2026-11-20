#include <iostream>

using namespace std;

// DIY 3.2: Counter array
// A Counter class with increment(), reset() and get();
// create an array of 3 counters and exercise them.

class Counter {
private:
    int count;

public:
    Counter(int initial = 0) : count(initial) {}

    void increment() {
        count++;
    }

    void reset() {
        count = 0;
    }

    int get() const {
        return count;
    }
};

int main() {
    const int N = 3;
    Counter counters[N]; // Array of 3 counter objects

    // Exercise counter 0
    counters[0].increment();
    counters[0].increment();

    // Exercise counter 1
    counters[1].increment();
    counters[1].increment();
    counters[1].increment();
    counters[1].increment();

    // Exercise counter 2
    counters[2].increment();
    counters[2].reset();

    for (int i = 0; i < N; ++i) {
        cout << "Counter[" << i << "] value = " << counters[i].get() << endl;
    }

    return 0;
}
