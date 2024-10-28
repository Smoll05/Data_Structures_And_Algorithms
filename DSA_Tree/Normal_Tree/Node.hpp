#include <iostream>

struct Node {
    int val;
    Node* left;
    Node* right;
    Node* parent;

    Node(int num) : val(num), left(nullptr), right(nullptr), parent(nullptr) {}

    int height() {
        if(this == nullptr) {
            return -1;
        }

        int leftHeight = left->height();
        int rightHeight = right->height();

        return std::max(leftHeight, rightHeight) + 1;
    }

    int depth() {
        if(parent == nullptr) {
            return 0;
        }

        return parent->depth() + 1;
    }
};