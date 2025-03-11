#include <iostream>
using namespace std;

template<typename T>

    class Queue {
        struct Node {
            T payload;
            Node* next;
            Node(const T& x) : payload(x), next(nullptr) {}
    };
        Node* head;
        Node* tail;
    public:
        Queue() : head(nullptr), tail(nullptr) {}

        bool is_empty() const { return (head == nullptr); }

        void pop() {
            if (is_empty()) throw runtime_error("oops");
            Node* victim = head;
            head = head->next;
            delete victim;
        }

        void push(const T& x) {
            Node* nn = new Node(x);
            if (is_empty()) {
                head = tail = nn;
            } else {
                tail->next = nn;
                tail = nn;
            }
        }
        T& front() {
            if (is_empty()) throw runtime_error("oops");
            return head->payload;
        }
};

int main() {
    
}
