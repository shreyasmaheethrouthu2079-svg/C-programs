#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// DIY 12.2: Top-3 with heap
// Read N numbers and print the three largest using a priority_queue
// (do not sort the whole array).

int main() {
    int n;
    cout << "Enter number of elements (or enter 0 to use demo set): ";
    if (!(cin >> n) || n <= 0) {
        vector<int> demo = {45, 12, 89, 73, 29, 99, 64, 91, 15};
        cout << "Using demo list: 45, 12, 89, 73, 29, 99, 64, 91, 15" << endl;

        priority_queue<int> pq(demo.begin(), demo.end());

        cout << "\nTop 3 largest elements (using max-heap):" << endl;
        for (int k = 1; k <= 3 && !pq.empty(); ++k) {
            cout << "Rank #" << k << ": " << pq.top() << endl;
            pq.pop();
        }
        return 0;
    }

    priority_queue<int> pq;
    cout << "Enter " << n << " integers:" << endl;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        pq.push(val);
    }

    cout << "\nTop 3 largest numbers:" << endl;
    for (int k = 1; k <= 3 && !pq.empty(); ++k) {
        cout << "Rank #" << k << ": " << pq.top() << endl;
        pq.pop();
    }

    return 0;
}
