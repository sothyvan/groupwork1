#include <iostream>
#include <chrono>
#ifndef SLL_HPP
#define SLL_HPP

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
            counter = 0;
        }
        void traverse(int n) {
            Node* cur = head;
            for (int i = 0; i < n; ++i) {
                if (cur == nullptr){
                    cur = head; // manual reset
                }
                cur = cur->next;
            }
        }
        //method
         // Insert at front
        void push_front(int val){
            Node *newNode = new Node(val);
            
            if (head == nullptr) {
                // First node in list
                head = tail = newNode;
            } else {
                newNode->next = head;
                head = newNode;
            }
            counter++;
        }
        
        // Insert at back
        void push_back(int val){
            Node *newNode = new Node(val);
            
            if (tail == nullptr) {
                // First node in list
                head = tail = newNode;
            } else {
                tail->next = newNode;
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
            
            Node* temp = head;
            head = head->next;
            
            if (head == nullptr) {
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
            
            if (head == tail) {
                // Only one node in list
                delete head;
                head = tail = nullptr;
            } else {
                // Find second last node
                Node* current = head;
                while (current->next != tail) {
                    current = current->next;
                }
                
                delete tail;
                tail = current;
                tail->next = nullptr;
            }
            counter--;
        }
        
        // Display the list
        void display() {
            if (head == nullptr) {
                cout << "List is empty" << endl;
                return;
            }
            
            Node* current = head;
            while (current != nullptr) {
                cout << current->data;
                if (current->next != nullptr) {
                    cout << " -> ";
                }
                current = current->next;
            }
            cout << " -> nullptr" << endl;
            
            cout << "Head: " << (head ? head->data : -1) << ", Tail: " << (tail ? tail->data : -1) << endl;
        }

        //recent items (SLL)
        void insertItemFront(int value){
            Node* newNode = new Node{value};
            newNode->next = head;
            head = newNode;

            //if the list is empty
            if(tail == nullptr){
                tail = newNode;
            }
            counter++;
        }
        void removeItemFront(){
            if (head == nullptr){
                cout << "Empty!";
                return;
            }
            Node *cur = head;
            head = head->next;
            delete cur;
            counter--;
        }
};

void SLL_observe(SLL* obj, void (SLL::*method)(), string msg){
    auto t0 = clk::now();

    (obj->*method)(); // perform operation

    auto t1 = clk::now();

    auto duration = chrono::duration_cast<chrono::nanoseconds>(t1 - t0);
    cout<<msg <<": "<<duration.count() <<" nanosecond(s)" <<endl;
}
#endif