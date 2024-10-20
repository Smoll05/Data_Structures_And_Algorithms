#include <iostream>
#include <cctype>
#include "Stack.cpp"

using namespace std;

int operationResult(int op1, int op2, char operand) {
    switch(operand) {
        case '+':
            return op1 + op2;
        case '-':
            return op2 - op1;
        case '*':
            return op1 * op2;
        case '/':
            return op2 / op1;
        default:
            return 0;
    }
}

int postfixCalculator(string equation) {
    Stack* stack = new Stack();
    int res, op1, op2;

    for(char c : equation) {
        if(isdigit(c)) {
            stack->push(c - '0');
        } else {
            op1 = stack->pop();
            op2 = stack->pop();
            stack->push(operationResult(op1, op2, c));
        }
    }
    return stack->pop();
}

int main() {
    string equation;
    cout << "Enter postfix equation: ";
    cin >> equation;

    int res = postfixCalculator(equation);

    cout << "The answer is: " << res << endl;
}