#include <iostream>

using namespace std;

int findSum(const int arr[3][3]) { // use const to prevent modification
    int sum = 0;

    for (int i = 0; i < 3; i++) { // loop through rows
        for (int j = 0; j < 3; j++) { // loop through columns
            sum = sum + arr[i][j];
        }
    }
    return sum;

}

int main() {
    int arr[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };

    cout << "Sum of 2D array: " << findSum(arr) << endl;


    return 0;
}