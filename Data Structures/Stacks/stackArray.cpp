#include <iostream>

using namespace std;

class StackArray {
    private:
        int size; // Maximum capacity of stack
        int* stackArr; 
        int top; // Index of the top element in the stack
        void resize(); // Resize the stack when full

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

// Constructor
StackArray::StackArray(int size) {
    this->size = size;
    stackArr = new int[size]; // Dynamically create array
    top = -1; // Empty stack
}

// Deconstructor
StackArray::~StackArray() {
    delete[] stackArr;
}

// Check if full (if top index == last index)
bool StackArray::isFull() {
    return top == size - 1;
}

// Empty Check
bool StackArray::isEmpty() {
    return top == -1;
}

// Push
void StackArray::push(int data) {
    if (isFull()) {
        // Would have to call potential resize()
        return;
    }
    top++; // Increment top index
    stackArr[top] = data; // Assign index top with data
}

// Pop function return value that is being popped
int StackArray::pop() {
    if (isEmpty()) {
        cout << "Cannot pop. Stack is empty." << endl;
        return -1;
    }
    return stackArr[top]; // Return top element
    top--; // Decrement index top
}

int StackArray::peek() {
    if (isEmpty()) {
        cout << "Stack is empty" << endl;
        return -1;
    }
    return stackArr[top]; // Return top element
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
    
    cout << "Popped: " << stack.pop() << endl;
    cout << "Top element: " << stack.peek() << endl;
    
    stack.display();

    return 0;
}
