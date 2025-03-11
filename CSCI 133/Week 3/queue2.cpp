#include <iostream>
using namespace std;

template<typename T>

    class Queue {

        // Private members
        private:
            struct Node {
                T payload;
                Node* next;

                // Constructor
                Node(const T& x) {
                    payload = x;
                    next = nullptr;
                }
            };

            Node* head;
            Node* tail;
            
        // Public members
        public:
            Queue() {
                head = nullptr;
                tail = nullptr;
            }

            bool is_empty() const { return (head == nullptr); }

            void pop() {
                if (is_empty()) {
                    throw runtime_error("Queue is empty");
                }
                Node* victim = head;
                head = head->next;
                delete victim;
            }

            void push(const T& x) {
                Node* nn = new Node(x);
                if (is_empty()) {
                    head = nn;
                    tail = nn;
                } else {
                    tail->next = nn;
                    tail = nn;
                }
            }
            T& front() {
                if (is_empty()) {
                    throw runtime_error("Queue is empty");
                }
                return head->payload;
            }
    };

int main() {


    return 0;
}
