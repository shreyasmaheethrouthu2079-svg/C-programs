#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// DIY 8.2: Polymorphic logger
// Abstract Logger with write(string); derive ConsoleLogger and FileLogger; switch at run time.

class Logger {
public:
    virtual ~Logger() {}
    virtual void write(const string &msg) = 0; // pure virtual interface
};

class ConsoleLogger : public Logger {
public:
    void write(const string &msg) override {
        cout << "[CONSOLE LOG] " << msg << endl;
    }
};

class FileLogger : public Logger {
private:
    string filename;
public:
    FileLogger(const string &fn) : filename(fn) {}

    void write(const string &msg) override {
        ofstream out(filename, ios::app);
        if (out) {
            out << "[FILE LOG] " << msg << "\n";
            cout << "(Written to " << filename << ": \"" << msg << "\")" << endl;
        } else {
            cerr << "Error writing to " << filename << endl;
        }
    }
};

int main() {
    ConsoleLogger console;
    FileLogger file("application.log");

    // Switching logger at run time via base class pointer
    Logger *logger = &console;
    logger->write("Application boot sequence initiated.");

    // Switch to file logger
    logger = &file;
    logger->write("System calibration completed. Ready.");

    // Switch back to console
    logger = &console;
    logger->write("User logged in successfully.");

    return 0;
}
