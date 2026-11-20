#include <iostream>
#include <string>

using namespace std;

// DIY 11.1: Generic utilities
// Write template functions swapVals(T&, T&) and findMax(T arr[], int n)
// and test with int and double.

template <typename T>
void swapVals(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
T findMax(const T arr[], int n) {
    T currentMax = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] > currentMax) {
            currentMax = arr[i];
        }
    }
    return currentMax;
}

int main() {
    // 1. Test swapVals with int
    int x = 10, y = 20;
    cout << "Before swap: x=" << x << ", y=" << y << endl;
    swapVals(x, y);
    cout << "After swap : x=" << x << ", y=" << y << endl;

    // 2. Test swapVals with double
    double p = 3.14, q = 6.28;
    cout << "\nBefore swap: p=" << p << ", q=" << q << endl;
    swapVals(p, q);
    cout << "After swap : p=" << p << ", q=" << q << endl;

    // 3. Test findMax with int array
    int intArr[] = {15, 82, 34, 99, 41};
    cout << "\nMax of intArr: " << findMax(intArr, 5) << endl;

    // 4. Test findMax with double array
    double dblArr[] = {4.5, 9.8, 12.3, 1.2, 7.7};
    cout << "Max of dblArr: " << findMax(dblArr, 5) << endl;

    return 0;
}
