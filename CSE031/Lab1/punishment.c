#include <stdio.h>
#include <stdlib.h>

int main() {
	
	int lines = 0;
	
	printf("Enter the number of lines for the punishment: ");
	scanf("%d", &lines);
	
	if (lines < 0) {
		printf("You entered an incorrect number of lines.\n");
		exit(1);
	}
	
	int typo = 0;
	
	printf("Enter the line for which we want to make a typo: ");
	scanf("%d", &typo);
	
	if (typo < 0 || typo > lines) {
		printf("You entered an incorrect value for the line typo.\n");
		exit(1);
	}
	int i = 0;
	
	for (i = 1; i <= lines; i++) {
		if (i != typo) {
			printf("C programming language is the best!\n");
		}
		else {
			printf("C programming language is the bet!\n");
		}
	}
	return 0;
}