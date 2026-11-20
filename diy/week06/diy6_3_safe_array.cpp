#include <iostream>
#include <stdexcept>

using namespace std;

// DIY 6.3: Safe array
// A class wrapping a dynamic array; overload operator[]
// to throw / report an error on out-of-range access instead of corrupting memory.

class SafeArray {
private:
    int *arr;
    int size;

public:
    SafeArray(int s) : size(s) {
        arr = new int[size]{0};
    }

    ~SafeArray() {
        delete[] arr;
    }

    int getSize() const { return size; }

    // Overload [] for non-const objects
    int& operator[](int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index " + to_string(index) + " out of bounds! Valid range: [0, " + to_string(size - 1) + "]");
        }
        return arr[index];
    }

    // Overload [] for const objects
    const int& operator[](int index) const {
        if (index < 0 || index >= size) {
            throw out_of_range("Index " + to_string(index) + " out of bounds! Valid range: [0, " + to_string(size - 1) + "]");
        }
        return arr[index];
    }
};

int main() {
    SafeArray sa(5);

    // Valid assignments
    for (int i = 0; i < 5; ++i) {
        sa[i] = (i + 1) * 10;
    }

    cout << "Array contents: ";
    for (int i = 0; i < 5; ++i) {
        cout << sa[i] << " ";
    }
    cout << endl;

    // Out-of-bounds access
    try {
        cout << "Attempting to access sa[10]..." << endl;
        sa[10] = 999;
    } catch (const out_of_range &e) {
        cout << "[Caught Exception] " << e.what() << endl;
    }

    try {
        cout << "Attempting to access sa[-1]..." << endl;
        cout << sa[-1] << endl;
    } catch (const out_of_range &e) {
        cout << "[Caught Exception] " << e.what() << endl;
    }

    return 0;
}
