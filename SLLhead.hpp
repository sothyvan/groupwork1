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
        //method
         // Insert at front
        void push_front(int val){
            Node *newNode = new Node(val);
            newNode->next = head;
            head = newNode;
            counter++;
        }
        
        // Insert at back
        void push_back(int val){
            Node *newNode = new Node(val);
            
            if (head == nullptr) {
                head = newNode;
            } else {
                Node* current = head;
                while (current->next != nullptr) {
                    current = current->next;
                }
                current->next = newNode;
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
            delete temp;
            counter--;
        }
        
        // Delete from back
        void pop_back(){
            if (head == nullptr) {
                cout << "List is empty! Cannot pop_back." << endl;
                return;
            }
            
            if (head->next == nullptr) {
                delete head;
                head = nullptr;
            } else {
                Node* current = head;
                while (current->next->next != nullptr) {
                    current = current->next;
                }
                delete current->next;
                current->next = nullptr;
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
        }
};

void SLLh_observe(SLLh* obj, void (SLLh::*method)(), string msg){
    auto t0 = clk::now();

    (obj->*method)(); // perform operation

    auto t1 = clk::now();

    auto duration = chrono::duration_cast<chrono::nanoseconds>(t1 - t0);
    cout<<msg <<": "<<duration.count() <<" nanosecond(s)" <<endl;
}