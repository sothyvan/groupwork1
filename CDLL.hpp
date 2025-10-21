#include <iostream>
#include <chrono>

using namespace std;
using clk = std::chrono::high_resolution_clock;

class circularDNode{
    public:
        int data;
        circularDNode *next;
        circularDNode *prev;

    //Constructor
        circularDNode(int value){
            data = value;
            next = nullptr;
            prev = nullptr;
        }
};

class cDLL{
    private:
        circularDNode *head;
        circularDNode *tail;

    public:
        //Constructor
        cDLL(){
            head = nullptr;
            tail = nullptr;
        }
        //Destructor
        ~cDLL(){
            circularDNode *cur = head;

            tail->next = nullptr;
            head->prev = nullptr;
            
            while(cur != nullptr){
                circularDNode *temp = head;
                cur = head->next;
                delete temp;
            }
            head = nullptr;
            tail = nullptr;
        }
};

void cDLL_observe(cDLL* obj, void (cDLL::*method)(), string msg){
    auto t0 = clk::now();

    (obj->*method)(); // perform operation

    auto t1 = clk::now();

    auto duration = chrono::duration_cast<chrono::nanoseconds>(t1 - t0);
    cout<<msg <<": "<<duration.count() <<" nanosecond(s)" <<endl;
} 