#include <iostream>
#include <chrono>

using namespace std;
using clk = std::chrono::high_resolution_clock;

class Node{
    public:
        int data;
        Node* next;

        //Constructor
        Node(int value){
            data = value;
            next = nullptr;
        }
};

class SLL{
    private:
        Node *head, *tail;
        int counter;
    
    public:
        //Constructor
        SLL(){
            head = nullptr;
            tail = nullptr;
            counter = 0;
        }
        // Destructor
        ~SLL() {
            while (head != nullptr) {
                Node* temp = head;
                head = head->next;
                delete temp;
            }
        }
};

void SLL_observe(SLL* obj, void (SLL::*method)(), string msg){
    auto t0 = clk::now();

    (obj->*method)(); // perform operation

    auto t1 = clk::now();

    auto duration = chrono::duration_cast<chrono::nanoseconds>(t1 - t0);
    cout<<msg <<": "<<duration.count() <<" nanosecond(s)" <<endl;
}