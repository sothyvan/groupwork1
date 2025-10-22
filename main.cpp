#include <iostream>
#include "CDLL.hpp"
#include "CSLL.hpp"
#include "DLL.hpp"
#include "SLL.hpp"
#include "SLLhead.hpp"


using namespace std;

int main(){
    cDLL list;
    cDLL_observe(&list, &cDLL::fillList, "fillList execution time");
    return 0;
}