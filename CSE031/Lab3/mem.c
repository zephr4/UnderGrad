#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

 int main() {
	int num;
	int *ptr;
	int **handle; // stored in the stack because they are local variables

	num = 14; 
	ptr = (int *)malloc(2 * sizeof(int)); //allocates space 
	*ptr = num;
	handle = (int **)malloc(1 * sizeof(int *));
	*handle = ptr;

	// Insert extra code here
	//int *adrNum = &num;
	//int *adrPtr = ptr;
	//int *adrHandle = *handle;
	
	//printf("Value of Num: %d\n", num);
	//printf("Value of Ptr: %p\n", ptr);
	//printf("Value of Handle: %p\n", handle);
	printf("Address of Num: %p\n", &num);
	printf("Address of Ptr: %p\n", &ptr);
	printf("Address of Handle: %p\n", &handle);
	return 0;
} 

