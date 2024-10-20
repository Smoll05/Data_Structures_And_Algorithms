#include <iostream>
#include "QueueArray.cpp"

int main() {
    Queue* queue = new QueueArray();
    char op;
    int num;

    do {
        cout << "Op: ";
        cin >> op;

        switch(op) {
            case 'e':
                cin >> num;
                queue->enqueue(num);
                break;

            case 'd':
                cout << queue->dequeue() << endl;
                break;

            case 'p':
                cout << queue->peek() << endl;
                break;

            case 's':
                queue->getSize();
                break;

            case 't':
                cout << "Is Empty: " << queue->isEmpty() << endl;
                break;

            case 'i':
                queue->print();
                break;
            
            default:
                cout << "Invalid Operation" << endl;
        }

    } while(op != 'x');
}