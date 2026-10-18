#include <iostream>
using namespace std;

int main() {
    int num, original, reversed = 0, remainder;
    
    cout << "Enter the number " << endl;
    cin >> num;
    
    original = num;
    
    while (num != 0) {
        remainder = num % 10;
        reversed = reversed * 10 + remainder;
        num /= 10;
    }
    
    if (original == reversed)
        cout << "pallindrome";
    else
        cout << "Not a pallindrom";
        
    return 0;
}