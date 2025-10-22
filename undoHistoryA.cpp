#include <iostream>

using namespace std;

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

int main(){
    
    return 0;
}