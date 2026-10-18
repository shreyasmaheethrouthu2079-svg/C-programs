#include <iostream>
using namespace std;

void SwapRef(int a, int b) { 
    int t = a; 
    a = b; 
    b = t; 
}

void SwapPtr(int *a, int *b) { 
    int t = *a; 
    *a = *b; 
    *b = t; 
}

int main() {
    int x = 10, y = 20;
    
    SwapRef(x, y);
    cout << "After Swap Ref: x=" << x << "y=" << y << endl;
    
    SwapPtr(&x, &y);
    cout << "After Swap Ptr x=" << x << "y=" << y << endl;
    
    int &alias = x;
    alias = 99;
    cout << "x via alias: " << x << endl;
    
    return 0;
}