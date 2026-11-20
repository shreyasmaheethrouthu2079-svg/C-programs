#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

// DIY 13.3: Prove the race
// Run Program 13.3 without the lock_guard, observe the wrong total over several runs,
// then restore the lock and confirm 200000.

long counter = 0;
mutex mtx;

// Unsafe function: NO synchronization (RACE CONDITION)
void addUnsafe(int times) {
    for (int i = 0; i < times; ++i) {
        ++counter; // not atomic: read-modify-write race
    }
}

// Safe function: Protected critical section via RAII lock_guard
void addSafe(int times) {
    for (int i = 0; i < times; ++i) {
        lock_guard<mutex> lk(mtx);
        ++counter;
    }
}

int main() {
    const int ITERATIONS = 100000;

    cout << "=== Test 1: WITHOUT lock_guard (Race Condition Demo) ===" << endl;
    for (int run = 1; run <= 3; ++run) {
        counter = 0;
        thread t1(addUnsafe, ITERATIONS);
        thread t2(addUnsafe, ITERATIONS);
        t1.join();
        t2.join();
        cout << "  Run #" << run << ": counter = " << counter
             << " (expected 200000, deficit = " << (200000 - counter) << ")" << endl;
    }

    cout << "\n=== Test 2: WITH lock_guard (Synchronized / Safe) ===" << endl;
    counter = 0;
    thread t3(addSafe, ITERATIONS);
    thread t4(addSafe, ITERATIONS);
    t3.join();
    t4.join();
    cout << "  Protected: counter = " << counter << " (exactly 200000!)" << endl;

    return 0;
}
