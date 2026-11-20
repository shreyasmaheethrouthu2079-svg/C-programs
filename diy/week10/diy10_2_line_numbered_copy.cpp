#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// DIY 10.2: Line-numbered copy
// Read in.txt and write out.txt with each line prefixed by its line number.

int main() {
    // Generate sample in.txt
    {
        ofstream sample("in.txt");
        sample << "Object-Oriented Programming with C++\n"
               << "Department of Electronics and Communication Engineering\n"
               << "NMAM Institute of Technology\n"
               << "SystemVerilog Verification Preparation\n";
    }

    ifstream in("in.txt");
    if (!in) {
        cerr << "Error: Could not open in.txt" << endl;
        return 1;
    }

    ofstream out("out.txt");
    if (!out) {
        cerr << "Error: Could not create out.txt" << endl;
        return 1;
    }

    string line;
    int lineNumber = 1;

    while (getline(in, line)) {
        out << lineNumber << ": " << line << "\n";
        lineNumber++;
    }

    in.close();
    out.close();

    cout << "Successfully copied with line numbers into out.txt!" << endl;

    // Display result from out.txt
    cout << "\n--- Contents of out.txt ---" << endl;
    ifstream verify("out.txt");
    while (getline(verify, line)) {
        cout << line << endl;
    }

    return 0;
}
