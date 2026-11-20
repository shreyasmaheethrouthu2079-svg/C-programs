#include <iostream>
#include <exception>

using namespace std;

// DIY 9.2: Stack over/underflow
// Give your Week-4 Stack custom Overflow and Underflow exceptions and handle them in main.

class StackOverflow : public exception {
public:
    const char* what() const noexcept override {
        return "Stack Exception: Overflow! Attempted to push into a full stack.";
    }
};

class StackUnderflow : public exception {
public:
    const char* what() const noexcept override {
        return "Stack Exception: Underflow! Attempted to pop from an empty stack.";
    }
};

class SafeStack {
private:
    int *arr;
    int capacity;
    int topIndex;

public:
    SafeStack(int cap = 3) : capacity(cap), topIndex(-1) {
        arr = new int[capacity];
    }

    ~SafeStack() {
        delete[] arr;
    }

    void push(int val) {
        if (topIndex >= capacity - 1) {
            throw StackOverflow();
        }
        arr[++topIndex] = val;
    }

    int pop() {
        if (topIndex < 0) {
            throw StackUnderflow();
        }
        return arr[topIndex--];
    }
};

int main() {
    SafeStack s(2); // Capacity = 2

    // 1. Test Overflow
    try {
        cout << "Pushing 10..." << endl;
        s.push(10);
        cout << "Pushing 20..." << endl;
        s.push(20);
        cout << "Pushing 30 (exceeds capacity)..." << endl;
        s.push(30);
    } catch (const StackOverflow &e) {
        cout << "[HANDLED] " << e.what() << endl;
    }

    // 2. Test Underflow
    try {
        cout << "\nPopping: " << s.pop() << endl;
        cout << "Popping: " << s.pop() << endl;
        cout << "Popping from empty stack..." << endl;
        cout << "Popping: " << s.pop() << endl;
    } catch (const StackUnderflow &e) {
        cout << "[HANDLED] " << e.what() << endl;
    }

    return 0;
}
