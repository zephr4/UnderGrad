#include <iostream>
//#include <cmath>

void Max_Heapify(int* list, int heap_size, int parent) {
    
    int leftChild = 2 * parent;
    int rightChild = 2 * parent + 1;
    int largest = parent;

    if (leftChild < heap_size && list[leftChild] > list[largest])
        largest = leftChild;
    
    if (rightChild < heap_size && list[rightChild] > list[largest])
        largest = rightChild;
    
    int temp;

    if (largest != parent) {

        temp = list[parent];
        list[parent] = list[largest];
        list[largest] = temp;

        Max_Heapify(list, heap_size, largest);
    }
    
}

void Build_Max_Heap(int* list, int heap_size) { 

    int i;
    for (i = heap_size - 1; i >= 0; i--) {
        
        Max_Heapify(list, heap_size, i);
    }
}

void heapSort(int* list, int listSize) {

    Build_Max_Heap(list, listSize);

    int i;
    int temp;
    //int heapSize = listSize;

    for (i = listSize - 1; i >= 0; i--) {

        temp = list[0];
        list[0] = list[i];
        list[i] = temp;
        //heapSize = heapSize - 1;

        Max_Heapify(list, i, 0 );
    }

    for (i = 0; i < listSize; i++) {
        std::cout << list[i] << ";";
    } 

}

int main(int argc,char **argv) {

     // Intializations of starting variables
    int *list;
    int listSize = 0;

    // User inputs the size of the List and new list is formed
    std::cin >> listSize;
    list = new int[listSize];

    // The list recieves user inputs as values
    int i;
    for(i = 0; i < listSize; i++) {

        std::cin >> list[i];
    }

    heapSort(list, listSize);

    //for (i = 0; i < listSize; i++) 
    //    std::cout << list[i] << ";";
        
    return 0;

}