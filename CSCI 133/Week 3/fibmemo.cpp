#include <iostream>

using namespace std;

int arr[8] = {-1, -1, -1, -1, -1, -1, -1, -1}; // global variable

int fibRecursive(int n) {

    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    }

    if (arr[n-1] == -1) {
        arr[n-1] = fibRecursive(n-1) + fibRecursive(n-2);
    }

    return arr[n-1];
}

int main() {

    cout << fibRecursive(8) << endl;

    for (int i = 0; i < 8; ++i) {
        cout << arr[i] << " ";
    }

}