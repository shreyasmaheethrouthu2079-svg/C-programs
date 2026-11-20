#include <iostream>
#include <string>

using namespace std;

// DIY 7.1: Employee hierarchy
// Base Employee (name, id); derive Manager (adds team size) and Engineer (adds skill);
// print details of each.

class Employee {
protected:
    string name;
    int id;

public:
    Employee(const string &n, int i) : name(n), id(i) {}

    void printDetails() const {
        cout << "ID: " << id << " | Name: " << name;
    }
};

class Manager : public Employee {
private:
    int teamSize;

public:
    Manager(const string &n, int i, int ts)
        : Employee(n, i), teamSize(ts) {}

    void printDetails() const {
        Employee::printDetails();
        cout << " | Role: Manager | Team Size: " << teamSize << endl;
    }
};

class Engineer : public Employee {
private:
    string skill;

public:
    Engineer(const string &n, int i, const string &sk)
        : Employee(n, i), skill(sk) {}

    void printDetails() const {
        Employee::printDetails();
        cout << " | Role: Engineer | Skill: " << skill << endl;
    }
};

int main() {
    Manager m("Ramesh Kumar", 501, 12);
    Engineer e("Pooja Sharma", 802, "SystemVerilog UVM");

    m.printDetails();
    e.printDetails();

    return 0;
}
