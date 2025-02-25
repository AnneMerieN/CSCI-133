/* Singly-Linked List Implementation */

#include <iostream>

using namespace std;

// A node has two parts:
//  1. data (int, string, etc.)
//  2. pointer to the next node

class Node {
    public:
        int data;
        Node* next;

        Node(int data) {
            this->data = data; // sets value of member variable data to the argument provided in main()
            next = nullptr; // pointer to another Node; since this is a new node, it doesn't point to anything yet
    
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
        int getSize() const { return size; }
        void append(int data);
        void prepend(int data);
        bool isEmpty() const;
        void toString() const; // prints out linkedlist
        void removeFirst();
        void removeLast();
        void removeAt(int pos);
        void insertAt(int pos, int data);
};

bool LinkedList::isEmpty() const {
    return (head == nullptr);
}

void LinkedList::append(int data) {

    Node* nodeToAppend = new Node(data);

    // Case 1 : Empty List
    if (head == nullptr) {
        head = nodeToAppend;
        tail = nodeToAppend;
    } else { // Case 2 : List is not empty
        tail->next = nodeToAppend;
        tail = nodeToAppend;

    }

    // Increment size counter
    size++;

} 

void LinkedList::prepend(int data) {
    Node* nodeToPrepend = new Node(data);

    if(isEmpty()) { // Case 1: Empty List
        head = nodeToPrepend;
        tail = nodeToPrepend;
    } else { // Case 2: List is not empty
        Node* temp = head;
        head = nodeToPrepend;
        nodeToPrepend->next = temp;
    }

    size++; // Increment the size

}
void LinkedList::toString() const{
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

void LinkedList::removeFirst() {
    // Case 1: empty list
    // Case 2: not empty list
    if(!isEmpty()) {
        Node* temp = head;
        head = head->next; // head points to second node
        delete temp;
        size--;
    }

}
void LinkedList::removeLast() {
    // Case 1: Empty
    // Case 2: 1 Node
    if (head->next == nullptr) {
        removeFirst();
    } else if (!isEmpty()) { // Case 3: More than 1
        Node* curr = head;
        Node* prev;

        while (curr->next != nullptr) {
            prev = curr;
            curr = curr->next;
        }

        tail = prev;
        prev->next = nullptr;
        delete curr;
        size--;
    }
}
void LinkedList::removeAt(int pos) {
    // Case 1: check for valid pos
    // Case 2: check if Pos is the first Node
    // Case 3: check if pos is at the last Node
    // Case 4: All other cases

    if (pos < 1 || pos > size) {
        return;
    } else if (pos == 1) {
        removeFirst();
    } else if (pos == size) { // size is the number of nodes within a linked list
        removeLast();
    } else if (!isEmpty()) {
        Node* prev;
        Node* curr = head;

        for (int i = 1; i < pos; i++) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        delete curr;
        size--;

    }

    }

void LinkedList::insertAt(int pos, int data) {
    // Case 1: check for valid pos
    // Case 2: check if insertion at beginning of list
    // Case 3: check if insertion at end of list
    // Case 4: all other cases

    if (pos < 0 || pos > size) { // invalid positions
        return;
    } else if (pos == 0) { // insertion at beginning
        prepend(data);
    } else if (pos == size) { // insertion at end
        append(data);
    } else if (!isEmpty()) {
        // Create node to insert
        Node* nodeToInsert = new Node(data);

        // Create prev and curr pointers
        Node* prev;
        Node* curr = head;

        for (int i = 0; i < pos; i++) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = nodeToInsert;
        nodeToInsert->next = curr;
        size++;
    }
}
LinkedList::~LinkedList() {
    Node* next;
    while(!isEmpty()) {
        next = head->next;
        delete head;
        head = next;
    }
}


int main () {
    LinkedList list;

    list.append(1);
    list.append(4);
    list.append(3);
    list.toString();
    list.removeAt(2);
    list.toString();

    return 0;

}