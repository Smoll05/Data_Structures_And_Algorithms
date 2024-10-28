#pragma once

struct Node {
    Node** children;
    int num_child;
    Node* parent;
    int elem;

    int height() {
        if(this->num_child == 0) return 0;
        
        int maxHeight = 0;
        for(int i = 0; i < num_child; i++) {
            int height = children[i]->height();
            if(height > maxHeight) {
                maxHeight = height;
            }
        }

        return maxHeight + 1;
    }

    int depth() {
        if(parent == nullptr) {
            return 0;
        }

        return parent->depth() + 1;
    }
};