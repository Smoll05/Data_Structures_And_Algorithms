#include <iostream>
#include <stdexcept>

#include "minHeap.cpp"

using namespace std;

int main() {
    MinHeap* minHeap = new MinHeap();

    char op;
    int input;

    do {
        cout << "Enter op: ";
        cin >> op;

        try {
            switch(op) {
                case 'i':
                    cout << "Enter value to insert: ";
                    cin >> input;
                    cout << "Inserted " << minHeap->insert(input) << endl;
                    break;

                case 'r':
                    cout << "Removed " << minHeap->deleteMin() << endl;
                    break;

                case 'p':
                    minHeap->print();
                    break;

                case 'L':
                    cout << "Enter index: ";
                    cin >> input;
                    cout << "Left of " << minHeap->getValue(input) << " is " << minHeap->getLeft(input) << endl;
                    break;

                case 'R':
                    cout << "Enter index: ";
                    cin >> input;
                    cout << "Right of " << minHeap->getValue(input) << " is " << minHeap->getLeft(input) << endl;
                    break;

                case 'P':
                    cout << "Enter index: ";
                    cin >> input;
                    cout << "Parent of " << minHeap->getValue(input) << " is " << minHeap->getParent(input) << endl;
                    break;

                case 'x':
                    cout << "Exiting";
                    break;
            }
        } catch(const logic_error& e) {
            cerr << "Logic Error: " << e.what() << endl;
        }

    } while(op != 'x');
}