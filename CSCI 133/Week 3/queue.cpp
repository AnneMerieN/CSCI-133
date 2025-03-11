#include <iostream>

using namespace std;

class Queue {

    private: // ensures only LinkedList class can manage node creation and modification
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
    }

}

void Queue::remove() {

    if (isEmpty()) {
        return;
    } else {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

}

void Queue::print() const {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {

    Queue myQueue;
    Queue myQueue;

    myQueue.add(1);
    myQueue.add(2);
    myQueue.add(3);
    myQueue.add(4);
    myQueue.remove();
    myQueue.remove();

    myQueue.print();

}