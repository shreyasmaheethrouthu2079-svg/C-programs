#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

// DIY 13.2: Shape factory v2
// Extend Program 13.1 with a Triangle and let the user type the shape name at run time;
// store the created shapes in a vector<unique_ptr<Shape>>.

struct Shape {
    virtual double area() const = 0;
    virtual string name() const = 0;
    virtual ~Shape() {}
};

struct Circle : Shape {
    double r;
    Circle(double r) : r(r) {}
    double area() const override { return 3.14159 * r * r; }
    string name() const override { return "Circle"; }
};

struct Square : Shape {
    double s;
    Square(double s) : s(s) {}
    double area() const override { return s * s; }
    string name() const override { return "Square"; }
};

struct Triangle : Shape {
    double b, h;
    Triangle(double b, double h) : b(b), h(h) {}
    double area() const override { return 0.5 * b * h; }
    string name() const override { return "Triangle"; }
};

// Factory function
unique_ptr<Shape> makeShape(const string &kind) {
    if (kind == "circle") {
        return make_unique<Circle>(3.0);
    } else if (kind == "square") {
        return make_unique<Square>(4.0);
    } else if (kind == "triangle") {
        return make_unique<Triangle>(5.0, 6.0);
    }
    return nullptr;
}

int main() {
    vector<unique_ptr<Shape>> shapes;
    string inputKind;

    cout << "Enter shapes to create (circle, square, triangle, or 'done' to stop):" << endl;
    cout << "(Or enter 'demo' to run preset demo shapes)" << endl;

    if (!(cin >> inputKind) || inputKind == "demo") {
        cout << "Running demo with circle, triangle, square:" << endl;
        shapes.push_back(makeShape("circle"));
        shapes.push_back(makeShape("triangle"));
        shapes.push_back(makeShape("square"));
    } else {
        while (inputKind != "done") {
            auto s = makeShape(inputKind);
            if (s) {
                shapes.push_back(std::move(s));
                cout << "Created " << inputKind << endl;
            } else {
                cout << "Unknown shape type: " << inputKind << endl;
            }
            if (!(cin >> inputKind)) break;
        }
    }

    cout << "\n=== Displaying All Created Shapes in vector<unique_ptr<Shape>> ===" << endl;
    for (const auto &sh : shapes) {
        cout << sh->name() << " with area = " << sh->area() << endl;
    }

    return 0;
}
