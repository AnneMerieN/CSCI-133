#include <iostream>

using namespace std;

int main() {

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8 , 9, 10};

    int size = sizeof(arr) / sizeof(arr[0]);

    int numToSearch;
    cout << "Search: " << flush;
    cin >> numToSearch;

    bool found = false;


    for (int i = 0; i < size; i++) {
        if (numToSearch == arr[i]) {
            cout << numToSearch << " is at index " << i << ".";
            found = true;
        }
    }

    if (!found) {
        cout << "Not in array" << endl;
    }

    return 0;
}