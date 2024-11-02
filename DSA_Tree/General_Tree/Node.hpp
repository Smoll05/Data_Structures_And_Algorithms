#pragma once
#include <algorithm>

struct Node {
    int val;
    int num_child;
    Node* parent;
    Node** children;

    int depth() {
        if(!parent) return 0;
        return parent->depth() + 1;
    }

    int height() {
        int maxHeight = 0;
        for(int i = 0; i < num_child; i++) {
            maxHeight = std::max(children[i]->height() + 1, maxHeight);
        }

        return maxHeight;
    }
};