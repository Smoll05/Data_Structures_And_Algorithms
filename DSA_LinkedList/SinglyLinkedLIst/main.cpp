#include <iostream>
#include "SinglyLinkedList.cpp"

int main() {
	List* list = new SinglyLinkedList();
	char op;
    int value, pos, element, result;

	do {
        cout << "Op: ";
        cin >> op;

        switch(op) {
            case 'a':   
                cin >> value;
                list->addHead(value);
                break;

            case 'A':
                list->removeHead();
                break;
            
            case 't':
                cin >> value;
                list->addTail(value);
                break;

            case 'T':
                list->removeTail();
                break;

            case 'g':
                cin >> pos;
                element = list->get(pos);
                if(element != -1) {
                    cout << "Element at position " << pos << " is " << element << endl;
                } else {
                    cout << "Invalid Postion" << endl;
                }
                break;

            case 'p':
                list->print();
                break;

            case 'x':
                cout << "Exiting..." << endl;
                break;

            default:
                break;
        }
    } while(op != 'x');
}