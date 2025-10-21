#include <iostream>
#include <chrono>

using namespace std;
using clk = std::chrono::high_resolution_clock;


class circularNode{
    public:
        int data;
        circularNode *next;

    //Constructor
    circularNode(int value){
        data = value;
        next = nullptr;
    }
};

class cSLL{
    private:
        circularNode *head;
        circularNode *tail;
    public:
        //Constructor
        cSLL(){
            head = nullptr;
            tail = nullptr;
        }
        //Destructor
        ~cSLL(){
            circularNode *cur = head;
            tail->next = nullptr;

            while (cur != nullptr){
                circularNode *temp = cur;
                cur = cur->next;
                delete temp;
            }
            head = nullptr;
            tail = nullptr;
        }
};

void cSLL_observe(cSLL* obj, void (cSLL::*method)(), string msg){
    auto t0 = clk::now();

    (obj->*method)(); // perform operation

    auto t1 = clk::now();

    auto duration = chrono::duration_cast<chrono::nanoseconds>(t1 - t0);
    cout<<msg <<": "<<duration.count() <<" nanosecond(s)" <<endl;
}
