#include <iostream>

using namespace std;

// DIY 4.1: Dynamic Matrix
// A Matrix class that allocates an m x n grid with new,
// provides a deep copy constructor, and frees it in the destructor.

class Matrix {
private:
    int rows;
    int cols;
    int **data;

public:
    // Constructor allocating dynamic 2D array
    Matrix(int r, int c) : rows(r), cols(c) {
        data = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new int[cols]{0}; // 0-initialized
        }
    }

    // Deep Copy Constructor
    Matrix(const Matrix &other) : rows(other.rows), cols(other.cols) {
        data = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new int[cols];
            for (int j = 0; j < cols; ++j) {
                data[i][j] = other.data[i][j];
            }
        }
        cout << "[Copy Constructor] Deep copy performed." << endl;
    }

    // Destructor releasing dynamic memory
    ~Matrix() {
        for (int i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }

    void set(int r, int c, int val) {
        if (r >= 0 && r < rows && c >= 0 && c < cols) {
            data[r][c] = val;
        }
    }

    int get(int r, int c) const {
        if (r >= 0 && r < rows && c >= 0 && c < cols) {
            return data[r][c];
        }
        return 0;
    }

    void display() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << data[i][j] << "\t";
            }
            cout << endl;
        }
    }
};

int main() {
    Matrix m1(2, 3);
    m1.set(0, 0, 10);
    m1.set(0, 1, 20);
    m1.set(1, 2, 99);

    cout << "Original Matrix m1:" << endl;
    m1.display();

    // Invoking deep copy constructor
    Matrix m2 = m1;
    cout << "\nCopied Matrix m2:" << endl;
    m2.display();

    // Verify independence (deep copy)
    m2.set(0, 0, 888);
    cout << "\nAfter modifying m2(0,0) to 888:" << endl;
    cout << "m1(0,0): " << m1.get(0, 0) << " (unmodified)" << endl;
    cout << "m2(0,0): " << m2.get(0, 0) << endl;

    return 0;
}
