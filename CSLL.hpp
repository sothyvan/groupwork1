#include <iostream>
#include <chrono>
#ifndef CSLL_HPP
#define CSLL_HPP

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
        int counter;
    public:
        //Constructor
        cSLL(){
            head = nullptr;
            tail = nullptr;
            counter = 0;
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
            counter = 0;
        }
        void insertBack(int value) {
            circularNode* newNode = new circularNode(value);
            if (head == nullptr) {
                // If the list is empty, newNode points to itself
                head = newNode;
                tail = newNode;
                newNode->next = newNode;
            } else {
                // Insert after tail and update tail pointer
                tail->next = newNode;
                newNode->next = head;
                tail = newNode;
            }
            counter++;
        }
        void traverse(int n) {
            circularNode* cur = head;
            for (int i = 0; i < n; ++i) {
                cur = cur->next;
            }
        }
        void deleteWithPred(circularNode* pred) {
            circularNode* target = pred->next;
            pred->next = target->next;
            delete target;
            counter--;
        }
        void deleteWithoutPred(circularNode* node) {
            circularNode* pred = head;
            while (pred->next != node){
                pred = pred->next;
            }
            pred->next = node->next;
            delete node;
            counter--;
        }
    };

void cSLL_observe(cSLL* obj, void (cSLL::*method)(), string msg){
    auto t0 = clk::now();

    (obj->*method)(); // perform operation

    auto t1 = clk::now();

    auto duration = chrono::duration_cast<chrono::nanoseconds>(t1 - t0);
    cout<<msg <<": "<<duration.count() <<" nanosecond(s)" <<endl;
}
#endif