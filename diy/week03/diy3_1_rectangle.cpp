#include <iostream>

using namespace std;

// DIY 3.1: Rectangle class
// Private length and width, public setters with validation (reject negatives),
// and area()/perimeter() getters.

class Rectangle {
private:
    double length;
    double width;

public:
    Rectangle(double l = 0.0, double w = 0.0) {
        setLength(l);
        setWidth(w);
    }

    bool setLength(double l) {
        if (l >= 0) {
            length = l;
            return true;
        } else {
            cout << "[Error] Length cannot be negative: " << l << endl;
            return false;
        }
    }

    bool setWidth(double w) {
        if (w >= 0) {
            width = w;
            return true;
        } else {
            cout << "[Error] Width cannot be negative: " << w << endl;
            return false;
        }
    }

    double getLength() const { return length; }
    double getWidth() const { return width; }

    double area() const {
        return length * width;
    }

    double perimeter() const {
        return 2 * (length + width);
    }
};

int main() {
    Rectangle r;
    r.setLength(10.5);
    r.setWidth(4.0);

    cout << "Rectangle dimensions: " << r.getLength() << " x " << r.getWidth() << endl;
    cout << "Area: " << r.area() << endl;
    cout << "Perimeter: " << r.perimeter() << endl;

    cout << "\nAttempting invalid assignment (-5):" << endl;
    r.setWidth(-5.0);
    cout << "Current Width remains: " << r.getWidth() << endl;

    return 0;
}
