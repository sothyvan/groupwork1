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
        } void push_front(int val){
            Node *newNode = new Node(val);
            
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
            Node *newNode = new Node(val);
            
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
            
            Node* temp = head;
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
            
            Node* temp = tail;
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
            
            Node* current = head;
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
            
            Node* current = tail;
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
        //Destructor
        ~DLL(){
            doublyNode *cur = head;
            
            while(cur != nullptr){
                doublyNode *temp = head;
                cur = head->next;
                delete temp;
            }
            head = nullptr;
            tail = nullptr;
        }
};

void DLL_observe(DLL* obj, void (DLL::*method)(), string msg){
    auto t0 = clk::now();

    (obj->*method)(); // perform operation

    auto t1 = clk::now();

    auto duration = chrono::duration_cast<chrono::nanoseconds>(t1 - t0);
    cout<<msg <<": "<<duration.count() <<" nanosecond(s)" <<endl;
}