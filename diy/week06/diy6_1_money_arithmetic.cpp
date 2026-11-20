#include <iostream>

using namespace std;

// DIY 6.1: Money arithmetic
// A Money class (rupees, paise); overload + and - with correct carry/borrow of paise into rupees.

class Money {
private:
    long rupees;
    int paise;

    void normalize() {
        if (paise >= 100) {
            rupees += paise / 100;
            paise %= 100;
        } else if (paise < 0) {
            long borrow = (-paise + 99) / 100;
            rupees -= borrow;
            paise += borrow * 100;
        }
    }

public:
    Money(long r = 0, int p = 0) : rupees(r), paise(p) {
        normalize();
    }

    Money operator+(const Money &other) const {
        return Money(rupees + other.rupees, paise + other.paise);
    }

    Money operator-(const Money &other) const {
        return Money(rupees - other.rupees, paise - other.paise);
    }

    friend ostream& operator<<(ostream &os, const Money &m) {
        os << "Rs. " << m.rupees << "." << (m.paise < 10 ? "0" : "") << m.paise;
        return os;
    }
};

int main() {
    Money m1(150, 75);
    Money m2(49, 50);

    cout << "m1 = " << m1 << endl;
    cout << "m2 = " << m2 << endl;

    Money sum = m1 + m2;
    cout << "m1 + m2 = " << sum << " (with carry)" << endl;

    Money diff = m1 - m2;
    cout << "m1 - m2 = " << diff << " (with borrow)" << endl;

    return 0;
}
