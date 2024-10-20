#include <iostream>
#include <cctype>
#include "Stack.cpp"

using namespace std;

int calculator(int op1, int op2, char operand) {
    switch(operand) {
        case '+':
            return op1 + op2;
        case '-':
            return op1 - op2; 
        case '*':
            return op1 * op2;
        case '/':
            return op1 / op2;
        default:
            cerr << "Invalid Operation" << endl;
            exit(EXIT_FAILURE);
    }
} 

int prefixCalculator(string exp) {
    Stack* stack = new Stack();
    int length = exp.length();
    int op1, op2;
    char c;

    for(int i = length - 1; i >= 0; i--) {
        c = exp[i];

        if(isdigit(c)) {
            stack->push(c - '0');
        } else {
            op1 = stack->pop();
            op2 = stack->pop();
            stack->push(calculator(op1, op2, c));
        }
    }
    return stack->pop();
}

int main() {
    string exp;
    cout << "Enter prefix expression: ";
    cin >> exp;

    int res = prefixCalculator(exp);
    cout << "The answer is: " << res << endl;
}