#include <iostream>

using namespace std;

class Node {
    public:
        int data;
        Node* next;
        Node* prev;

        // Constructor
        Node (int data) {
            this->data = data;
            next = nullptr;
            prev = nullptr;
        }

        Node* getNext() const { return next; }
        void setNext(Node* n) { next = n; }
        int getVal() { return data; }
};


class LinkedList {
    private:
        Node* head;
        Node* tail;
        int size;
    public:
        LinkedList() { // Default Constructor
            head = nullptr;
            tail = nullptr;
            size = 0;
        }

        ~LinkedList();
        bool isEmpty() { return head == nullptr; }
        void append(int data);
        void prepend(int data);
        void removeFirst();
        void removeLast();
        void print() const;
        void deleteAt(int x);
};

void LinkedList::deleteAt(int x) {

    if (head != nullptr) {
        Node* prev = head;
        Node* curr = head;

        for (int i = 0; i < x; i++) {
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;
        delete curr;
        
    }

}

void LinkedList::removeLast() {
    if (isEmpty()) {
        return;
    } else if (head->next == nullptr) { // If one node
        removeFirst();
        size--;
    } else { // if more than one node
        Node* curr = head;
        Node* prev = nullptr;

        while (curr->next != nullptr) { // Loop through linked list
            prev = curr;
            curr = curr->next;
        }
        tail = prev;
        prev->next = nullptr;
        delete curr;
        size--;
    }
}

void LinkedList::removeFirst() {
    if (isEmpty()) {
        return;
    } else {
        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
    }
}

void LinkedList::print() const {
    Node* temp = head;

    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next; // Advance pointer to next node
    }

    cout << endl;
    delete temp;
}

LinkedList::~LinkedList() {
    Node* next;
    while(!isEmpty()) {
        next = head->next;
        delete head;
        head = next;
    }
}

// Add to front
void LinkedList::prepend(int data) {
    
    Node* nodeToPrepend = new Node(data);

    if (isEmpty()) {
        head = nodeToPrepend;
        tail = nodeToPrepend;
    } else {
        nodeToPrepend->next = head;
        head = nodeToPrepend;
    }
    size++;
}

// Add node to end
void LinkedList::append(int data) {

    Node* nodetoAppend = new Node(data);

    if(isEmpty()) { // Case 1: empty
        head = nodetoAppend;
        tail = nodetoAppend;
    } else { // Case 2: not empty
        tail->next = nodetoAppend;
        tail = nodetoAppend;
    }
    size++;
}


int main() {
    LinkedList list;
    Node node(10);
    node.getVal();


    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.deleteAt(1);
    

    list.print();



    return 0;

}