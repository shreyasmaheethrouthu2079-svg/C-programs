#include <iostream>
#include <string>

using namespace std;

// DIY 7.3: Resolve a diamond
// Build Person -> Student, Person -> Employee, then TA (teaching assistant) inheriting both;
// use a virtual base so Person appears once.

class Person {
protected:
    string name;

public:
    Person(const string &n = "Unknown") : name(n) {
        cout << "Person ctor: " << name << endl;
    }
    virtual ~Person() {}

    void printName() const {
        cout << "Name: " << name << endl;
    }
};

// Virtual inheritance ensures only ONE shared Person sub-object exists
class Student : virtual public Person {
protected:
    string rollNo;

public:
    Student(const string &n, const string &r) : Person(n), rollNo(r) {
        cout << "Student ctor" << endl;
    }
};

class Employee : virtual public Person {
protected:
    int empId;

public:
    Employee(const string &n, int id) : Person(n), empId(id) {
        cout << "Employee ctor" << endl;
    }
};

class TA : public Student, public Employee {
private:
    string course;

public:
    // With virtual base class, the most-derived class (TA) directly initializes Person
    TA(const string &n, const string &r, int id, const string &c)
        : Person(n), Student(n, r), Employee(n, id), course(c) {
        cout << "TA ctor" << endl;
    }

    void display() const {
        cout << "\n=== Teaching Assistant Details ===" << endl;
        // Unambiguous call because Person is a virtual base class!
        printName();
        cout << "Roll No  : " << rollNo << endl;
        cout << "Emp ID   : " << empId << endl;
        cout << "Assigned : " << course << endl;
    }
};

int main() {
    TA ta("Aditi", "4NM24EC001", 9012, "ECE121 OOP in C++");
    ta.display();

    return 0;
}
