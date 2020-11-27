#include <iostream>

int* merge(int* arr, int start, int mid, int end){

    int leftLen = mid - start + 1;
    int rightLen = end - mid;

    int left[leftLen];
    int right[rightLen];
    
    int i;
    int j;
    
    for (i = 0; i < leftLen; i++)
        left[i] = arr[start + i];
    
    for (j = 0; j < rightLen; j++)
        right[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    int k = start;

    while (i < leftLen && j < rightLen) {

        if (left[i] < right[j]) {
            arr[k] = left[i];
            i++;
        }

        else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < leftLen) {

        arr[k] = left[i];
        i++;
        k++;
    }

    while (i < rightLen) {

        arr[k] = right[j];
        j++;
        k++;
    }

    return arr;

}

int* mergeSort(int* A, int start, int end) {

    //int* L;
    //int* R;
    int* sorted;

    //if (start >= end)
    //    return A;
    
    if (start < end) {
        int mid = (start + end) / 2;
        //std:: cout << "middle ------->" << mid << std::endl;
        mergeSort(A, start, mid);
        mergeSort(A, mid + 1, end); 
        sorted = merge(A, start, mid, end);
    }

    return sorted;
    
}

int main(int argc,char **argv) {

    // Intializations of starting variables
    int *list;
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

    int* sortedList = mergeSort(list, 0, listSize - 1);

    for (i = 0; i < listSize; i++) 
        std::cout << sortedList[i] << ";";
     
    //std::cout << "" << std::endl;

    return 0;

}