#include <iostream>

using namespace std;

void findRowSums(const int arr[3][3]) {

    cout << "Sum of each individual row: " << endl;

    for (int i = 0; i < 3; i++) {
        int rowSum = 0;
        for (int j = 0; j < 3; j++) {
            rowSum = rowSum + arr[i][j];
        }
        cout << "Row " << i << " sum = " << rowSum << endl;
    }
}

// Function to find the total sum of all rows combined
void sumAllRows(const int arr[3][3]) {
    int totalSum = 0; // Stores the sum of all rows combined
    for (int i = 0; i < 3; i++) { // Loop through rows
        for (int j = 0; j < 3; j++) { // Loop through columns
            totalSum = totalSum + arr[i][j];  // Add every element to total sum
        }
    }
    cout << "Total row sum: " << totalSum;
    
}


int main() {

    int arr[3][3] {
        {1, 2 ,3},
        {4, 5, 6},
        {7, 8, 9},

    };

    findRowSums(arr);
    sumAllRows(arr);


    return 0;
}
