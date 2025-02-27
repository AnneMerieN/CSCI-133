/* Doubly-Linked List Implementation */

#include <iostream>

using namespace std;

class Node {
    public:
        int data;
        Node* next;
        Node* prev;

        Node(int data) {
            this->data = data; // sets value of member variable data to the argument provided in main()
            next = nullptr; // pointer to another Node; since this is a new node, it doesn't point to anything yet
            prev = nullptr;
        }
};

class LinkedList {
    private:
        Node* head;
        Node* tail;
        int size;
    public:
        LinkedList() { head = nullptr; tail = nullptr, size = 0; }
        ~LinkedList();
        int getSize() { return size; }
        void append(int data);
        void prepend(int data);
        bool isEmpty();
        void toString(); // prints out linkedlist
        void removeFirst();
        void removeLast();
        void removeAt(int pos);
        void insertAt(int pos, int data);
        void toStringReverse();
};

bool LinkedList::isEmpty() {
    return (head == nullptr);
}

LinkedList::~LinkedList() {
    Node* next;
    while(!isEmpty()) {
        next = head->next;
        delete head;
        head = next;
    }
}

void LinkedList::toString() {
    // Create a temp pointer that points to first Node
    Node* temp = head;
    // Create loop that stops when pointer is null
    while (temp != nullptr) {
        // Print data
        cout << temp->data << " ";
        // Advance pointer to next node to avoid infinite loop
        temp = temp->next;


    }
    cout << endl;
}
void LinkedList::prepend(int data) {
    Node* nodeToPrepend = new Node(data);

    if (isEmpty()) {
        head = nodeToPrepend;
        tail = nodeToPrepend;
    } else {
        head->prev = nodeToPrepend;
        nodeToPrepend->next = head;
        head = nodeToPrepend;
    }
    size++;
}
void LinkedList::append(int data) {
    Node* nodeToAppend = new Node(data);

    if (isEmpty()) {
        head = nodeToAppend;
        tail = nodeToAppend;
    } else {
        tail->next = nodeToAppend;
        nodeToAppend->prev = tail;
        tail = nodeToAppend;
    }
    size++;
}

void LinkedList::insertAt(int pos, int data) {
    if (pos < 0 || pos > size) {
        return;
    } else if (pos == 0) {
        prepend(data);
    } else if (pos == size) {
        append(data);
    } else {
        Node* nodeToInsert = new Node(data);

        Node* curr = head;

        for (int i = 0; i < pos; ++i) {
            curr = curr->next;
        }

        curr->prev->next = nodeToInsert; // next pointer of curr's prev node
        nodeToInsert->prev = curr->prev;
        nodeToInsert->next = curr;
        curr->prev = nodeToInsert;
    }
    size++;
}

void LinkedList::toStringReverse() {
    // Create a temp pointer that points to the tail
    Node* temp = tail;
    // Create a loop that keeps executing till pointer is nullptr
    while (temp != nullptr) {
        // Print data
        cout << temp->data << " ";

        // Advance pointer to next node
        temp = temp->prev;
    }

    cout << endl;

}
void LinkedList::removeFirst() {
    
    if (head->next = nullptr) { // 1 node
        delete head;
        head = nullptr;
        tail = nullptr;
        size--;
    } else if (!isEmpty()) {
        head = head->next;
        delete head->prev;
        head->prev = nullptr;
        size--;
    }

}

void LinkedList::removeLast() {
    if (isEmpty()) { // First case: empty list
        return;
    } else if (head->next == nullptr) { // Second case: 1 node
        delete head;
        head = nullptr;
        tail = nullptr;
        size--;
    } else if (!isEmpty()) { // Third case: all other cases
        tail = tail->prev;
        delete tail->next;
        tail->next = nullptr;
        size--;
    }
}
void LinkedList::removeAt(int pos) {
    // Check if position is a valid position
    if (pos < 0 || pos > size) {
        return;
    } else if (pos == 0) {
        removeFirst();
    } else if (pos == size) {
        removeLast();
    } else {
        Node* curr = head;

        for (int i = 0; i < pos; i++) {
            curr = curr->next;
        }
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        delete curr;

    }
    size--;
}

int main() {
    LinkedList list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);

    list.removeAt(1);

    list.toString();

}

    