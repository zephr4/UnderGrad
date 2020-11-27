#ifndef FindMin_h
#define FindMin_h

// Declare and define the findMin function here
int findMin (int N[], int x, int y) {
    int min = N[x];
    int i;
    for (i = 1; i < y; i++) {
        if (N[i] < min) {
            min = N[i];
        }
    }
    return min;
}


// Do not write any code below this line
#endif
