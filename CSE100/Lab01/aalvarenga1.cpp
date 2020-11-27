#include <iostream>

int main(int argc,char **argv) {

    // Intializations of starting variables
    int* list;
    int listSize = 0;
    int input = 0;

    // User inputs the size of the List and new list is formed
    std::cin >> listSize;
    list = new int[listSize];

    // The list recieves user inputs as values
    int i;
    for(i = 0; i < listSize; i++) {

        std::cin >> list[i];
    }

    // Insertion Sort Algorithm is implemented
    int key;
    int j;
    for (i = 1; i < listSize; i++) {

        // The initial value, Key, is stored 
        key = list[i];
        j = i - 1;

        // Comparisons are performed to check if value is in the right position
        while (j >= 0 && list[j] > key) {

            list[j + 1] = list[j];
            j = j - 1;
        }

        // The List updated
        list[j + 1] = key;

        // Only the sorted portion of the list is printed 
        int k = 0;
        while (k <= i) {
            std::cout << list[k] << ";";
            k++;
        }
        std::cout << "" << std::endl;
        
    }
    
    return 0;
}