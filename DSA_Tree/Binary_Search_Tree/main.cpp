#include <iostream>
#include <stack>
#include "Tree.cpp"
#include "Node.hpp"

using namespace std;

int main() {
    BinaryTree* tree = new BinaryTree();
    
    tree->insert(1);
    tree->insert(2);
    tree->insert(3);
    tree->insert(5);
    tree->insert(7);

    cout << tree->search(8);

    stack.push(1);
}