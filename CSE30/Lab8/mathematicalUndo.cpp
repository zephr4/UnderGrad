#include <iostream>
#include "OpStack.h"

int main(int argc, const char * argv[]) {

    Stack* myStack = new Stack(); 

    char b;
    long value;
    long total = 0;

    do {
        std::cin >> b;

        if (b == 'z') {
            if (!myStack->isEmpty()) {
                Link* temp = myStack->pop();
                if (temp->op == 'a') {
                    total = total - temp->data;
                }
                else if (temp->op == 's') {
                    total = total + temp->data;
                }
            }
            else {
                std::cout << "Nothing to undo..." << std::endl;
            }
        }

        else if (b != 'q') {
            std::cin >> value;
            myStack->push(value, b);
            if (b == 'a') {
                total = total + value;
            }

            else if (b == 's') {
                total = total - value;
            }
        }
        else {
            break;
        }
         std::cout << "Total: " << total << std::endl;
    }

    while (b != 'q');

    return 0;
}