#ifndef BST_H
#define BST_H

template <typename T>
class BinarySearchTree{
    private:
        // create a key
        T key;
        // pointers for left and right
        BinarySearchTree<T>* left;
        BinarySearchTree<T>* right;
    public:
        // constructor
        BinarySearchTree(T value);

        // insert left and right
        void insert(T value);
        // traversing
        void preOrder();
        void inOrder();
        void postOrder();
        // searching
};

template <typename T>
BinarySearchTree<T>::BinarySearchTree(T value){
    key = value;
    left = nullptr;
    right = nullptr;
}

template <typename T>
void BinarySearchTree<T>::insert(T value){
    // left or right
    
    // go left if value < key insert to left
    if(value < key){
        if(left == nullptr){
            left = new BinarySearchTree<T>(value);
        } else {
            left->insert(value);
        }
    } else if(value > key){ 
        if(right == nullptr){
            right = new BinarySearchTree<T>(value);
        } else {
            right->insert(value);
        }
    }
}

template <typename T>
void BinarySearchTree<T>::preOrder(){
    std::cout<< key << " ";
    if (left != nullptr){
        left->preOrder();
    }
    if (right != nullptr){
        right->preOrder();
    }
}
// aggressively go to the left then right
// left root right
template <typename T>
void BinarySearchTree<T>::inOrder(){
    // go to left
    if (left != nullptr){
        left->inOrder();
    }
    std::cout<< key << " ";
    // goto right
    if (right != nullptr){
        right->inOrder();
    }
}

// left then right then root
template <typename T>
void BinarySearchTree<T>::postOrder(){
    // go to left
    if (left != nullptr){
        left->postOrder();
    }
    // goto right
    if (right != nullptr){
        right->postOrder();
    }
    std::cout<< key << " ";
}


#endif