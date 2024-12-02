#pragma once
#include <algorithm>

struct Node {
    int val;
    Node* left;
    Node* right;
    Node* parent;

    int depth() {
        if(!parent) return 0;
        return parent->depth() + 1;
    }

    int height() {
        if(!this) return -1;
        return std::max(left->height(), right->height()) + 1;
    }
};