#include <iostream>
#include <cstdlib>

//Followed the Hungarian folk dance, https://www.youtube.com/watch?v=ywWBy6J5gz8, as reference
//Used, http://www.cplusplus.com/reference/cstdlib/rand/, to understand how generate random numbers in a range
//Used, https://www.geeksforgeeks.org/quicksort-using-random-pivoting/, as a reference
int randomized_partition(int* list, int start, int end) {

    //Generates a pivot at random index
    srand(time(NULL)); 
    int randIndex = start + rand() % (end - start);

    //Swap the value at the random index with the value of the last index of the list
    int temp = list[end];
    list[end] = list[randIndex];
    list[randIndex] = temp; 

    //set the value of the randPivot equal to the value at the end
    int randPivot = list[end];
    //Index of where randPivot will be inserted
    int index = start - 1;

    for (int j = start; j < end; j++) {

        //if the value at the current j-index is <= the random pivot, increment i and swap j and i
        if (list[j] <= randPivot) {
            index++;
            temp = list[j];
            list[j] = list[index];
            list[index] = temp;
        }
    }
    //swap the end with (i + 1)
    temp = list[end];
    list[end] = list[index + 1];
    list[index + 1] = temp;

    //Returns index of the randPivot, to correctly partition the list recursively
    return (index + 1);
}

void randomized_quicksort(int* list, int start, int end) {

    if (start < end) {

        int randPivot = randomized_partition(list, start, end);
        randomized_quicksort(list, start, randPivot - 1);
        randomized_quicksort(list, randPivot + 1, end);
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

    randomized_quicksort(list, 0, listSize - 1);
    
    for (i = 0; i < listSize; i++) {
        std::cout << list[i] << ";";
    }     

    return 0;
}