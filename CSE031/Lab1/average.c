#include <stdio.h>
#include <stdlib.h>
	
int main() {
	
	int num;
	int sumPos = 0;
	int sumNeg = 0;
	int countPos = 0;
	int countNeg = 0;
	
	while(num != 0) {
		printf("Please enter a number: ");
		scanf("%d", &num);
		
		if (num > 0) {
			sumPos = sumPos + num;
			countPos = countPos + 1;
		}
		
		else if (num < 0) {
			sumNeg = sumNeg + num;
			countNeg = countNeg + 1;
		}
		
		else {
			break;
		}	
	}
	
	if (sumPos != 0 && countPos != 0) {
		printf("Positive Average: %d\n", sumPos/countPos);
	}
	
	if (sumNeg != 0 && countNeg != 0) {
		printf("Negative Average: %d\n", sumNeg/countNeg);
	}
	return 0;
}