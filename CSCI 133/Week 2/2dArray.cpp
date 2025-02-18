#include <iostream>

using namespace std;

int main() {

    int arr[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };

    // Loop through rows
    for (int i = 0; i < 3; i++) { // O(n)
        // Loop through columns
        for (int j = 0; j < 3; j++) { // O(n)
            cout << arr[i][j] << " "; // O(1)
        }
        cout << endl; // O(1)
    }








    return 0;
}