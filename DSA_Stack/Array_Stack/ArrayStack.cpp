#include <iostream>
#include "..\include\List.hpp"
#define MAX_SIZE 100

using namespace std;

class ArrayStack : public List {
    int data[MAX_SIZE];
    int top;

public:
    ArrayStack() {
        top = -1;
    }

    void push(int num) {
        if(top == MAX_SIZE - 1) {
            cerr << "Stack overflow" << endl;
            return;
        }

        data[++top] = num;
    }

    int pop() {
        if(isEmpty()) {
            return -1;
        }

        return data[top--];
    }

    int peek() {
        if(isEmpty()) {
            return -1;
        }
        return data[top];
    }

    bool isEmpty() {
        return top == -1;
    }

    int size() {
        return top + 1;
    }
};