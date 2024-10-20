#include <iostream>
#include "..\include\List.hpp"
#include "..\include\Node.hpp"

using namespace std;

class ListStack : public List {
private:
    Node* head, *tail;
    int capacity;

public:
    ListStack() : head(nullptr), tail(nullptr), capacity(0) {}

    void push(int num) {
        Node* node = new Node(num);
        node->next = head;
        head = node;
        capacity++;
    }

    int pop() {
        if(!head) {
            return -1;
        }

        int elem = head->val;
        if(head == tail) {
            delete head;
            head = tail = nullptr;
            capacity--;
            return elem;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
        capacity--;
        return elem;
    }

    int peek() {
        if(!head) return -1;

        return head->val;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    int size() {
        return capacity;
    }
};