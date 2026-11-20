#include <iostream>

using namespace std;

// DIY 3.3: Complex number class
// Store real and imag, provide setData() and display();
// print a small array of complex numbers.

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    void setData(double r, double i) {
        real = r;
        imag = i;
    }

    void display() const {
        cout << real;
        if (imag >= 0) {
            cout << " + " << imag << "i";
        } else {
            cout << " - " << -imag << "i";
        }
        cout << endl;
    }
};

int main() {
    Complex arr[3];

    arr[0].setData(3.5, 4.2);
    arr[1].setData(5.0, -2.1);
    arr[2].setData(0.0, 7.8);

    cout << "Array of Complex Numbers:" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << "arr[" << i << "] = ";
        arr[i].display();
    }

    return 0;
}
