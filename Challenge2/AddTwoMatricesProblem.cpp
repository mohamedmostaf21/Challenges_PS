#include "stdio.h"
//Problem
//
//By using one for loop how to add two matrices
// 
// 
// 
// 
// First we can add two matrices easily using two loops as shown
// 

#define ROWS 5
#define COLS 5

void addMatrices(int mat1[][COLS], int mat2[][COLS], int result[][COLS]) {
	for (size_t i = 0; i < ROWS; i++)
	{
		for (size_t j = 0; j < COLS; j++)
		{
			result[i][j] = mat1[i][j] + mat2[i][j];
		}
	}
}

void displayMatrix(int matrix[][COLS]) {
	for (size_t i = 0; i < ROWS; i++)
	{
		for (size_t j = 0; j < COLS; j++)
		{
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}
}

//Second So the solution is using pointers as shown 
void addMatricesUsingPointers(int mat1[][COLS], int mat2[][COLS], int result[][COLS]) {
	//create three pointers
	int* ptr1 = &mat1[0][0];
	int* ptr2 = &mat2[0][0];
	int* ptrResult = &result[0][0];

	for (size_t i = 0; i < ROWS * COLS; i++)
	{
		*ptrResult = *ptr1 + *ptr2;
		ptr1++;
		ptr2++;
		ptrResult++;
	}
}

void displayMatrixUisngPointers(int matrix[][COLS]) {
	int* ptr = &matrix[0][0];
	for (size_t i = 0; i < ROWS * COLS; i++)
	{
		printf("%d\t", *ptr);
		ptr++;
		//to add line after each row
		if ((i + 1) % COLS == 0)
			printf("\n");
	}
}
int main()
{
	//test of the first idea
	int matrix1[ROWS][COLS]{
		2, 2, 2, 2, 2,
		2, 2, 2, 2, 2,
		2, 2, 2, 2, 2,
		2, 2, 2, 2, 2,
		2, 2, 2, 2, 2,
	};

	int matrix2[ROWS][COLS]{
		3, 3, 3, 3, 3,
		3, 3, 3, 3, 3,
		3, 3, 3, 3, 3,
		3, 3, 3, 3, 3,
		3, 3, 3, 3, 3,
	};

	int result[ROWS][COLS];
	addMatrices(matrix1, matrix2, result);
	printf("\nSum of matrices:\n");
	displayMatrix(result);

	//test for the second idea
	int matrixUsingPointers1[ROWS][COLS]{
		2, 2, 2, 2, 2,
		2, 2, 2, 2, 2,
		2, 2, 2, 2, 2,
		2, 2, 2, 2, 2,
		2, 2, 2, 2, 2,
	};

	int matrixUsingPointers2[ROWS][COLS]{
		3, 3, 3, 3, 3,
		3, 3, 3, 3, 3,
		3, 3, 3, 3, 3,
		3, 3, 3, 3, 3,
		3, 3, 3, 3, 3,
	};

	int resultUsingPointers[ROWS][COLS];
	addMatricesUsingPointers(matrixUsingPointers1, matrixUsingPointers2, resultUsingPointers);
	printf("\nSum of matrices:\n");
	displayMatrixUisngPointers(resultUsingPointers);
	

	return 0;
}

