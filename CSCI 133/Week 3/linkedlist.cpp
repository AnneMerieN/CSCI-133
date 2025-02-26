#include <iostream>

using namespace std;

class Node {
    public:
        int data;
        Node* next;

        Node (int data) {
            this->data = data;
            next = nullptr;
        }
};


class LinkedList {
    private:
        Node* head;
        Node* tail;
        int size;
    public:
        bool isEmpty() { return head == nullptr; }
};


int main() {
    LinkedList list;



    return 0;

}