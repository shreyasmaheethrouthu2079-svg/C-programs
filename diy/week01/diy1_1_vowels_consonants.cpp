#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// DIY 1.1: Vowel & consonant counter
// Read a sentence with getline(cin, s) and print how many vowels and consonants it contains.

int main() {
    string s;
    cout << "Enter a sentence: ";
    getline(cin, s);

    int vowels = 0;
    int consonants = 0;

    for (char ch : s) {
        if (isalpha(static_cast<unsigned char>(ch))) {
            char lower = tolower(static_cast<unsigned char>(ch));
            if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u') {
                vowels++;
            } else {
                consonants++;
            }
        }
    }

    cout << "Vowels: " << vowels << endl;
    cout << "Consonants: " << consonants << endl;

    return 0;
}
