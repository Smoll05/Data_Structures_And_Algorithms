#include <iostream>
#include "BinarySearchTree.hpp"
using namespace std;

int main(void) {
    Tree* tree = new BinarySearchTree();

    char op;
    int input, ind;
    Node* nodes[100];
    int res;

    do {
        try {
            cout << "Op: ";
            cin >> op;

            switch (op) {
                case 'Q':
                    cin >> input;
                    nodes[input] = tree->addRoot(input);
                    if (nodes[input]) {
                        cout << nodes[input]->val << " added as root" << endl;
                    }
                    break;
                
                case 'A':
                    cin >> input;
                    nodes[input] = tree->addNode(input);
                    if (nodes[input]) {
                        cout << nodes[input]->val << " added " << endl;
                    }
                    break;

                case '-':
                    cin >> ind;
                    res = tree->remove(nodes[ind]);
                    cout << "Removed " << res << endl;
                    break;

                case 'p':
                    tree->print();
                    break;

                case 'P':
                    tree->inorder();
                    break;

                case 'H':
                    cin >> ind;
                    cout << "Height of " << nodes[ind]->val << ": " << nodes[ind]->height() << endl;
                    break;
                
                case 'D':
                    cin >> ind;
                    cout << "Depth of " << nodes[ind]->val << ": " << nodes[ind]->depth() << endl;
                    break;
                
                case 'x':
                    cout << "Exiting" << endl;
                    break;
                    default:
                    cout << "Invalid operation" << endl;
            }
        } catch (exception& e) {
            cout << e.what() << endl;
        }
    } while (op != 'x');

    return 0;
}