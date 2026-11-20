#include <iostream>
#include <exception>
#include <string>

using namespace std;

// DIY 9.1: Safe withdrawal
// Extend the Week-3 BankAccount to throw a custom InsufficientFunds exception
// instead of returning false.

class InsufficientFundsException : public exception {
private:
    string message;
public:
    InsufficientFundsException(double balance, double requested) {
        message = "Insufficient Funds: Available balance is Rs. " + to_string(balance)
                + ", but requested Rs. " + to_string(requested);
    }

    const char* what() const noexcept override {
        return message.c_str();
    }
};

class BankAccount {
private:
    string owner;
    double balance;

public:
    BankAccount(const string &name, double initial)
        : owner(name), balance(initial > 0 ? initial : 0) {}

    void deposit(double amt) {
        if (amt > 0) balance += amt;
    }

    void withdraw(double amt) {
        if (amt <= 0) {
            throw invalid_argument("Withdrawal amount must be positive.");
        }
        if (amt > balance) {
            throw InsufficientFundsException(balance, amt);
        }
        balance -= amt;
        cout << "Successfully withdrew Rs. " << amt << ". Remaining balance: Rs. " << balance << endl;
    }

    double getBalance() const { return balance; }
};

int main() {
    BankAccount acc("Suresh", 1500.0);

    try {
        cout << "Initial Balance: Rs. " << acc.getBalance() << endl;
        acc.withdraw(500.0);  // Success
        acc.withdraw(2000.0); // Throws InsufficientFundsException
    } catch (const InsufficientFundsException &e) {
        cout << "[Caught Exception] " << e.what() << endl;
    } catch (const exception &e) {
        cout << "[General Exception] " << e.what() << endl;
    }

    return 0;
}
