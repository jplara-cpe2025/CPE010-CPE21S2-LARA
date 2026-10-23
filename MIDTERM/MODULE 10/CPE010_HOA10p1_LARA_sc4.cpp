#include <iostream>

template <typename T>
class BinarySearchTree {
private:
    T key;
    BinarySearchTree<T>* left;
    BinarySearchTree<T>* right;

public:
    // Constructor
    BinarySearchTree(T value) {
        key = value;
        left = nullptr;
        right = nullptr;
    }

    // Insert a value
    void insert(T value) {
        if (value < key) {
            if (left == nullptr) {
                left = new BinarySearchTree<T>(value);
            } else {
                left->insert(value);
            }
        } else if (value > key) {
            if (right == nullptr) {
                right = new BinarySearchTree<T>(value);
            } else {
                right->insert(value);
            }
        }
    }

    // Preorder: Root, Left, Right
    void preOrder() {
        std::cout << key << " ";

        if (left != nullptr) {
            left->preOrder();
        }

        if (right != nullptr) {
            right->preOrder();
        }
    }

    // Inorder: Left, Root, Right
    void inOrder() {
        if (left != nullptr) {
            left->inOrder();
        }

        std::cout << key << " ";

        if (right != nullptr) {
            right->inOrder();
        }
    }

    // Postorder: Left, Right, Root
    void postOrder() {
        if (left != nullptr) {
            left->postOrder();
        }

        if (right != nullptr) {
            right->postOrder();
        }

        std::cout << key << " ";
    }
};

int main() {
    BinarySearchTree<int> tree(2);

    tree.insert(3);
    tree.insert(9);
    tree.insert(18);
    tree.insert(0);
    tree.insert(1);
    tree.insert(4);
    tree.insert(5);

    std::cout << "Preorder: ";
    tree.preOrder();

    std::cout << "\nInorder: ";
    tree.inOrder();

    std::cout << "\nPostorder: ";
    tree.postOrder();

    return 0;
}