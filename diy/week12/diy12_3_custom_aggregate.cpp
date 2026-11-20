#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

// DIY 12.3: Custom aggregate
// Use accumulate with a lambda to compute the product of all elements,
// or the sum of only the even ones.

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6};

    cout << "Input numbers: ";
    for (int x : nums) cout << x << " ";
    cout << endl;

    // 1. Product of all elements using accumulate with multiplication lambda
    long long product = accumulate(nums.begin(), nums.end(), 1LL,
        [](long long acc, int val) {
            return acc * val;
        });

    cout << "Product of all elements: " << product << " (expected 720)" << endl;

    // 2. Sum of only even elements using accumulate with condition lambda
    int sumEvens = accumulate(nums.begin(), nums.end(), 0,
        [](int acc, int val) {
            return (val % 2 == 0) ? (acc + val) : acc;
        });

    cout << "Sum of only even elements: " << sumEvens << " (2 + 4 + 6 = 12)" << endl;

    return 0;
}
