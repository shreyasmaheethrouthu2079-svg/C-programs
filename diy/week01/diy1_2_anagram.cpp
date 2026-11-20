#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// DIY 1.2: Anagram test
// Read two words and decide whether one is an anagram of the other.

bool isAnagram(const string &w1, const string &w2) {
    if (w1.length() != w2.length()) return false;

    int freq[26] = {0};

    for (char c : w1) {
        if (isalpha(static_cast<unsigned char>(c))) {
            freq[tolower(static_cast<unsigned char>(c)) - 'a']++;
        }
    }

    for (char c : w2) {
        if (isalpha(static_cast<unsigned char>(c))) {
            freq[tolower(static_cast<unsigned char>(c)) - 'a']--;
        }
    }

    for (int count : freq) {
        if (count != 0) return false;
    }

    return true;
}

int main() {
    string word1, word2;
    cout << "Enter first word: ";
    cin >> word1;
    cout << "Enter second word: ";
    cin >> word2;

    if (isAnagram(word1, word2)) {
        cout << "\"" << word1 << "\" and \"" << word2 << "\" ARE anagrams." << endl;
    } else {
        cout << "\"" << word1 << "\" and \"" << word2 << "\" are NOT anagrams." << endl;
    }

    return 0;
}
