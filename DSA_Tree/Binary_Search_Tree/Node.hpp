#ifndef NODE_HPP
#define NODE_HPP

struct Node {
    int val;
    Node* left;
    Node* right;
    Node* parent;

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

#endif