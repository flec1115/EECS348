#include <stdio.h> 
#include <stdbool.h>

#define SIZE 5   //matrix size, global definition for easy use

void addMatrices(int matrix1[SIZE][SIZE], int matrix2[SIZE][SIZE]);    
void multiplyMatrices(int matrix1[SIZE][SIZE], int matrix2[SIZE][SIZE]);
void transposeMatrix(int m[SIZE][SIZE]);
void printMatrix(int m[SIZE][SIZE]);

int main() {
	int userInput;
	int userInput2;

	int matrix1[SIZE][SIZE] = {       //example matrices given 
		{1, 2, 3, 4, 5},
		{6, 7, 8, 9, 10},
		{11, 12, 13, 14, 15},
		{16, 17, 18, 19, 20},
		{21, 22, 23, 24, 25}
	};

	int matrix2[SIZE][SIZE] = {
		{25, 24, 23, 22, 21},
		{20, 19, 18, 17, 16},
		{15, 14, 13, 12, 11},
		{10, 9, 8, 7, 6},
		{5, 4, 3, 2, 1}
	};

	//Ask which function the user would like to run
	while(true) {
		printf("Which program would you like to run?\n");
		printf("1) Add Two Matrices\n2) Multiply Two Matrices\n3) Transpose a Matrix\n4) Quit\nSelect a function (1-4): ");
		scanf("%d",&userInput);
		printf("\n");

		switch(userInput){
			case 1:
				printf("Running Function 1...\n--Add Two Matrices--\n");
				addMatrices(matrix1, matrix2);
				break;
			case 2:
				printf("Running Function 2...\n--Multiply Two Matrices--\n");
				multiplyMatrices(matrix1, matrix2);
				break;
			case 3:
				printf("Running Function 3...\n--Transpose a Matrix--\n");
				while(true){
					printf("Would you like to transpose matrix 1 or 2?\nChoice (1/2): ");
					scanf("%d", &userInput2);
					printf("\n");
					if(userInput2 == 1){
						transposeMatrix(matrix1);
						break;
					} else if(userInput2==2){
						transposeMatrix(matrix2);
						break;
					} else {
						printf("Select a valid input between 1 and 2.\n");
					}
				}
				break;
			case 4:
				printf("Quitting Program...");
				break;
			default:
				printf("Select a valid input between 1 and 4.");
				break;
		}

		if(userInput == 4) {
			break;
		}
	}
}

void addMatrices(int matrix1[SIZE][SIZE], int matrix2[SIZE][SIZE]) {
	int matrix3[SIZE][SIZE];
	for(int x=0; x<SIZE; x++){   //does matrix addition
		for(int y=0; y<SIZE; y++){
			matrix3[x][y] = matrix1[x][y]+matrix2[x][y];  

		}
	}
	printMatrix(matrix3);

	//Return matrix3
}

void multiplyMatrices(int matrix1[SIZE][SIZE], int matrix2[SIZE][SIZE]) {
	int matrix3[SIZE][SIZE] = {0}; //We have to initialize the matrix with zeroes due to the use of += operator
	for(int x=0; x<SIZE; x++){
		for(int y=0; y<SIZE; y++){
			for(int z = 0; z < SIZE; z++) {
            matrix3[x][y] += matrix1[x][z] * matrix2[z][y];
			}
		}
	}
	printMatrix(matrix3);
	//Return matrix3
}

void transposeMatrix(int m[SIZE][SIZE]) {
	int mT[SIZE][SIZE];

	for(int x=0; x<SIZE; x++){
		for(int y=0; y<SIZE; y++){
			mT[y][x] = m[x][y];
		}
	}
	printMatrix(mT);  //returns transposed matrix
    
}

void printMatrix(int m[SIZE][SIZE]) {
	for(int x=0; x<SIZE; x++){                // formats matrix 
		for(int y=0; y<SIZE; y++){
			printf("%6d", m[x][y]);
		}
		printf("\n");
	}
	printf("\n———————————————————————\n\n");
}
