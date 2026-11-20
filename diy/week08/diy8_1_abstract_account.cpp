#include <iostream>
#include <string>

using namespace std;

// DIY 8.1: Abstract Account
// Pure-virtual calculateInterest(); derive Savings and Current with different rates;
// process an array of Account*.

class Account {
protected:
    string accountNumber;
    double balance;

public:
    Account(const string &acc, double bal) : accountNumber(acc), balance(bal) {}
    virtual ~Account() {} // virtual destructor for safe polymorphic deletion

    // Pure virtual method
    virtual double calculateInterest() const = 0;

    virtual void display() const {
        cout << "Acc: " << accountNumber
             << " | Balance: Rs. " << balance
             << " | Interest: Rs. " << calculateInterest() << endl;
    }
};

class Savings : public Account {
public:
    Savings(const string &acc, double bal) : Account(acc, bal) {}

    // 4.5% annual interest
    double calculateInterest() const override {
        return balance * 0.045;
    }

    void display() const override {
        cout << "[Savings] ";
        Account::display();
    }
};

class Current : public Account {
public:
    Current(const string &acc, double bal) : Account(acc, bal) {}

    // 1.0% interest / nominal return
    double calculateInterest() const override {
        return balance * 0.010;
    }

    void display() const override {
        cout << "[Current] ";
        Account::display();
    }
};

int main() {
    // Array of base class pointers
    Account* accounts[] = {
        new Savings("SB-1001", 50000.0),
        new Current("CA-2001", 120000.0),
        new Savings("SB-1002", 75000.0)
    };

    cout << "Processing accounts polymorphically:" << endl;
    for (Account* acc : accounts) {
        acc->display();
    }

    // Cleanup
    for (Account* acc : accounts) {
        delete acc;
    }

    return 0;
}
