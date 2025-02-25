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
        ~Stack() {
            while (!isEmpty()) {
                pop();
            }
        }
        void push(int data) {
            Node* nodeToInsert = new Node(data);

            nodeToInsert->next = top;
            top = nodeToInsert;
        }
        bool isEmpty() {
            return top == nullptr;
        }
        void pop();
        

};