#include <stdio.h>
#include <stdlib.h>

// Declare printSudoku function
void printSudoku(int***);
// Declare solveSudoku function
int solveSudoku(int***);

//Helper functions. You can define any functions that can help your solve the problem

/* 1 = true, 0 = false */

int rowCheck(int*** arr, int rowIndex, int boxIndex, int num){
	
	int j, b;
	
	if(boxIndex < 3 && boxIndex >= 0){
		boxIndex = 0;
		
		for(b = boxIndex; b < 3; b++){
			for(j = 0; j < 3; j++){
				if(*(*(*(arr + b) + rowIndex) + j) == num){
					return 1;
				}
			}
		}
	}
	
	else if(boxIndex < 6 && boxIndex >= 3){
		boxIndex = 3;
		
		for(b = boxIndex; b < 6; b++){
			for(j = 0; j < 3; j++){
				if(*(*(*(arr + b) + rowIndex) + j) == num){
					return 1;
				}
			}
		}
	}
	
	else if(boxIndex < 9 && boxIndex >= 6){
		boxIndex = 6;
		
		for(b = boxIndex; b < 9; b++){
			for(j = 0; j < 3; j++){
				if(*(*(*(arr + b) + rowIndex) + j) == num){
					return 1;
				}
			}
		}
	}
	return 0;
}

int colCheck(int*** arr, int colIndex, int boxIndex, int num){
	
	int i, b;
	
	if(boxIndex % 3 == 0){
		boxIndex = 0;
	}
	else if(boxIndex % 3 == 1){
		boxIndex = 1;
	}
	else if(boxIndex % 3 == 2){
		boxIndex = 2;
	}
	/*if colCheck returns 1, then num is in the box */
	for(b = boxIndex; b < 9; b += 3){ 
		for(i = 0; i < 3; i++){
			if(*(*(*(arr + b) + i) + colIndex) == num){
				return 1;
			}
		}
	}
	return 0;
}

int boxCheck(int*** arr, int boxIndex, int num){
	
	int i, j;
	
	/* if boxCheck returns 1, then num is in the box */
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			if(*(*(*(arr + boxIndex) + i) + j) == num){
				return 1;
			}
		}
	}
	return 0;
}

int inImmediate(int*** arr, int boxIndex, int rowIndex, int colIndex, int num){
	
	
	if(rowCheck(arr, rowIndex, boxIndex, num) || colCheck(arr, colIndex, boxIndex, num) || boxCheck(arr, boxIndex, num)){
		return 0;
	}
	return 1;
}

/*
The main program reads a text file containing the block values of the Sudoku grid.
It then saves each 3x3 block into a 2D array. The Sudoku grid is composed of 9 3x3 blocks.
DO NOT MODIFY THE MAIN FUNTION!!!
*/
int main(int argc, char **argv) {
	if (argc != 2) {
		fprintf(stderr, "Usage: %s <file name>\n", argv[0]);
		return 2;
	}
    int i, j;
    FILE *fptr;
    int ***blocks = (int***)malloc(9 * sizeof(int**));

    // Open file for reading
    fptr = fopen(argv[1], "r");
    if (fptr == NULL) {
        printf("Cannot Open File!\n");
        return 0;
    }

	// Read 9x9 blocks into 2D arrays
    for(i=0; i<9; i++)
    {
        *(blocks+i) = (int**)malloc(3 * sizeof(int*));
        printf("Reading numbers in block %d... \n", i+1);
        for(j=0; j<3; j++)
        {
            *(*(blocks+i)+j) = (int*)malloc(3 * sizeof(int));

                fscanf(fptr, "%d %d %d", *(*(blocks+i)+j), *(*(blocks+i)+j)+1, *(*(blocks+i)+j)+2);
                printf("%d %d %d\n", *(*(*(blocks+i)+j)), *(*(*(blocks+i)+j)+1), *(*(*(blocks+i)+j)+2));
        }
    }
	
	// Print out original Sudoku grid
    printf("Printing Sudoku before being solved:\n");
    printSudoku(blocks);

	// Call solveSudoku and print out result
    printf("\nSolving Sudoku...\n\n");
    if(solveSudoku(blocks)){
        printf("Sudoku solved!\n");
        printSudoku(blocks);
    }
    else
        printf("This Sudoku cannot be solved!\n");

    return 0;
}


void printSudoku(int*** arr){
	// This function will print out the complete Sudoku grid (arr). It must produce the output in the SAME format as the samples in the instructions. 	
	// Your implementation here
	
    int i, j, b;
	
	/* i = row, j = col, b = box */
	for(i = 0; i < 3; i++){  
		for(b = 0; b < 3; b++){
			for(j = 0; j < 3; j++){
				printf("%d ", *(*(*(arr + b) + i) + j));
				if((j + 1) % 3 == 0)
					printf(" | ");
			}
		}
		printf("\n");
	}
	
	printf("--------------------------\n");
	
	for(i = 0; i < 3; i++){               
		for(b = 3; b < 6; b++){
			for(j = 0; j < 3; j++){
				printf("%d ", *(*(*(arr + b) + i) + j));
				if((j + 1) % 3 == 0)
					printf(" | ");
			}
		}
		printf("\n");
	}
	
	printf("--------------------------\n");
	
	for(i = 0; i < 3; i++){               
		for(b = 6; b < 9; b++){
			for(j = 0; j < 3; j++){
				printf("%d ", *(*(*(arr + b) + i) + j));
				if((j + 1) % 3 == 0)
					printf(" | ");
			}
		}
		printf("\n");
	}

}


int solveSudoku(int*** blocks){
	// This is the function to solve the Sudoku (blocks). Feel free to use any helper functions.
	// YOU MUST NOT USE ANY ARRAY NOTATION ([])!
	
	//Your implementation here
	
	int i, j, b, num;
	
	/* i = row, j = column, b = box */
	for(b = 0; b < 9; b++){
		for(i = 0; i < 3; i++){
			for(j = 0; j < 3; j++){
				if(*(*(*(blocks + b) + i) + j) == 0){

					for(num = 1; num <= 9; num++){
						
						if(inImmediate(blocks, b, i, j, num)){
							
							*(*(*(blocks + b) + i) + j) = num; 
				
							if(solveSudoku(blocks))
								return 1;
							
						}
					}
					*(*(*(blocks + b) + i) + j) = 0;
					return 0;
				}
			}
		}
	}
	return 1;
}

/* Collaborated with: Spencer Tang */
/* Recieved help from: Omar Gonzales */