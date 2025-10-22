#include <iostream>
#include <chrono>
#ifndef CDLL_HPP
#define CDLL_HPP

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
                circularDNode *temp = cur;
                cur = cur->next;
                delete temp;
            }
            head = nullptr;
            tail = nullptr;
        }
        void insertEnd(int value) {
            circularDNode* newNode = new circularDNode(value);
            if (!head) {
                head = newNode;
                tail = newNode;
                head->next = head;
                head->prev = head;
                return;
            }
            newNode->prev = tail;
            newNode->next = head;
            tail->next = newNode;
            head->prev = newNode;
            tail = newNode;
        }
        void fillList() {
            for (int i = 1; i <= 100; i++) {
                insertEnd(i);
            }
        }
};

void cDLL_observe(cDLL* obj, void (cDLL::*method)(), string msg){
    auto t0 = clk::now();

    (obj->*method)(); // perform operation

    auto t1 = clk::now();

    auto duration = chrono::duration_cast<chrono::nanoseconds>(t1 - t0);
    cout<<msg <<": "<<duration.count() <<" nanosecond(s)" <<endl;
}
#endif  