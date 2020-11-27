
#include <stdio.h>
#include <malloc.h> //recieved help from classmate

int** matMult(int **a, int **b, int size){
	// (4) Implement your matrix multiplication here. You will need to create a new matrix to store the product.
	int i, j, d;
	int **c = (int**)malloc(size * sizeof(int*));
	for(i = 0;i < size; i++){
		*(c + i) = (int *)malloc(size * sizeof(int*));
		for(j = 0; j < size; j++){
			*(*(c+i)+j) = 0;
			for (d = 0; d < size; d++){
				*(*(c+i)+j) += (*(*(a+i)+d)) * (*(*(b+d)+j));
			}
		}
	}
	return c;


}

void printArray(int **arr, int n){
	// (2) Implement your printArray function here
	int i, j;
	for (i=0; i<n; i++){
		for(j=0;j<n;j++){
			printf("%d\t", *(*(arr+i)+j));
		}
			printf("\n");
	}
}

int main() {
	int n = 2;
	int i, j;
	int **matA, **matB, **matC;
	// (1) Define 2 n x n arrays (matrices). 
	matA = (int**)malloc(n * sizeof(int*));
	matB = (int**)malloc(n * sizeof(int*));
	matC = (int**)malloc(n * sizeof(int*));
	
	
	for (i = 0; i < n; i++){
		*(matA + i) = (int*)malloc(n * sizeof(int));
		for(j = 0; j < n; j++){
			*(*(matA + i) + j) = 4;
		}
	}
	
	for (i = 0; i < n; i++){
		*(matB+ i) = (int*)malloc(n * sizeof(int));
		for(j = 0; j < n; j++){
			*(*(matB + i) + j) = 5;
		}
	}

	for (i=0; i<n; i++){
	*(matC+ i) = (int*)malloc(n * sizeof(int));
		for(j=0;j<n;j++){
			*(*(matC+ i)+j) = 0;
		}
	}
	
	// (3) Call printArray to print out the 2 arrays here.
	printArray(matA, n);
	printArray(matB, n);
	
	//(5) Call matMult to multiply the 2 arrays here.
	matC = matMult(matA, matB, n);
	
	//(6) Call printArray to print out resulting array here.
	printArray(matC, n);


    return 0;
}