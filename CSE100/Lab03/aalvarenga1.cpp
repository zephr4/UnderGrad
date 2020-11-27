#include <iostream>

int max(int a, int b) { 

    // A simple comparison to return the larger number
    if (a > b)    
        return a;
    else 
        return b;
} 

int Find_Max_Subarray_Sum(int* A, int low, int high) {

    int i;
    int sum = 0;
    int max = -999999999;

    // Finds the max of the sub array
    for(i = low; i < high; i++) {

        sum = sum + A[i];
        if (sum > max) {

            max = sum;
        }
        return max;
    }
    return 0;
}

int Find_Max_Crossing_Subarray_Sum(int* A, int low, int mid, int high) {
    int sum = 0;
    int leftSum = -999999999;

    int i;

    // Finds the max of the maxSubArray on the left
    for (i = mid; i >= low; i--) {

        sum = sum + A[i];
        if (sum > leftSum) {

            leftSum = sum;
        }
    }
    sum = 0;
    int rightSum = -999999999;

    int j;

    // Finds the max of the maxSubArray on the right
    for (j = mid + 1; j <= high; j++) {

        sum = sum + A[j];
        if (sum > rightSum) {

            rightSum = sum;
        }
    }
    // Adds the two sums together to give the max crossing sum
    return leftSum + rightSum;
}

int Find_Max_Subarray(int* A, int low, int high) {

    // Initializations of Variables
    int mid;
    int leftMax;
    int leftArr;
    int rightMax;
    int rightArr;
    int crossMax;

    // Termination Case: if length of A is 1, return value of A
    if (low == high) {

        return A[low];
    }
    
    else {     
        // Finds 3 maxes: Left, Right, and the Cross, then compares them
        mid = low + (high - low) / 2;
        leftArr = Find_Max_Subarray(A, low, mid);
        rightArr = Find_Max_Subarray(A, mid + 1, high);
        crossMax = Find_Max_Crossing_Subarray_Sum(A, low, mid, high);

        leftMax = Find_Max_Subarray_Sum(A, 0, mid);
        rightMax = Find_Max_Subarray_Sum(A, mid + 1, high);

        // std::cout << leftMax << std::endl;
        // std::cout << rightMax << std::endl;
        // std::cout << crossMax << std::endl;
        // std::cout << "" << std::endl;
        // std::cout << "Left: " << leftArr << std::endl;
        // std::cout << "LeftMax: " << leftMax << std::endl;
        // std::cout << "Right: " << rightArr << std::endl;
        // std::cout << "RightMax: " << rightMax << std::endl;
        // std::cout << "" << std::endl;

        return max(max(max(leftMax, rightMax), crossMax), max(leftArr, rightArr));
    }

    return 0;
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
    
    int max = Find_Max_Subarray(list, 0, listSize - 1);
    
    std::cout << max;

    return 0;

}