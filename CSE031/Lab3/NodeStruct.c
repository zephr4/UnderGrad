#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct Node {
    int iValue;
    float fValue ;
    struct Node *next;
};

int main() {

    struct Node *head = (struct Node*) malloc(sizeof(struct Node));
    head->iValue = 5;
    head->fValue = 3.14;
	
	// Insert extra code here
	printf("Head: %p\n", head);
	printf("Address of Head: %p\n", &head);
	printf("Address of iValue: %p\n", &head->iValue);
	printf("Address of fValue: %p\n", &head->fValue);
	printf("Address of Next: %p\n", head->next);
	
	
	return 0;
}