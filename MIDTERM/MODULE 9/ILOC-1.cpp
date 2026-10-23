#include <iostream>
#include "BST.h"

int main(){
    // create the root node
    BinarySearchTree<int> tree(2);

    tree.insert(3);
    tree.insert(9);
    tree.insert(18);
    tree.insert(0);
    tree.insert(1);
    tree.insert(4);
    tree.insert(5);

    std::cout << "Pre order: ";
    tree.preOrder();
    std::cout << "\nIn order: ";
    tree.inOrder();
    std::cout << "\nPost order: ";
    tree.postOrder();

    return 0;
}