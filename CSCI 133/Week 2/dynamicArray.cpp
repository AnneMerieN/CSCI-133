#include <iostream>

using namespace std;

class DynamicArray {
private:
    int size;
    int capacity;
    int* arr; // pointer to an int

public:
    DynamicArray(int initialCapacity = 2); // Constructor
    ~DynamicArray(); // Deconstructor delete[] arr
    void resize(); 
    bool isFull();
    void push(int value);
    void print() const;
};

DynamicArray::DynamicArray(int initialCapacity) {
    capacity = initialCapacity; // capacity = 2
    size = 0;
    arr = new int[capacity]; // Create dynamically allocated array and initialize it with capacity
}

bool DynamicArray::isFull() {
    return size == capacity;
}

void DynamicArray::resize() {
    capacity = capacity * 2; // double capacity
    int* newArr = new int[capacity]; // Dynamically create new array with capacity
    for (int i = 0; i < size; ++i) { // copy values from old array to new array
        newArr[i] = arr[i];
    }
    delete[] arr; // delete old array
    arr = newArr; // reassign pointers
}

void DynamicArray::push(int value) {
    if (isFull()) { 
        resize(); // Resize if full
    }
    arr[size] = value; // add value to last index of array
    size++; // increase size
}

DynamicArray::~DynamicArray() { // Deconstructor
    delete[] arr;
}

void DynamicArray::print() const {
    cout << "Array contents: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    DynamicArray myArray;

    myArray.push(10);
    myArray.push(20);
    myArray.push(30);

    myArray.print();
 
    return 0;
}
