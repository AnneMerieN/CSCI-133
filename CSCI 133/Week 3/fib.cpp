#include <iostream>


int fib (int n) {
    if (n == 0) { // Base Case: Fib of 0 is 0
        return 0;
    } else if (n == 1) { // Base Case: Fib of 1 is 1
        return 1;
    } else { // Each subsequent number is the sum of the two preceding numbers 
        return fib(n - 1) + fib(n-2); // Recursive case
    }
}


int main() {


    return 0;
}