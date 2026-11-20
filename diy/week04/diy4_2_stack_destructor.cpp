#include <iostream>

using namespace std;

// DIY 4.2: Stack with destructor
// An integer Stack backed by a dynamic array;
// push/pop plus a destructor that releases the buffer.

class Stack {
private:
    int *arr;
    int capacity;
    int topIndex;

public:
    Stack(int cap = 10) : capacity(cap), topIndex(-1) {
        arr = new int[capacity];
    }

    ~Stack() {
        delete[] arr; // clean up allocated buffer
    }

    bool push(int val) {
        if (topIndex >= capacity - 1) {
            cout << "[Error] Stack Overflow!" << endl;
            return false;
        }
        arr[++topIndex] = val;
        return true;
    }

    int pop() {
        if (topIndex < 0) {
            cout << "[Error] Stack Underflow!" << endl;
            return -1;
        }
        return arr[topIndex--];
    }

    bool empty() const {
        return topIndex < 0;
    }

    int size() const {
        return topIndex + 1;
    }
};

int main() {
    Stack s(5);

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Popping elements from stack:" << endl;
    while (!s.empty()) {
        cout << s.pop() << " ";
    }
    cout << endl;

    return 0;
}
