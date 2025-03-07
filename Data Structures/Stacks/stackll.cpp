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
        Node* top; 
    public:
        Stack() { top = nullptr; } 

        ~Stack() { 
            while (!isEmpty()) {
                pop();
            }
        }

        void push(int data) {
            Node* nodeToInsert = new Node(data);
            nodeToInsert->next = top; // Link new node to current top
            top = nodeToInsert; 
        }

        bool isEmpty() {
            return top == nullptr;
        }

        int pop() { 
            if (isEmpty()) {
                cout << "Stack Underflow: Cannot pop from an empty stack." << endl;
                return -1;
            }

            int poppedValue = top->data; // Store data to return
            Node* temp = top;            
            top = top->next;             
            delete temp;                 
        
            return poppedValue;
        }

        int peek() {
            if (isEmpty()) {
                cout << "Stack is empty." << endl;
                return -1;
            }
            return top->data;
        }

        void display() {
            if (isEmpty()) {
                cout << "Stack is empty." << endl;
                return;
            }
            Node* current = top;
            cout << "Stack elements from top to bottom: ";
            while (current != nullptr) {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }
};

int main() {
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);
    
    cout << "Top element: " << stack.peek() << endl;
    cout << "Popped: " << stack.pop() << endl;
    
    stack.display();

    return 0;
}
