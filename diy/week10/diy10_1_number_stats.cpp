#include <iostream>
#include <fstream>
#include <limits>

using namespace std;

// DIY 10.1: Number stats from file
// Read an unknown count of integers from nums.txt and print their count, sum, min and max.

int main() {
    // Generate sample nums.txt if not already present
    {
        ofstream sample("nums.txt");
        sample << "42 17 89 5 63 99 21 8" << endl;
    }

    ifstream in("nums.txt");
    if (!in) {
        cerr << "Error: Could not open nums.txt" << endl;
        return 1;
    }

    int num;
    long long sum = 0;
    int count = 0;
    int minVal = numeric_limits<int>::max();
    int maxVal = numeric_limits<int>::min();

    while (in >> num) {
        sum += num;
        count++;
        if (num < minVal) minVal = num;
        if (num > maxVal) maxVal = num;
    }

    in.close();

    if (count > 0) {
        cout << "File: nums.txt" << endl;
        cout << "Count : " << count << endl;
        cout << "Sum   : " << sum << endl;
        cout << "Min   : " << minVal << endl;
        cout << "Max   : " << maxVal << endl;
        cout << "Average: " << static_cast<double>(sum) / count << endl;
    } else {
        cout << "nums.txt is empty." << endl;
    }

    return 0;
}
