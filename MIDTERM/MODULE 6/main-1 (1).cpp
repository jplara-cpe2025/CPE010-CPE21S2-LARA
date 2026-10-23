#include <iostream>
#include <cstdlib> // for generating random integers 
#include <time.h> // will be used for our seeding function
#include "searchingAlgo.h"

const int max_size = 50;

int main() {
    /*
    int dataset[max_size];
    srand(time(0));
    for(int i = 0; i < max_size ; i++){
        dataset[i] = rand();
        std::cout<< dataset[i] << " ";
    }
    std::cout<<std::endl;

    std::cout<< "what number to find: ";
    int choice;

    std::cin >> choice;

    linearSearchAR(max_size, choice, dataset);
    */

    // CREATE A NODE FOR YOUR NAME
    // [J]->[i]->[M]->[L]->[O]->[R]->[D]->NULL
    
    // CREATE A NODE
    
    Node<char> *char1 = new_node('J');
    Node<char> *char2 = new_node('P');
    Node<char> *char3 = new_node('C');
    Node<char> *char4 = new_node('L');

    
    // CONNECT THE NODES
    char1->next = char2;
    char2->next = char3;
    char3->next = char4;

    
    linearSearchLL(char1, 'C');
    /*
    int newArr[10] = {1,2,3,4,5,6,7,8,9,10};
    for(int i = 0; i < max_size; i++){
        newArr[i] = i;
    }
    binarySearchArr(newArr, max_size, 100);
    */
    
    /*
    Node<char> *char1 = new_node('J');
    Node<char> *char2 = new_node('I');
    Node<char> *char3 = new_node('M');
    Node<char> *char4 = new_node('L');
    Node<char> *char5 = new_node('O');
    Node<char> *char6 = new_node('R');
    Node<char> *char7 = new_node('D');

    char1->next = char2;
    char2->next = char3;
    char3->next = char4;
    char4->next = char5;
    char5->next = char6;
    char6->next = char7;
    */
    /*
    Node<int> *int1 = new_node(10);
    Node<int> *int2 = new_node(11);
    Node<int> *int3 = new_node(12);
    Node<int> *int4 = new_node(13);
    Node<int> *int5 = new_node(14);
    Node<int> *int6 = new_node(15);
    Node<int> *int7 = new_node(16);

    int1->next = int2;
    int2->next = int3;
    int3->next = int4;
    int4->next = int5;
    int5->next = int6;
    int6->next = int7;


    binarySearchLL(int1, 16);
    */
}

