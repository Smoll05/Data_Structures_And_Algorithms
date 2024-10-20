#include <iostream>
#include "..\Queue.hpp"

#define MAX_SIZE 100

using namespace std;

class QueueArray : public Queue {
private:
    int queue[MAX_SIZE];
    int front;
    int rear;

public:
    QueueArray() : front(0), rear(-1) {}


    void enqueue(int num) {
        if(rear == MAX_SIZE - 1) {
            cout << "Queue Overflow" << endl;
            return;
        }

        queue[++rear] = num;
    }


    int dequeue() {
        if(front > rear) {
            cout << "Queue is Empty" << endl;
            return -1;
        }

        return queue[front++];
    }


    int peek() {
        if(front > rear) {
            cout << "Queue is Empty" << endl;
            return -1;
        }

        return queue[front];
    }


    int getSize() {
        return (rear + 1) - front;
    }


    bool isEmpty() {
        return front > rear;
    }


    void print() {
        if(isEmpty()) {
            cout << "Empty" << endl;
            return;
        }
        
        for(int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
};