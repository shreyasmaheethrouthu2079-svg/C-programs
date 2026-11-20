#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

// DIY 1.3: Reverse the words
// Read a sentence like "hello world cpp" and print "cpp world hello"
// (reverse word order, not characters).

int main() {
    string sentence;
    cout << "Enter a sentence: ";
    getline(cin, sentence);

    stringstream ss(sentence);
    string word;
    vector<string> words;

    while (ss >> word) {
        words.push_back(word);
    }

    cout << "Reversed words: ";
    for (int i = static_cast<int>(words.size()) - 1; i >= 0; --i) {
        cout << words[i] << (i > 0 ? " " : "");
    }
    cout << endl;

    return 0;
}
