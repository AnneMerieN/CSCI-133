#include <iostream>

using namespace std;

int binarySearchRecursive(const int arr[], int left, int right, const int numToSearch, const int size) {
    // Base Case 1: If left index exceeds right, the element is not in the array
    if (left > right) { // Means search space is exhausted
        return -1; 
    }
    // Base Case 2: Check bounds (Defensive Check)
    if (left < 0 || right >= size) {
        return -1;
    }

    // Find the middle index
    int mid = (left + right) / 2;

    // Base Case 3: If middle element is the target, return its index
    if (arr[mid] == numToSearch) {
        return mid;
        
    }   else if (numToSearch > arr[mid]) {
            int newLeft = mid + 1;
            return binarySearchRecursive(arr, newLeft, right, numToSearch, size);
        }
    
        else {
            int newRight = mid - 1;
            return binarySearchRecursive(arr, left, newRight, numToSearch, size);
        }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    int numToSearch;
    cout << "Enter a value to search: ";
    cin >> numToSearch;

    // Call recursive binary search
    int index = binarySearchRecursive(arr, 0, size - 1, numToSearch, size);

    // Output result
    if (index != -1) {
        cout << numToSearch << " is at index " << index << "." << endl;
    } else {
        cout << "Not in array." << endl;
    }

    return 0;
}