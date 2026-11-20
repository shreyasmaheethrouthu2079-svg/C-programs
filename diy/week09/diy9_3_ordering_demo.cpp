#include <iostream>
#include <exception>

using namespace std;

// DIY 9.3: Ordering demo
// Define MathError and a derived DivideByZero;
// show that catching MathError first hides DivideByZero, then fix the order.

class MathError : public exception {
public:
    const char* what() const noexcept override {
        return "Base MathError occurred";
    }
};

class DivideByZero : public MathError {
public:
    const char* what() const noexcept override {
        return "DivideByZero: Division by zero is undefined!";
    }
};

double divide(double num, double den) {
    if (den == 0) {
        throw DivideByZero();
    }
    return num / den;
}

int main() {
    cout << "=== Part 1: Flawed Catch Order (Base before Derived) ===" << endl;
    cout << "Warning: Catching MathError before DivideByZero hides the specialized handler!" << endl;
    try {
        divide(10, 0);
    }
    // Notice: If MathError is placed first, it catches DivideByZero because of polymorphism!
    catch (const MathError &e) {
        cout << "[WRONG ORDER] Caught by MathError handler: " << e.what() << endl;
    }
    /*
    catch (const DivideByZero &e) {
        // unreachable if above catch is enabled!
    }
    */

    cout << "\n=== Part 2: Correct Catch Order (Derived before Base) ===" << endl;
    try {
        divide(25, 0);
    }
    // CORRECT: Most specific (derived) exception first
    catch (const DivideByZero &e) {
        cout << "[CORRECT ORDER] Caught by specific DivideByZero handler: " << e.what() << endl;
    }
    catch (const MathError &e) {
        cout << "[CORRECT ORDER] Caught by general MathError handler: " << e.what() << endl;
    }

    return 0;
}
