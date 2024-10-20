#include <iostream>
#include "Node.hpp"

using namespace std;

class Stack {
private:
    Node* head, *tail;
    int size;

public:
    Stack() {
        head = tail = nullptr;
        size = 0;
    }

    void push(int c) {
        Node* node = new Node(c);
        if(!head) {
            head = tail = node;
            size++;
            return;
        }

        node->next = head;
        head = node;
        size++;
        return;
    }

    int pop() {
        if(!head) {
            cout << "Stack Underflow" << endl;
            size--;
            return -1;
        }

        Node* temp;
        int res;

        if(head == tail) {
            temp = head;
            head = tail = nullptr;
            res = temp->val;
            delete temp;
            size--;
            return res;
        }

        temp = head;
        head = head->next;
        res = temp->val;
        delete temp;
        size--;
        return res;
    }

    int peek() {
        if(!head) {
            cout << "Stack Underflow" << endl;
            size--;
            return -1;
        }

        return head->val;
    }

    bool isEmpty() {
        return size == 0;
    }
};