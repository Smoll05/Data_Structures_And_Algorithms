#include <iostream>
#include "LinkedQueue.cpp"

using namespace std;

int main() {
    Queue* queue = new LinkedQueue();
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
                queue->dequeue();
                break;

            case 'p':
                queue->peek();
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