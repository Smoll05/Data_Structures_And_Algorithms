#pragma once

struct Node {
    int val;
    Node* next;

    Node(int num) : val(num), next(nullptr) {}
};