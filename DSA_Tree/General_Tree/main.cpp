// DO NOT modify this file.
// Go to binarytree and mybinarytree
#include <iostream>
#include "GeneralTree.hpp"
using namespace std;

int main() {
    Tree* tree = new GeneralTree();
    Node* nodes[100];
    char op;
    int par, chi;

    do {
        try {
            cout << "Op: ";
            cin >> op;

            switch (op) {
                case 'q':
                    cin >> par;
                    nodes[par] = tree->addRoot(par);
                    break;

                case 'i':
                    cin >> par >> chi;
                    nodes[chi] = tree->addChild(nodes[par], chi);
                    break;

                case 'p':
                    tree->print();
                    break;
                    case 'd':
                    cin >> par;
                    cout << "Depth of " << par << ": " << nodes[par]->depth() << endl;
                    break;

                case 'h':
                    cin >> par;
                    cout << "Height of " << par << ": " << nodes[par]->height() << endl;
                    break;

                case 'r':
                    cin >> par;
                    tree->remove(nodes[par]);
                    break;

                case 'x':
                    cout << "Exiting...";
                    break;
            }
        } catch (exception& e) {
        cout << e.what() << endl;
        }
    } while (op != 'x');
}