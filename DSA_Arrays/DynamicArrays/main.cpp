#include <iostream>
#include "DynamicArray.cpp"
using namespace std;

int main() {
    List* list = new DynamicArray();
    char ch;
    int num, pos;	
    do {
        cout << "Op: ";
        cin >> ch;
        switch (ch) {
            case 'a':
                cin >> num;
                list->add(num);
                break;
			case '@':
				cin >> num >> pos;
                list->addAt(num, pos);
                break;
            case 'r':
				cin >> num;
                cout << "Remove "<<num << " at pos " << list->remove(num) << endl;
                break;
			case '#':
                cin >> pos;
                cout << "Removed " << list->removeAt(pos) << endl;
                break;
            case 'p':
                list->print();
                break;
			case 'g':
				cin >> pos;
				cout << "Element: " << list->get(pos) << endl;
				break;
            case 'x':
                cout << "Exiting...";
                break;
            default:
                cout << "Invalid operation" << endl;
        }
    } while (ch != 'x');
    return 0;
}