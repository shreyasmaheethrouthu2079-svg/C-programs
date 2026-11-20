#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// DIY 12.1: Sort pairs
// Given a vector<pair<string,int>>, sort by the integer (second) field ascending, then print.

int main() {
    vector<pair<string, int>> studentScores = {
        {"Rohit", 85},
        {"Sneha", 94},
        {"Aditya", 78},
        {"Bhavna", 91},
        {"Chirag", 62}
    };

    cout << "=== Before Sorting ===" << endl;
    for (const auto &p : studentScores) {
        cout << p.first << ": " << p.second << endl;
    }

    // Sort ascending by the integer (second) field using lambda comparator
    sort(studentScores.begin(), studentScores.end(),
         [](const pair<string, int> &a, const pair<string, int> &b) {
             return a.second < b.second; // strict weak ordering (<)
         });

    cout << "\n=== After Sorting by Score (Ascending) ===" << endl;
    for (const auto &p : studentScores) {
        cout << p.first << ": " << p.second << endl;
    }

    return 0;
}
