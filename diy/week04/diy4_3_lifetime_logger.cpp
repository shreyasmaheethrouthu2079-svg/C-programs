#include <iostream>

using namespace std;

// DIY 4.3: Lifetime logger
// Extend Program 4.1 so each Tracer is created with new inside a loop
// and deleted -- observe how forgetting delete leaks.

class Tracer {
    int id;
public:
    Tracer(int i) : id(i) {
        cout << "  Construct Tracer #" << id << endl;
    }
    ~Tracer() {
        cout << "  Destruct Tracer #" << id << endl;
    }
};

int main() {
    cout << "=== Correct usage: Allocation with delete ===" << endl;
    for (int i = 1; i <= 3; ++i) {
        Tracer *t = new Tracer(i);
        delete t; // Properly frees memory and invokes destructor
    }

    cout << "\n=== Demonstrating leak: Allocation WITHOUT delete ===" << endl;
    for (int i = 101; i <= 103; ++i) {
        Tracer *t = new Tracer(i);
        // Notice: Omitting 'delete t;' prevents destructor execution and leaks memory!
        // When compiled with: g++ -fsanitize=address, AddressSanitizer detects this leak.
        (void)t; // suppress unused variable warning
    }
    cout << "Finished loop without delete (destructors not called for #101-#103)." << endl;

    return 0;
}
