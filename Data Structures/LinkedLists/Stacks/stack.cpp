/* Array-Based Stack */

#include <iostream>

using namespace std;

class StackArray {
    private:
        int size; // maximum capacity of stack
        int* stackArr; // dynamic array to hold stack elements
        int top; // index of the top element in the stack
        void resize(); // in case stack becomes full
    public:
        StackArray(int size);
        ~StackArray();
        void push(int data);
        bool isFull();
        bool isEmpty();
        int pop();
        int peek();
        void display();
};

StackArray::StackArray(int size) {
    this->size = size;
    stackArr = new int[size];
    top = -1;
}

StackArray::~StackArray() {
    delete[] stackArr;
}

bool StackArray::isFull() {
    return top == size - 1;
}

bool StackArray::isEmpty() {
    return size == 0;
}

void StackArray::push(int data) {
    if (isFull()) {
        cout << "Stack Overflow: Cannot push " << data << endl;
        return;
    }
    stackArr[++top] = data; // increment top and add the value
}

int StackArray::pop() {
    if (isEmpty()) {
        cout << "Cannot pop. Stack is empty." << endl;
        return -1;
    }
    return stackArr[top--]; // Return the top element and decrement
    // Notes:
    // 1. arr[top]: returns the value at the top of the stack
    // 2. top--: post-decrment operator (--) decreases top after accessing arr[top]

}
int StackArray::peek() {
    if (isEmpty()) {
        cout << "Stack is empty" << endl;
        return -1;
    }

    return stackArr[top];
}

void StackArray::display() {
    if (isEmpty()) {
        cout << "Stack is empty" << endl;
        return;
    }
    cout << "Stack elements from top to bottom: ";
    for (int i = top; i >= 0; i--) {
        cout << stackArr[i] << " ";
    }
    cout << endl;
}


int main() {
    StackArray stack(5);

    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.display();


    return 0;
}