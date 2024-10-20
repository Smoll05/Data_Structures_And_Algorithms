#include <iostream>
#define MAX_SIZE 100
using namespace std;

class Stack {
private:
    char stack[MAX_SIZE];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(char c) {
        if(top == MAX_SIZE - 1) {
            cout << "Stack Overflow" << endl;
            return;
        }

        stack[++top] = c;
    }

    char pop() {
        if(top == -1) {
            cout << "Stack Underflow" << endl;
            return -1;
        }

        return stack[top--];
    }

    char peek() {
        if(top == -1) {
            cout << "Stack Empty" << endl;
            return -1;
        }

        return stack[top];
    }

    bool isEmpty() {
        return top == -1;
    }
};

bool isBalanced(string parentheses) {
    Stack* stack = new Stack();

    for (char c : parentheses) {
        if(c == '(' || c == '[' || c == '{') {
            stack->push(c);
        } else {
            if(stack->isEmpty()) {
                return false;
            }

            if(stack->peek() == '(' && c != ')' || 
               stack->peek() == '[' && c != ']' || 
               stack->peek() == '{' && c != '}') {
                return false;
            } else {
                stack->pop();
            }
        }
    }
    return stack->isEmpty();
}

int main() {
    string parentheses;
    cout << "Enter a parentheses: ";
    cin >> parentheses;

    if(isBalanced(parentheses)) {
        cout << "The parentheses is balanced" << endl;
    } else {
        cout << "The parentheses is not balanced" << endl;
    }
}