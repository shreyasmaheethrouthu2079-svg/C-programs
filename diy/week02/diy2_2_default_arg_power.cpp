#include <iostream>

using namespace std;

// DIY 2.2: Default-argument calculator
// Write power(int base, int exp = 2) so power(5) gives 25 and power(2,10) gives 1024.

long long power(int base, int exp = 2) {
    long long result = 1;
    for (int i = 0; i < exp; ++i) {
        result *= base;
    }
    return result;
}

int main() {
    cout << "power(5)     = " << power(5) << " (expected 25)" << endl;
    cout << "power(2, 10) = " << power(2, 10) << " (expected 1024)" << endl;
    cout << "power(3, 4)  = " << power(3, 4) << " (expected 81)" << endl;

    return 0;
}
