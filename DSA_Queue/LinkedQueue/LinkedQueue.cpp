#include <iostream>
#include "..\Queue.hpp"
#include "Node.hpp"

using namespace std;

class LinkedQueue : public Queue {
private:
    Node* head; // front
    Node* tail; // rear
    int size;

public:
    void enqueue(int num) {
        Node* node = new Node();
        node->val = num;

        if(!head) {
            head = tail = node;
            size++;
            return;
        }

        node->next = head;
        head = node;
        size++;
    }


    int dequeue() {
        if(!head) {
            cout << "Queue is Empty!" << endl;
            size--;
            return -1;
        }

        Node* temp = head;
        int ret = head->val;
        head = head->next;
        delete temp;
        size--;
        return ret;
    }


    int peek() {
        if(!head) {
            cout << "Queue is Empty!" << endl;
            return -1;
        }

        return head->val;
    }


    int getSize() {
        return size;
    }


    bool isEmpty() {
        return size == 0;
    }


    void print() {
        Node* curr = head;  
        while(curr) {
            cout << curr->val;
            if(!curr->next) {
                cout << " -> " << endl;
            }
            curr = curr->next;
        }
        cout << endl;
    }

};