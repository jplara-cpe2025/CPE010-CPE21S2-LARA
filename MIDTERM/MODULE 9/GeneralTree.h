#ifndef GENERAL_TREE_H
#define GENERAL_TREE_H

template <typename T>
class GeneralTree{
    private:
        // create a key
        T key;
        // pointers for first child and next siblings
        GeneralTree<T>* firstChild;
        GeneralTree<T>* nextSibling;
        // search helper functions
        bool findPreOrder(T value);
        bool findInOrder(T value);
        bool findPostOrder(T value);
    public:
        // constructor
        GeneralTree(T value);
        // insert a child to a parent node
        void insert(T parent, T value);
        // traversing
        void preOrder();
        void inOrder();
        void postOrder();
        // searching 
        void findData(int choice, T value);
};

template <typename T>
GeneralTree<T>::GeneralTree(T value){
    key = value;
    firstChild = nullptr;
    nextSibling = nullptr;
}

template <typename T>
void GeneralTree<T>::insert(T parent, T value){
    // if current node is parent
    if(key == parent){
        // add first child
        if(firstChild == nullptr){
            firstChild = new GeneralTree<T>(value);
        } else {
            // to last child
            GeneralTree<T>* current = firstChild;

            while(current->nextSibling != nullptr){
                current = current->nextSibling;
            }
            // add new child at the end
            current->nextSibling = new GeneralTree<T>(value);
        }
        return;
    }
    // find child, sibling
    if(firstChild != nullptr){
        firstChild->insert(parent, value);
    }

    if(nextSibling != nullptr){
        nextSibling->insert(parent, value);
    }
}
// TRAVERSAL
// root, first, siblings
template <typename T>
void GeneralTree<T>::preOrder(){
    std::cout << key << " ";
    // first child
    if(firstChild != nullptr){
        firstChild->preOrder();
    }
    // next sibling
    if(nextSibling != nullptr){
        nextSibling->preOrder();
    }
}
// first, root, sibling
template <typename T>
void GeneralTree<T>::inOrder(){
    // first child subtree
    if(firstChild != nullptr){
        firstChild->inOrder();
        // root after first child
        std::cout << key << " ";
        // process remaining children
        GeneralTree<T>* current = firstChild->nextSibling;

        while(current != nullptr){
            current->inOrder();
            current = current->nextSibling;
        }
    } else {
        // leaf node
        std::cout << key << " ";
    }
}
// first, sibling, root
template <typename T>
void GeneralTree<T>::postOrder(){
    // first child
    if(firstChild != nullptr){
        firstChild->postOrder();
    }
    std::cout << key << " ";
    // next sibling
    if(nextSibling != nullptr){
        nextSibling->postOrder();
    }
}
// Searching helper functions
template <typename T>
bool GeneralTree<T>::findPreOrder(T value){
    // check current node
    if(key == value){
        return true;
    }
    // first child
    if(firstChild != nullptr){
        if(firstChild->findPreOrder(value)){
            return true;
        }
    }
    // next sibling
    if(nextSibling != nullptr){
        if(nextSibling->findPreOrder(value)){
            return true;
        }
    }
    return false;
}

template <typename T>
bool GeneralTree<T>::findInOrder(T value){
    // first child
    if(firstChild != nullptr){
        if(firstChild->findInOrder(value)){
            return true;
        }
    }
    // check current node
    if(key == value){
        return true;
    }
    // next sibling
    if(nextSibling != nullptr){
        if(nextSibling->findInOrder(value)){
            return true;
        }
    }
    return false;
}

template <typename T>
bool GeneralTree<T>::findPostOrder(T value){
    // first child
    if(firstChild != nullptr){
        if(firstChild->findPostOrder(value)){
            return true;
        }
    }
    // next sibling
    if(nextSibling != nullptr){
        if(nextSibling->findPostOrder(value)){
            return true;
        }
    }
    // check current node
    if(key == value){
        return true;
    }
    return false;
}
// Primary searching function
template <typename T>
void GeneralTree<T>::findData(int choice, T value){
    bool found = false;
    // choose a method
    switch(choice){
        case 1: found = findPreOrder(value); break;
        case 2: found = findInOrder(value); break;
        case 3: found = findPostOrder(value); break;
        default: break;
    }
    // display result
    if(found){
        std::cout << value << " was found! (Using method #" << choice << ")\n";
    } else {
        std::cout << value << " was NOT found! (Using method #" << choice << ")\n";
    }
}
#endif