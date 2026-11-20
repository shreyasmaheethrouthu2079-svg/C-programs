#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;

// DIY 11.3: Frequency counter
// Read words from input and use an unordered_map<string,int>
// to print each word with its count; then print the most frequent word.

int main() {
    string line;
    cout << "Enter a line of text (or press Enter for default test sentence):" << endl;
    getline(cin, line);

    if (line.empty()) {
        line = "verilog systemverilog cpp uvm verification cpp verilog verification cpp";
        cout << "Using default input: \"" << line << "\"" << endl;
    }

    stringstream ss(line);
    string word;
    unordered_map<string, int> freq;

    while (ss >> word) {
        freq[word]++;
    }

    cout << "\n=== Word Frequencies ===" << endl;
    string mostFreqWord = "";
    int maxCount = 0;

    for (const auto &pair : freq) {
        cout << pair.first << " : " << pair.second << endl;
        if (pair.second > maxCount) {
            maxCount = pair.second;
            mostFreqWord = pair.first;
        }
    }

    cout << "\nMost frequent word: \"" << mostFreqWord
         << "\" with frequency " << maxCount << endl;

    return 0;
}
