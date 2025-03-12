/* Linked-list Based Queue */

#include <iostream>

using namespace std;

class Queue {

    private:
        class Node {
            public:
                int data;
                Node* next;
                Node(int data) {
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

        void add(int data);
        void remove();
        void print() const;
        bool isEmpty() const;
};

bool Queue::isEmpty() const {
    return head == nullptr;
}

void Queue::add(int data) {
    Node* nodeToAdd = new Node(data);

    if (isEmpty()) {
        head = nodeToAdd;
        tail = nodeToAdd;
    } else {
        tail->next = nodeToAdd;
        tail = nodeToAdd;
    }
}

void Queue::remove() {
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

void Queue::print() const {
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
    Queue myQueue;

    myQueue.add(1);
    myQueue.add(2);
    myQueue.add(3);
    myQueue.add(4);
    myQueue.remove();
    myQueue.remove();

    myQueue.print();

    return 0;
}
