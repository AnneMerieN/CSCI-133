#include <iostream>

using namespace std;


// Part I: Singly Linked List
class SinglyLinkedList {

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

    public:
        SinglyLinkedList() {
            head = nullptr;
        }

        ~SinglyLinkedList() {
            Node* current = head;
            while (current != nullptr) {
                Node* next = current->next;
                delete current;
                current = next;
            }
        }

    // Add an element at the end
    void add(int data) {

        Node* newNode = new Node(data); // Create node to add

        if (head == nullptr) { // Empty check
            head = newNode;
        } else {
            Node* temp = head; // Create temp node and traverse to end of linked list
            while ((temp -> next) != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

// Delete an element by value
void deleteNode(int data) {
    if (head == nullptr) {
        return; // Empty list, nothing to delete
    }

    // Case 1: If the node to delete is the head
    if (head->data == data) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    // Case 2: Search for the node to delete
    Node* prev = nullptr;
    Node* temp = head;

    while (temp != nullptr && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    // If the node was not found, return
    if (temp == nullptr) { // Reached the end of the list without finding the node
        return;
    }

    // Update the previous node's next pointer to skip the deleted node
    prev->next = temp->next;

    // Delete the node
    delete temp;
}


    // Display the linked list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Part III: Reverse the Singly Linked List
    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;

        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
};


// Part II: Doubly Linked List

class DoublyLinkedList {
private:
    class Node {
    public:
        int data;
        Node* next;
        Node* prev;

        // Constructor
        Node(int data) {
            this->data = data;
            next = nullptr;
            prev = nullptr;
        }
    };

    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    ~DoublyLinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    // Add element at the beginning
    void addFirst(int data) {
        Node* newNode = new Node(data);
        if (head = nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Add element at the end
    void addLast(int data) {
        Node* newNode = new Node(data);
        if (tail = nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

// Delete a node by value
void deleteNode(int data) {
    if (head == nullptr) {
        return; // Empty list, nothing to delete
    }

    Node* temp = head;

    // Case 1: If the node to delete is the head
    if (head->data == data) {
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr; // If the list becomes empty
        }
        delete temp;
        return;
    }

    // Search for the node to delete
    while (temp != nullptr && temp->data != data) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        return; // Node not found
    }

    // Update previous and next pointers
    if (temp->prev != nullptr) {
        temp->prev->next = temp->next;
    }
    if (temp->next != nullptr) {
        temp->next->prev = temp->prev;
    }

    // If deleting the tail, update tail pointer
    if (temp == tail) {
        tail = temp->prev;
    }

    delete temp; // Free memory
}



    // Display list from front to back
    void displayForward() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Display list from back to front
    void displayBackward() {
        Node* temp = tail;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
};


// Main Function to Test All Parts
int main() {
    // ====== Part I: Singly Linked List ======
    cout << "Singly Linked List:" << endl;
    SinglyLinkedList singlyList;
    singlyList.add(10);
    singlyList.add(20);
    singlyList.add(30);
    // singlyList.display();  // Output: 10 20 30

    // singlyList.deleteNode(20);
    // singlyList.display();  // Output: 10 30

    // // ====== Part II: Doubly Linked List ======
    // cout << "\nDoubly Linked List:" << endl;
    // DoublyLinkedList doublyList;
    // doublyList.addFirst(10);
    // doublyList.addLast(20);
    // doublyList.addLast(30);

    // cout << "Forward: ";
    // doublyList.displayForward();  // Output: 10 20 30

    // cout << "Backward: ";
    // doublyList.displayBackward(); // Output: 30 20 10

    // doublyList.deleteNode(20);
    // cout << "After deleting 20:" << endl;
    // cout << "Forward: ";
    // doublyList.displayForward();  // Output: 10 30
    // cout << "Backward: ";
    // doublyList.displayBackward(); // Output: 30 10

    // // ====== Part III: Reverse Singly Linked List ======
    // cout << "\nReversing Singly Linked List:" << endl;
    singlyList.reverse();
    singlyList.display();  // Output: 30 10

    return 0;
}
