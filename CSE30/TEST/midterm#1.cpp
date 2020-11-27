#include <iostream>

int* intOnHeap (int value) {
    int* result = new int(value - 4);

    return result;
}

int main (int argc, const char * argv[]) {
    int* p = intOnHeap(37);

    std::cout << *p <<std::endl;

    delete[] p;

    return 0;
}