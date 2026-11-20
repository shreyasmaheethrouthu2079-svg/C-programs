#include <iostream>

using namespace std;

// DIY 8.3: Prove the bug
// Build a Base/Derived pair where Derived allocates memory;
// show the leak when the destructor is not virtual, then fix it
// (use g++ -fsanitize=address).

class BuggyBase {
public:
    BuggyBase() { cout << "BuggyBase constructor" << endl; }
    // BUG: Missing 'virtual' keyword on base destructor!
    ~BuggyBase() { cout << "BuggyBase destructor (ONLY)" << endl; }
};

class BuggyDerived : public BuggyBase {
    int *buffer;
public:
    BuggyDerived() {
        buffer = new int[100];
        cout << "BuggyDerived allocated 100 ints" << endl;
    }
    ~BuggyDerived() {
        delete[] buffer;
        cout << "BuggyDerived freed 100 ints (destructor called)" << endl;
    }
};

// FIXED VERSION:
class SafeBase {
public:
    SafeBase() { cout << "SafeBase constructor" << endl; }
    // FIX: virtual destructor ensures derived destructor is called through base pointer
    virtual ~SafeBase() { cout << "SafeBase destructor" << endl; }
};

class SafeDerived : public SafeBase {
    int *buffer;
public:
    SafeDerived() {
        buffer = new int[100];
        cout << "SafeDerived allocated 100 ints" << endl;
    }
    ~SafeDerived() override {
        delete[] buffer;
        cout << "SafeDerived freed 100 ints (destructor called properly!)" << endl;
    }
};

int main() {
    cout << "=== Case 1: Non-virtual destructor (PROVES THE BUG / LEAK) ===" << endl;
    BuggyBase *pBuggy = new BuggyDerived();
    // Because BuggyBase::~BuggyBase is non-virtual, only BuggyBase destructor runs!
    // BuggyDerived::~BuggyDerived is SKIPPED, leaking the 100 ints buffer!
    delete pBuggy;

    cout << "\n=== Case 2: Virtual destructor (FIXED / SAFE) ===" << endl;
    SafeBase *pSafe = new SafeDerived();
    // Virtual dispatch calls SafeDerived::~SafeDerived, then SafeBase::~SafeBase
    delete pSafe;

    return 0;
}
