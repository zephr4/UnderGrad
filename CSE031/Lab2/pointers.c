#include <stdio.h>

int main(){
	int x = 0, y = 0, *px = &x, *py = &y;
	int i = 0;
	int arr[10];
	
	for (i = 0; i < 10; i++) {
		arr[i] = i;
		printf("%d\n", *(arr + i));
	}
	
	printf("%p\n", px); //print address of x
	printf("%p\n", py); //print address of y
	printf("%p\n", &arr); //print address of arr
	
	return 0;
}