/* Linked-list based stack */

#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        next = nullptr;
    }
};

class Stack {
    private:
        Node* top; // Pointer to the top node
    public:
        Stack() { top = nullptr; } // Initialize stack as empty

        void push(int data) {
            // Check if empty first
            Node* nodeToInsert = new Node(data);

            nodeToInsert->next = top; // Link new node to point to current top
            top = nodeToInsert; // reassign new top
        }

        bool isEmpty() {
            return top == nullptr;
        }

        int popvalue() {
            
            if (isEmpty()) {
                return -1;
            }
        
            int poppedValue = top->data; // Store the data to return

            Node* temp = top;            // Save the current top node
            top = top->next;             // Move top to the next node
            delete temp;                 // Delete the old top node
        
            return poppedValue;           // Return the popped value
        }
        

};