#include <iostream>
#include "searchingAlgo.h"
#include "node.h"

int main(){
    int newArr[10] = {3, 5, 6, 8, 11, 12, 14, 15, 17, 18};

    std::cout << "BINARY SEARCH\n";
    std::cout << "Searching for 8\n\n";

    binarySearchArrDisplay(newArr, 10, 8);
    return 0;
}