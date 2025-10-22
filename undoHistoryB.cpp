#include <iostream>

using namespace std;

class DynamicArray{
    private:
        int* data;
        int capacity;
        int size;

        void grow(){
            //growing its capacity by doubling when full
            int new_capacity;
            if (capacity == 0){
                new_capacity = 1;
            } else {
                new_capacity = capacity * 2;
            }
            int *newData = new int{new_capacity};

            //Copy old data to new array
            for(int i = 0; i < size; i++){
                newData[i] = data[i];
            }

            //Free old array and updata pointers
            delete[] data;
            data = newData;
            capacity = new_capacity;
        }
    
    public:
        //Constructor
        DynamicArray(){
            data = nullptr;
            capacity = 0;
            size = 0;
        }
        //Destructtor
        ~DynamicArray(){
            delete[] data;
        }

        void push(int value){
            //If the array is fulled
            if (size == capacity){
                grow();
            }
            data[size] = value;
            size++;
        }

        void pop(){
            if(size == 0){
                cout << "Empty!\n";
                return;
            }
            size--;
            //The data in the array isn't deleted, but the stack will ignore it because size tells the stack how many elements are valid
        }

        int size(){
            return size;
        }
};

int main(){
    
    return 0;
}