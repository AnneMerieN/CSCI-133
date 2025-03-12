#include <iostream>

using namespace std;

template <typename T>
class Queue {
    private:
        class Node {
            public:
                T data;
                Node* next;
                Node(T data) {
                    this->data = data;
                    next = nullptr;
                }
        };

        Node* head;
        Node* tail;

    public:
        Queue() {
            head = nullptr;
            tail = nullptr;
        }

        ~Queue() {
            while (!isEmpty()) {
                remove();
            }
        }

        void add(T data);
        void remove();
        void print() const;
        bool isEmpty() const;
};

template <typename T>
bool Queue<T>::isEmpty() const {
    return head == nullptr;
}

template <typename T>
void Queue<T>::add(T data) {
    Node* nodeToAdd = new Node(data);

    if (isEmpty()) {
        head = nodeToAdd;
        tail = nodeToAdd;
    } else {
        tail->next = nodeToAdd;
        tail = nodeToAdd;
    }
}

template <typename T>
void Queue<T>::remove() {
    if (isEmpty()) { // Case 1: Queue is already empty
        cout << "Queue is empty, cannot remove." << endl;
        return;
    }
    else if (head->next == nullptr) { // Case 2: Queue has only one element
        delete head;
        head = nullptr;
        tail = nullptr;
    }
    else { // Case 3: Queue has multiple elements
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

template <typename T>
void Queue<T>::print() const {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
        return;
    }

    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Queue<int> intQueue;
    intQueue.add(1);
    intQueue.add(2);
    intQueue.add(3);
    intQueue.add(4);
    intQueue.remove();
    intQueue.remove();
    intQueue.print(); // Output: 3 4

    Queue<string> stringQueue;
    stringQueue.add("Alice");
    stringQueue.add("Bob");
    stringQueue.add("Charlie");
    stringQueue.remove();
    stringQueue.print(); // Output: Bob Charlie

    return 0;
}
