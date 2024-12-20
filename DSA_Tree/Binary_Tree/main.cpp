// DO NOT modify this file.
// Go to binarytree and mybinarytree
#include <iostream>
#include "BinaryTree.hpp"
using namespace std;

int main(void) {
    BinaryTree* tree = new BinaryTree();
    BinaryTree* attach = new BinaryTree();

    Node* attachRoot = attach->addRoot(5);
    attach->addRight(attachRoot, 6);
    attach->addLeft(attachRoot, 7);

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
                
                case 'L':
                    cin >> input;
                    cin >> ind;
                    nodes[input] = tree->addLeft(nodes[ind], input);
                    if (nodes[input]) {
                        cout << nodes[input]->val << " added as left of " << nodes[ind]->val << endl;
                    }
                    break;
                
                case 'R':
                    cin >> input;
                    cin >> ind;
                    nodes[input] = tree->addRight(nodes[ind], input);
                    if (nodes[input]) {
                        cout << nodes[input]->val << " added as right of " << nodes[ind]->val << endl;
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

                case 'H':
                    cin >> ind;
                    cout << "Height of " << nodes[ind]->val << ": " << nodes[ind]->height() << endl;
                    break;
                
                case 'D':
                    cin >> ind;
                    cout << "Depth of " << nodes[ind]->val << ": " << nodes[ind]->depth() << endl;
                    break;

                case '@':
                    cin >> ind;
                    tree->attachSibling(nodes[ind], attach);
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