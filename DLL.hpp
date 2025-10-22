#include <iostream>
#include <chrono>
#ifndef DLL_HPP
#define DLL_HPP

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
        void push_front(int val){
            doublyNode *newNode = new doublyNode(val);
            
            if (head == nullptr) {
                // First node in list
                head = tail = newNode;
            } else {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
            counter++;
        }
        
        // Insert at back
        void push_back(int val){
            doublyNode *newNode = new doublyNode(val);
            
            if (tail == nullptr) {
                // First node in list
                head = tail = newNode;
            } else {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
            counter++;
        }
        
        // Delete from front
        void pop_front(){
            if (head == nullptr) {
                cout << "List is empty! Cannot pop_front." << endl;
                return;
            }
            
            doublyNode* temp = head;
            head = head->next;
            
            if (head != nullptr) {
                head->prev = nullptr;
            } else {
                // List became empty
                tail = nullptr;
            }
            
            delete temp;
            counter--;
        }
        
        // Delete from back
        void pop_back(){
            if (tail == nullptr) {
                cout << "List is empty! Cannot pop_back." << endl;
                return;
            }
            
            doublyNode* temp = tail;
            tail = tail->prev;
            
            if (tail != nullptr) {
                tail->next = nullptr;
            } else {
                // List became empty
                head = nullptr;
            }
            
            delete temp;
            counter--;
        }
        
        // Display the list from front to back
        void display_forward() {
            if (head == nullptr) {
                cout << "List is empty" << endl;
                return;
            }
            
            doublyNode* current = head;
            cout << "nullptr <- ";
            while (current != nullptr) {
                cout << current->data;
                if (current->next != nullptr) {
                    cout << " <-> ";
                }
                current = current->next;
            }
            cout << " -> nullptr" << endl;
            
            cout << "Head: " << (head ? head->data : -1) << ", Tail: " << (tail ? tail->data : -1) << endl;
        }
        
        // Display the list from back to front
        void display_backward() {
            if (tail == nullptr) {
                cout << "List is empty" << endl;
                return;
            }
            
            doublyNode* current = tail;
            cout << "nullptr <- ";
            while (current != nullptr) {
                cout << current->data;
                if (current->prev != nullptr) {
                    cout << " <-> ";
                }
                current = current->prev;
            }
            cout << " -> nullptr" << endl;
        }

};

void DLL_observe(DLL* obj, void (DLL::*method)(), string msg){
    auto t0 = clk::now();

    (obj->*method)(); // perform operation

    auto t1 = clk::now();

    auto duration = chrono::duration_cast<chrono::nanoseconds>(t1 - t0);
    cout<<msg <<": "<<duration.count() <<" nanosecond(s)" <<endl;
}
#endif