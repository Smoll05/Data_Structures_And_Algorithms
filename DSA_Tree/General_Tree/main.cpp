#include <iostream>
#include <cassert>
#include "Node.hpp"
#include "GeneralTree.cpp"

using namespace std;

int main() {
    GeneralTree tree;

    // Test 1: Add Root
    Node* root = tree.addRoot(1);
    assert(root != nullptr);  // Root should be added successfully
    assert(root->elem == 1);  // Verify root's value
    assert(root->num_child == 0);  // Ensure no children initially
    assert(root->parent == nullptr);  // Root has no parent

    // Test 2: Try Adding Another Root (Should Fail)
    Node* secondRoot = tree.addRoot(2);
    assert(secondRoot == nullptr);  // Adding another root should return nullptr

    // Test 3: Add Children to Root
    Node* child1 = tree.addChild(root, 2);
    Node* child2 = tree.addChild(root, 3);
    assert(child1 != nullptr && child2 != nullptr);  // Children should be added
    assert(root->num_child == 2);  // Root should have two children
    assert(child1->parent == root);  // Verify parent-child relationship
    assert(child2->parent == root);


    // Test 4: Add Child to child1
    Node* grandchild = tree.addChild(child1, 4);
    assert(grandchild != nullptr);  // Ensure grandchild is added
    assert(grandchild->parent == child1);  // Verify parent relationship
    assert(child1->num_child == 1);  // child1 should have one child

    // Test 5: Preorder Traversal Output
    cout << "Preorder Traversal Output:" << endl;
    tree.preorder(root);  // Expected output: 1, 2, 4, 3

    cout << root->height() << endl;
    // Test 6: Validate Node Height
    
    assert(root->height() == 2);  // Height of root should be 2 (root -> child1 -> grandchild)
    assert(child1->height() == 1);  // Height of child1 should be 1
    assert(grandchild->height() == 0);  // Height of leaf node should be 0

    // Test 7: Validate Node Depth
    assert(root->depth() == 0);  // Root has depth 0
    assert(child1->depth() == 1);  // child1 has depth 1
    assert(grandchild->depth() == 2);  // Grandchild has depth 2


    // Test 8: Null Parent Check for addChild
    Node* invalidChild = tree.addChild(nullptr, 5);
    assert(invalidChild == nullptr);  // Should return nullptr for null parent

    cout << "All tests passed!" << endl;

    return 0;
}
