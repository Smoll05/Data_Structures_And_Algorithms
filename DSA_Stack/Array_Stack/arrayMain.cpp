#include <iostream>
#include "ArrayStack.cpp"

using namespace std;

int main() {
    List* stack = new ArrayStack();
    char op;
    cout << "Stack Array" << endl;

    int input;
    int topElem;

    do {
        cout << "Enter operation: ";
        cin >> op;

        switch(op) {
            case 'a':
                cin >> input;
                stack->push(input);
                break;

            case 'p':
                topElem = stack->pop();
                if(topElem != -1) cout << "Top element: " << topElem << endl;
                else cout << "Stack underflow" << endl;
                break;

            case 't':
                topElem = stack->peek();
                if(topElem != -1) cout << "Top element: " << topElem << endl;
                else cout << "Stack is Empty" << endl;
                break;

            case 'e':
                if(stack->isEmpty()) {
                    cout << "Stack is empty" << endl;
                } else {
                    cout << "Stack is not empty" << endl;
                }
                break;

            case 's':
                cout << "Size of stack: " << stack->size() << endl;
                break;

            case 'x':
                cout << "Exiting..";
                break;

            default:
                cerr << "Invalid operation" << endl;
        }
    } while(op != 'x');
}