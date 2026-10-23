#ifndef PRINTERARR_H
#define PRINTERARR_H
#include <iostream>
#include <string>
// job class
class Job{
    public:
        int id;
        std::string user;
        int pages;
};
// printer class 
class Printer{
    private:
        // variables
        Job* q_array;
        size_t q_capacity;
        size_t q_size;
        int q_front;
        int q_back;

    public:
        // constructor
        Printer(size_t capacity = 10){
            q_capacity = capacity;
            q_size = 0;
            q_front = 0;
            q_back = -1;
            q_array = new Job[q_capacity];
        }
        // destructor
        ~Printer(){
            delete[] q_array;
        }
        // checks
        bool Empty(){
            return q_size == 0;
        }

        bool Full(){
            return q_size == q_capacity;
        }
        // job operations
        void AddJob(Job newJob){
            if(Full()){
                std::cout << "Printer queue is full\n";
                return;
            }
            // using circular method
            q_back = (q_back + 1) % q_capacity;
            q_array[q_back] = newJob;
            q_size++;

            std::cout << "Print job added\n";
        }

        Job RemoveJob(){
            if(Empty()){
                std::cout << "No print jobs\n";
                return Job();
            }
            // using circular method
            Job temp = q_array[q_front];
            q_front = (q_front + 1) % q_capacity;
            q_size--;
            // clear 
            if(Empty()){
                Clear();
            }

            return temp;
        }

        void ProcessJobs(){
            if(Empty()){
                std::cout << "There are no print jobs to process\n";
                return;
            }
            // process all jobs
            while(!Empty()){
                Job temp = RemoveJob();
                std::cout << "Printing Job ID: " << temp.id << "   User: " << temp.user << "   Pages: " << temp.pages << std::endl;
            }
            // message
            std::cout << "Print Jobs DONE\n";
        }

        void ShowJobs(){
            if(Empty()){
                std::cout << "There are no pending print jobs\n";
                return;
            }
            int index = q_front;
            std::cout << "\nPending Print Jobs\n";
            // display jobs
            for(size_t i = 0; i < q_size; i++){
                std::cout << "Job ID: " << q_array[index].id << "   User: " << q_array[index].user << "   Pages: " << q_array[index].pages << std::endl;

                index = (index + 1) % q_capacity;
            }
        }
        // clear, reset
        void Clear(){
            q_size = 0;
            q_front = 0;
            q_back = -1;
        }
};
#endif