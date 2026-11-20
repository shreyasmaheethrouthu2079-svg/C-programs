#include <iostream>
#include <numeric>

using namespace std;

// DIY 6.2: Fraction I/O
// A Fraction class; overload << and >> and auto-simplify (divide by GCD) on construction.

long long computeGcd(long long a, long long b) {
    a = (a < 0) ? -a : a;
    b = (b < 0) ? -b : b;
    while (b != 0) {
        long long t = b;
        b = a % b;
        a = t;
    }
    return a;
}

class Fraction {
private:
    long long num;
    long long den;

    void simplify() {
        if (den < 0) {
            num = -num;
            den = -den;
        }
        if (den == 0) {
            cout << "[Warning] Denominator cannot be zero, setting to 1." << endl;
            den = 1;
        }
        long long g = computeGcd(num, den);
        if (g > 0) {
            num /= g;
            den /= g;
        }
    }

public:
    Fraction(long long n = 0, long long d = 1) : num(n), den(d) {
        simplify();
    }

    friend ostream& operator<<(ostream &os, const Fraction &f) {
        os << f.num << "/" << f.den;
        return os;
    }

    friend istream& operator>>(istream &is, Fraction &f) {
        char slash;
        is >> f.num >> slash >> f.den;
        f.simplify();
        return is;
    }
};

int main() {
    Fraction f1(8, 12); // Auto-simplifies to 2/3
    Fraction f2(-15, -25); // Auto-simplifies to 3/5

    cout << "f1 (8/12 auto-simplified) = " << f1 << endl;
    cout << "f2 (-15/-25 auto-simplified) = " << f2 << endl;

    Fraction f3;
    cout << "Enter a fraction in format num/den (e.g. 18/24): ";
    if (cin >> f3) {
        cout << "Simplified Fraction: " << f3 << endl;
    }

    return 0;
}
