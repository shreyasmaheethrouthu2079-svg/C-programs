#include <iostream>

using namespace std;

// DIY 2.3: Inline min
// Write an inline overloaded minVal returning the smaller of two ints
// and, via a second overload, the smallest of three ints.

inline int minVal(int a, int b) {
    return (a < b) ? a : b;
}

inline int minVal(int a, int b, int c) {
    return minVal(minVal(a, b), c);
}

int main() {
    cout << "minVal(12, 25)     = " << minVal(12, 25) << endl;
    cout << "minVal(40, -5)     = " << minVal(40, -5) << endl;
    cout << "minVal(15, 3, 9)   = " << minVal(15, 3, 9) << endl;
    cout << "minVal(-2, -8, -1) = " << minVal(-2, -8, -1) << endl;

    return 0;
}
