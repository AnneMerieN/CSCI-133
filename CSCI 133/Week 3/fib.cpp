#include <iostream>

using namespace std;

int fibRecursive(int n) {
    
    int storedValue; 

    if (n == 0) {
        storedValue = 0; 
    } else if (n == 1) {
        storedValue = 1;
    } else {
        storedValue = fibRecursive(n - 1) + fibRecursive(n - 2); 
    }
    return storedValue; 
}

int main() {
    const int size = 8;
    int arr[size];

    // Storing Fibonacci sequence in the array
    for (int i = 0; i < size; ++i) {
        int storedValue = fibRecursive(i);
        arr[i] = storedValue; 
    }

    // Print
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }

    return 0;
}
