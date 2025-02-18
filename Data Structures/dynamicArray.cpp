/* Problems with static arrays:
    1. Once created, it's size cannot be changed
    2. Size must be known at compile time
    3. Lifetime of static array is tied to its scope 
    4. Large static arrays can cause stack overflow because stack has limited memory
*/

/* Other random notes:
    1. 3 TYPES OF CONST:
        a. const variables: cannot be modified after initialization
        b. const member functions: ensures the function does not modify any
            member variables (just reading data)
        c. const int* ptr = &a; // Pointer to a const int (can change what ptr points to but cannot modify the value)
        d. int* const ptr = &a; // const pointer to an int (cannot change what ptr points to but you can change value)
        e. const int* const ptr = &a // constant pointer to a constant int;
        */

#include <iostream>

using namespace std;

class DynamicArray {
    private:
        int* arr;
        int capacity;
        int size;
        void resize();
    public:
        DynamicArray(int initialCapacity = 2);
        ~DynamicArray() { delete[] arr; }
        void push(int value);
        bool isFull();
        void pop();
};

bool DynamicArray::isFull() {
    return size == capacity;
}

void DynamicArray::pop() {
    if (size > 0 ) {
        size--;
    }
}

void DynamicArray::push(int value) {
    if (isFull) {
        resize();
    }
    arr[size] = value;
    size++;
}

DynamicArray::DynamicArray(int initialCapacity = 2) {
    capacity = initialCapacity;
    size = 0;
    arr = new int[capacity];
}

void DynamicArray::resize() {
    capacity = capacity * 2;
    int* newArr = new int[capacity];
    for (int i = 0; i < size; i++) {
        newArr[i] = arr[i]; // copy old array elements to new array
    }
    delete[] arr; // delete old array
    arr = newArr; // reassign pointers
}

int main() {






    return 0;
}