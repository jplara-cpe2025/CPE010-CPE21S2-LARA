#ifndef SEARCHINGALGO_H
#define SEARCHINGALGO_H

#include "node.h"
#include <iostream>

template <typename T>
void linearSearchAR(int size, T dataFind, T array[]){
    int comparisons = 0;
    //for loop implementation
    for(int j = 0; j < size ; j++){
        comparisons++;
        if(dataFind == array[j]){
            std::cout<<"Searching is successful\n";
            std::cout << "Number of comparisons: " << comparisons << "\n";
            return;
        }
    }
    std::cout<<"Searching is unsuccessful\n";
    std::cout << "Number of comparisons: " << comparisons << "\n";
}

/*
LINEAR SEARCH ALGORITHM
head 
data to find
N -> Boundary of the list
Item -> Searching number
Data -> Linear array
Step 1: I := 0
Step 2: Repeat while I <= n
  If (item = data[i])
  Print "Searching is successful"
  Exit
Else
  Print "Searching is Unsuccessful"
Exit
*/

template <typename T>
void linearSearchLL(Node<T> *nodes, T dataFind){
    int comparisons = 0;
    // repeat the loop until the current node is not NULL
    while(nodes != nullptr){
        comparisons++;
        // check if the item = to the current node data
        if(nodes->data == dataFind){
            std::cout << "The data: " << nodes->data << " was found successfully.\n";
            std::cout << "Number of comparisons: " << comparisons << "\n";
            return;
        }
        // move on the next node
        nodes = nodes->next;

    }
    // display unsuccessful
    std::cout << "Searching is unsuccessful.\n";

    std::cout << "Number of comparisons: " << comparisons << "\n";
}

/*
BINARY SEARCH ALGORITHM
Step 1: low :=0, up=n-1
Step 2: Repeat while low <= up
    mid = int(low+up)/2
    if(no=arr[mid])
    print "Search element is found!"
    exit
    else
    if(no < arr[mid]) then
        up = mid-1
else
    low = mid+1
Step 3: Print "Search element is not found"
Step 4: Exi

*/
template <typename T>
void binarySearchArr(T data[], int arrSize, T dataFind){
    int low = 0, high = arrSize - 1, middle;
    while(low<= high){
        middle = (int)((low+high)/2);
        if(dataFind == data[middle]){
            std::cout<<"the data was found\n";
            return;
        }
        else if( dataFind < data[middle]){
            high = middle -1;
        }
        else{
            low = middle+1;
        }
    }

    std::cout<<"the data was not found\n";
}

// Modified binary array search for display
template <typename T>
void binarySearchArrDisplay(T data[], int arrSize, T dataFind){
    int low = 0, high = arrSize - 1, middle, iteration = 1;
    while(low<= high){
        middle = (low + high)/2;
        std::cout << "Iteration " << iteration << "\n";
        std::cout << "Element: " << data[middle] << "\n";
        std::cout << "Middle: " << middle << "\n";
        std::cout << "Low: " << low << "\n";
        std::cout << "High: " << high << "\n";

        if(dataFind == data[middle]){
            std::cout << "Data was found\n";
            return;
        }
        else if(dataFind < data[middle]){
            high = middle - 1;
        }
        else{
            low = middle + 1;
        }
        iteration++;
        std::cout << "\n";
    }
    std::cout << "Data was not found\n";
}

//RECURSIVE
template <typename T>
void binarySearchRecursive(T data[], int low, int high, T dataFind){
    if(low > high){
        std::cout << "Data was not found\n";
        return;
    }

    int middle = (low + high) / 2;

    std::cout << "Low: " << low << "\n";
    std::cout << "High: " << high << "\n";
    std::cout << "Middle: " << middle << "\n";
    std::cout << "Element: " << data[middle] << "\n\n";

    if(data[middle] == dataFind){
        std::cout << "Data was found\n";
        return;
    }
    else if(dataFind < data[middle]){
        binarySearchRecursive(data, low, middle - 1, dataFind);
    }
    else{
        binarySearchRecursive(data, middle + 1, high, dataFind);
    }
}

// middle function getter:
template <typename T>
Node<T>* getMiddle(Node<T> *start, Node<T>* last){
    Node<T>* slow = start;
    Node<T>* fast = start;

    // continue until fast reaches the end or last node of the current search range

    while(fast != last && fast->next != last){

        // move slow one step
        slow = slow -> next;
        // move fast two steps
        fast = fast->next->next;
    }
    return slow; 
}

template <typename T>
void binarySearchLL(Node<T>* start, T dataFind){
    //step 1: set start to the head of the list and set last to null
    Node<T>* last = nullptr;

    while(start != last){
        //Middle element is calculated using the two pointers approach discussed above.
        Node<T> *middle = getMiddle(start, last);

        //If the middle element is same as the key to be searched, we return it.
        if(middle->data == dataFind){
            std::cout<< "searching is Successful\n";
            return;
        }
        //Else if middle element is greater than the key to be searched, we have to search is the
        //right side of the singly linked list. So, we set start pointer to the next of middle
        //element
        else if(middle->data > dataFind){
            last = middle;
        }
        //Else if middle element is less than the key to be searched, we have to search is the left
        //side of the singly linked list. So, we set last pointer to the middle element.
        else{
            start = middle->next;
        }
    }

    std::cout<<"Searching is unsuccessful\n";
}
#endif