#include <iostream>
#include <chrono>

using namespace std;
using clk = std::chrono::high_resolution_clock;

class doublyNode{
    public:
        int data;
        doublyNode *next;
        doublyNode *prev;

    //Constructor
    doublyNode(int value){
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

class DLL{
    private:
        doublyNode *head;
        doublyNode *tail;
        int counter;

    public:
        //Constructor
        DLL(){
            head = nullptr;
            tail = nullptr;
            counter = 0;
        }
        //Destructor
        ~DLL(){
            doublyNode *cur = head;
            
            while(cur != nullptr){
                doublyNode *temp = cur;
                cur = cur->next;
                delete temp;
            }
            head = nullptr;
            tail = nullptr;
            counter = 0;
        }

        //recent items (DLL)
        void insertItemFront(int value){
            doublyNode *new_node = new doublyNode{value};
            if (head != nullptr){
                new_node->next = head;
                head->prev = new_node;
            } else {
                tail = new_node;
            }
            head = new_node;
            counter++;
        }
        void removeItemFront(){
            if (head == nullptr){
                cout << "Empty!";
                return;
            }
            doublyNode *temp = head;
            head = head->next;
            if (head != nullptr){
                head->prev = nullptr;
            } else {
                tail = nullptr;
            }
            delete temp;
            counter--;
        }

        void eraseNode(doublyNode* node){
            if(node == nullptr){
                return;     
            }
            if(node == head){
                head = node->next;
                if(head != nullptr){
                    head->prev = nullptr;
                } else {
                    tail = nullptr;
                }
            }
            else if(node == tail){
                tail = node->prev;
                if(tail != nullptr){
                    tail->next = nullptr;;
                } else {
                    head = nullptr;
                }
            }
            else{
                node->prev->next = node->next;
                node->next->prev = node->prev;
            }
            delete node;
        }
};

void DLL_observe(DLL* obj, void (DLL::*method)(), string msg){
    auto t0 = clk::now();

    (obj->*method)(); // perform operation

    auto t1 = clk::now();

    auto duration = chrono::duration_cast<chrono::nanoseconds>(t1 - t0);
    cout<<msg <<": "<<duration.count() <<" nanosecond(s)" <<endl;
}