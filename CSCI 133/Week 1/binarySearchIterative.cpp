/* Binary search only works for sorted data.
    Use linear search if the data is unsorted and you only need to search once.

    Binary search works by:
        1. Checking the middle element.
        2. If it's equal to the search value, we return its index.
        3. If it's smaller, we search the right half of the array.
        4. If it's larger, we search the left half of the array.
        5. We repeat the process until the value is found or the search space is empty.
        6. We divide the search space in half each time.
 */

#include <iostream>

using namespace std;


int binarySearch(const int arr[], int size, int numToSearch) { // Returns the index of that number 

        // Define search boundaries
    int leftIndex = 0;
    int rightIndex = size - 1;

    while (leftIndex <= rightIndex) {
        int mid = leftIndex + (rightIndex + leftIndex) / 2;

        if (arr[mid] == numToSearch) {
            return mid; // Value found at index mid
        } else if (arr[mid] < numToSearch) {
            leftIndex = mid + 1; // Update leftIndex index to the left side of the right half of mid
        } else {
            rightIndex = mid - 1; // Search left half
        }
    }
    return -1; // Value not found
    
}

int main() {

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    int numToSearch;
    cout << "Enter a value to search: ";
    cin >> numToSearch;

    int index = binarySearch(arr, size, numToSearch);

    
    cout << numToSearch << " is at index " << index << "." << endl;
    

    return 0;
}