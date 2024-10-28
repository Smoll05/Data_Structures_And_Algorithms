#include <iostream>
#include "Tree.cpp"

using namespace std;

int main() {
    try {
        Tree* tree = new Tree();
        Node* root = tree->addRoot(1);
        
        Node* two = tree->addLeft(root, 2);
        Node* three = tree->addRight(root, 3);

        Node* four = tree->addLeft(two, 4);
        Node* five = tree->addLeft(three, 5);
        Node* six = tree->addRight(three, 6);

        cout << "Pre-order" << endl;
        tree->preorder(root);

        cout << "In-order" << endl;
        tree->inorder(root);

        cout << "Post-order" << endl;
        tree->postorder(root);

        cout << "Level-order" << endl;
        tree->levelorder(root);

        cout << "Height of root: " << root->height() << endl;
        cout << "Height of two: " << two->height() << endl;
        cout << "Height of five: " << five->height() << endl;

        cout << "Depth of root: " << root->depth() << endl;
        cout << "Depth of two: " << two->depth() << endl;
        cout << "Depth of five: " << five->depth() << endl;

        cout << endl << "Removing Nodes: " << endl;
        // cout << tree->remove(three) << endl;
        cout << tree->remove(six) << endl;
        cout << tree->remove(two) << endl;
    } catch (const char* e) {
        cout << e << endl;
    }
}