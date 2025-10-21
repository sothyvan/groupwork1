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

class LinkedlistUndoHistory{
    private:
        Node *head;
        int counter;
    public:
        //Constructor
        LinkedlistUndoHistory(){
            head = nullptr;
            counter = 0;
        }
        //Destructor
        ~LinkedlistUndoHistory(){
            while(head != nullptr){
                Node *temp = head;
                head = head->next;
                delete temp;
            }
        }

        void addAction(int value){
            Node* new_node = new Node{value};
            new_node->next = head;
            head = new_node;
            counter++;
        }

        void undo(){
            if(head == nullptr){
                cout << "Empty!\n";
                return;
            }

            Node *temp = head;
            head = head->next;
            delete temp;
            counter--;
        }

        int size(){
            return counter;
        }
};

void LinkedlistUndoHistory_observe(LinkedlistUndoHistory* obj, void (LinkedlistUndoHistory::*method)(), string msg){
    auto t0 = clk::now();

    (obj->*method)(); // perform operation

    auto t1 = clk::now();

    auto duration = chrono::duration_cast<chrono::nanoseconds>(t1 - t0);
    cout<<msg <<": "<<duration.count() <<" nanosecond(s)" <<endl;
}

int main(){
    
    return 0;
}