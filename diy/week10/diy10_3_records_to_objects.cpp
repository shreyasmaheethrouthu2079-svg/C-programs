#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// DIY 10.3: Records into objects
// Store name marks pairs in a file, read them back into an array of Student objects,
// and print the topper.

class Student {
private:
    string name;
    int marks;

public:
    Student() : name(""), marks(0) {}
    Student(const string &n, int m) : name(n), marks(m) {}

    string getName() const { return name; }
    int getMarks() const { return marks; }

    void display() const {
        cout << name << " -> " << marks << " marks" << endl;
    }
};

int main() {
    // 1. Store name marks pairs in file
    const string filename = "student_marks.txt";
    {
        ofstream out(filename);
        out << "Ananya 94\n"
            << "Vikram 87\n"
            << "Deepak 98\n"
            << "Sneha 91\n"
            << "Kiran 82\n";
    }

    // 2. Read them back into array/vector of Student objects
    ifstream in(filename);
    if (!in) {
        cerr << "Error: Could not open " << filename << endl;
        return 1;
    }

    vector<Student> students;
    string name;
    int marks;

    while (in >> name >> marks) {
        students.push_back(Student(name, marks));
    }
    in.close();

    cout << "Loaded Student Records:" << endl;
    for (const auto &s : students) {
        s.display();
    }

    // 3. Find and print the topper
    if (!students.empty()) {
        const Student *topper = &students[0];
        for (const auto &s : students) {
            if (s.getMarks() > topper->getMarks()) {
                topper = &s;
            }
        }
        cout << "\n🏆 Top Performer: " << topper->getName()
             << " with " << topper->getMarks() << " marks!" << endl;
    }

    return 0;
}
