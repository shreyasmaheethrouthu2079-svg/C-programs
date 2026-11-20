#include <iostream>

using namespace std;

// DIY 2.1: Overloaded volume
// Write three overloads computing the volume of a cube (1 arg),
// cuboid (3 args) and cylinder (2 args, radius & height).

// Cube volume: s^3
double volume(double s) {
    return s * s * s;
}

// Cuboid volume: l * b * h
double volume(double l, double b, double h) {
    return l * b * h;
}

// Cylinder volume: pi * r^2 * h
double volume(double r, double h) {
    const double PI = 3.141592653589793;
    return PI * r * r * h;
}

int main() {
    cout << "Volume of cube (side = 4): " << volume(4.0) << endl;
    cout << "Volume of cuboid (3 x 4 x 5): " << volume(3.0, 4.0, 5.0) << endl;
    cout << "Volume of cylinder (r = 3, h = 7): " << volume(3.0, 7.0) << endl;

    return 0;
}
