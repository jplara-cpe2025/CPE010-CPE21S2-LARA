#include <iostream>
#include "GeneralTree.h"

int main(){
    // create the root node
    GeneralTree<char> tree('A');

    // create the first level
    tree.insert('A', 'B');
    tree.insert('A', 'C');
    tree.insert('A', 'D');
    tree.insert('A', 'E');
    tree.insert('A', 'F');
    tree.insert('A', 'G');

    // create the children of D
    tree.insert('D', 'H');

    // create the children of E
    tree.insert('E', 'I');
    tree.insert('E', 'J');

    // create the children of J
    tree.insert('J', 'P');
    tree.insert('J', 'Q');

    // create the children of F
    tree.insert('F', 'K');
    tree.insert('F', 'L');
    tree.insert('F', 'M');

    // create the child of G
    tree.insert('G', 'N');

    std::cout << "Tree Traversal";
    std::cout << "\nPre order: ";
    tree.preOrder();
    std::cout << "\nIn order: ";
    tree.inOrder();
    std::cout << "\nPost order: ";
    tree.postOrder();

    std::cout << "\n\nfindData: 1 = pre-order, 2 = in-order, 3 = post-order";
    std::cout << "\nFinding char 'N'...\n";
    tree.findData(1, 'N');
    tree.findData(2, 'N');
    tree.findData(3, 'N');

    // add O as another child of G
    tree.insert('G', 'O');
    std::cout << "\nAdding O...";

    std::cout << "\nPre order: ";
    tree.preOrder();
    std::cout << "\nIn order: ";
    tree.inOrder();
    std::cout << "\nPost order: ";
    tree.postOrder();

    std::cout << "\n\nfindData: 1 = pre-order, 2 = in-order, 3 = post-order";
    std::cout << "\nFinding char 'O'...\n";
    tree.findData(1, 'O');
    tree.findData(2, 'O');
    tree.findData(3, 'O');

    std::cout << "\nFinding char 'i'...\n";
    tree.findData(1, 'i');
    tree.findData(2, 'i');
    tree.findData(3, 'i');

    return 0;
}