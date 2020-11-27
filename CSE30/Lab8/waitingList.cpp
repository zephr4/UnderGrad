#include <iostream>
#include "StringQueue.h"

int main(int argc, const char * argv[]) {

    Queue myQueue;

    char b;
    std::string name;

    do {
        std::cin >> b;

        if (b == 'a') {
            std::cin >> name;
            myQueue.push(name);
            std::cout << name << " arrived" << std::endl;
        }
        else if (b == 's') {
            std::cout << "Now serving: " << myQueue.pop() << std::endl;
        }
        else if (b == 'n') {
            if (!myQueue.isEmpty()) {
                std::cout << "Next in line: " << myQueue.peek() << std::endl;
            }
            else {
                std::cout << "The waiting list is empty" << std::endl;
            }
        }
    }

    while (b != 'q');
    
    std:: cout << "Come back tomorrow: " << std::endl;
    
    while (!myQueue.isEmpty()) {
        std::cout << myQueue.pop() << std::endl;
    } 

    std::cout << "Closing up now." << std::endl;

    return 0;
}