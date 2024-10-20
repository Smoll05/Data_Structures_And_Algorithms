#include <iostream>
#define MAX_SIZE 100

using namespace std;

class Stack {
private:
    int stack[MAX_SIZE];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(int num) {
        if(top == MAX_SIZE - 1) {
            cerr << "Stack Overflow" << endl;
            exit(EXIT_FAILURE);
        }

        stack[++top] = num;
    }

    int pop() {
        if(top == -1) {
            cerr << "Stack Underflow" << endl;
            exit(EXIT_FAILURE);
        }

        return stack[top--];
    }

    int peek() {
        if(top == -1) {
            cout << "Stack is empty" << endl;
            return -1;
        }

        return stack[top];
    }

    bool isEmpty() {
        return top == -1;
    }
};