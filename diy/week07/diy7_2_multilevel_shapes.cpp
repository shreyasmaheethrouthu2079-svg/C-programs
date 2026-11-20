#include <iostream>
#include <string>

using namespace std;

// DIY 7.2: Multilevel shapes
// Shape -> Polygon -> Rectangle; each level adds one field;
// demonstrate the constructor call order with print statements.

class Shape {
protected:
    string color;

public:
    Shape(const string &c) : color(c) {
        cout << "[1] Shape constructor called (color=" << color << ")" << endl;
    }
    ~Shape() {
        cout << "[1] Shape destructor called" << endl;
    }
};

class Polygon : public Shape {
protected:
    int numSides;

public:
    Polygon(const string &c, int sides) : Shape(c), numSides(sides) {
        cout << "[2] Polygon constructor called (sides=" << numSides << ")" << endl;
    }
    ~Polygon() {
        cout << "[2] Polygon destructor called" << endl;
    }
};

class Rectangle : public Polygon {
private:
    double length, width;

public:
    Rectangle(const string &c, double l, double w)
        : Polygon(c, 4), length(l), width(w) {
        cout << "[3] Rectangle constructor called (" << length << "x" << width << ")" << endl;
    }
    ~Rectangle() {
        cout << "[3] Rectangle destructor called" << endl;
    }

    void show() const {
        cout << "Rectangle: Color=" << color << ", Sides=" << numSides
             << ", Dimensions=" << length << "x" << width
             << ", Area=" << (length * width) << endl;
    }
};

int main() {
    cout << "--- Constructing Rectangle (Base -> Derived) ---" << endl;
    {
        Rectangle r("Blue", 10.0, 5.0);
        r.show();
        cout << "--- Destroying Rectangle (Derived -> Base) ---" << endl;
    }

    return 0;
}
