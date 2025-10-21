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

class SLLh{
    private:
        Node *head;
        int counter;
    
    public:
        //Constructor
        SLLh(){
            head = nullptr;
            counter = 0;
        }
        // Destructor
        ~SLLh() {
            while (head != nullptr) {
                Node* temp = head;
                head = head->next;
                delete temp;
            }
        }
};

void SLLh_observe(SLLh* obj, void (SLLh::*method)(), string msg){
    auto t0 = clk::now();

    (obj->*method)(); // perform operation

    auto t1 = clk::now();

    auto duration = chrono::duration_cast<chrono::nanoseconds>(t1 - t0);
    cout<<msg <<": "<<duration.count() <<" nanosecond(s)" <<endl;
}