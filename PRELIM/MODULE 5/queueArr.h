#ifndef QUEUEARR_H
#define QUEUEARR_H
#include <iostream>
// Array-based circular queue
template <typename T>
class queueArr{
    private:
        // pointer to dynamically allocate an array
        T* q_array;
        // maximum 
        size_t q_capacity;
        // current number of elements in the queue
        size_t q_size;
        // index of the front element
        int q_front;
        // index of the back element
        int q_back;
    public:
        // constructor 
        queueArr(size_t capacity = 10);

        // copy constructor
        queueArr(const queueArr& other);

        // copy assignment operator
        queueArr& operator = (const queueArr& other);

        // destructor
        ~queueArr();

        // queue operations:
        bool Empty();
        bool Full();
        size_t Size();
        void Clear();
        T Front();
        T Back();
        void Enqueue(T value);
        T Dequeue();

};

// constructor
template <typename T>
queueArr<T>::queueArr(size_t capacity){
    // capacity, q_size, q_front, q_back and q_array
    q_capacity = capacity;
    q_size = 0;
    q_front = 0;
    q_back = -1;
    q_array = new T[q_capacity];

}

// *copy constructor
template <typename T>
queueArr<T>::queueArr(const queueArr& other){
    q_capacity = other.q_capacity;
    q_size = other.q_size;
    q_front = other.q_front;
    q_back = other.q_back;

    q_array = new T[q_capacity];

    for(size_t i = 0; i < q_capacity; i++){
        q_array[i] = other.q_array[i];
    }
}

// copy assignment operator
template <typename T>
queueArr<T>& queueArr<T>::operator=(const queueArr& other){
    if(this != &other){
        delete[] q_array;

        q_capacity = other.q_capacity;
        q_size = other.q_size;
        q_front = other.q_front;
        q_back = other.q_back;

        q_array = new T[q_capacity];

        for(size_t i = 0; i < q_capacity; i++){
            q_array[i] = other.q_array[i];
        }
    }

    return *this;
}

// destructor
template <typename T>
queueArr<T>::~queueArr(){
    delete[] q_array;
}

// Empty()
template <typename T>
bool queueArr<T>::Empty(){
    // check if the size is 0
    return q_size == 0;
}

// Full()
template <typename T>
bool queueArr<T>::Full(){
    // check if the q_size has reached the maximum capacity
    return q_size == q_capacity;
}

// find the current size at the array
template <typename T>
size_t queueArr<T>::Size(){
    return q_size;
}

// clear
template <typename T>
T queueArr<T>::Front(){
    // check if the queue is empty
    if(Empty()){
        std::cout << "the queue is empty\n";
        return T(); 
    }
    // return the front
    return q_array[q_front];
}

// back
template <typename T>
T queueArr<T>::Back(){
    // check if the queue is empty
    if(Empty()){
        std::cout << "the queue is empty\n";
        return T(); 
    }
    // return the back
    return q_array[q_back];
}

// clear
template <typename T>
void queueArr<T>::Clear(){
    // reset the q_size, q_front, q_back
    q_size = 0;
    q_front = 0;
    q_back = -1;
}

template <typename T>
void queueArr<T>::Enqueue(T value){
    // check if the queue is full
    if(Full()){
        std::cout << "Queue is full\n";
        return;
    }

    // move q_back circularly 
    q_back = (q_back + 1) % q_capacity;

    // store the value to the back
    q_array[q_back] = value;

    // increment the q_size
    q_size++;
}

// T Dequeue()
template <typename T>
T queueArr<T>::Dequeue(){
    // check if empty
    if(Empty()){
        std::cout << "Queue is empty\n";
        return T();
    }

    // create a temp variable to store current front
    T temp = q_array[q_front];

    // move q_front circularly 
    q_front = (q_front + 1) % q_capacity;

    // decrement q_size
    q_size--;

    // reset indexes if queue becomes empty
    if(Empty()) Clear();

    // return temp variable 
    return temp;
}

#endif