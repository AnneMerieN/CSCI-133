#include <iostream>

using namespace std;

class Queue {
private:
    int* arr;  // Array to store queue elements
    int front, rear, size;
    int capacity; // Maximum size of the queue

public:
    Queue(int capacity) {
        this->capacity = capacity;
        arr = new int[capacity]; // Allocate memory for the array
        front = 0;
        rear = -1;
        size = 0;
    }

    ~Queue() {
        delete[] arr; // Free allocated memory
    }

    void enqueue(int data);
    void dequeue();
    int peek() const;
    void print() const;
    bool isEmpty() const;
    bool isFull() const;
};

bool Queue::isEmpty() const {
    return size == 0;
}

bool Queue::isFull() const {
    return size == capacity;
}

void Queue::enqueue(int data) {
    if (isFull()) {
        cout << "Queue is full! Cannot enqueue." << endl;
        return;
    }

    rear = (rear + 1) % capacity; // Circular increment
    arr[rear] = data;
    size++;
}

void Queue::dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty! Cannot dequeue." << endl;
        return;
    }

    front = (front + 1) % capacity; // Move front forward
    size--;
}

int Queue::peek() const {
    if (isEmpty()) {
        throw runtime_error("Queue is empty! No front element.");
    }
    return arr[front];
}

void Queue::print() const {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
        return;
    }

    cout << "Queue elements: ";
    for (int i = 0; i < size; i++) {
        cout << arr[(front + i) % capacity] << " ";
    }
    cout << endl;
}

int main() {
    Queue myQueue(5); // Create a queue with capacity 5

    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);
    myQueue.enqueue(40);
    myQueue.enqueue(50);
    myQueue.enqueue(60); // This will fail (queue is full)

    myQueue.print(); // Output: 10 20 30 40 50

    myQueue.dequeue();
    myQueue.dequeue();
    
    myQueue.print(); // Output: 30 40 50

    cout << "Front element: " << myQueue.peek() << endl; // Output: 30

    return 0;
}
