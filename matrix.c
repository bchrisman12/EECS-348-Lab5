#include <stdio.h>  // Standard library for input/output
#define SIZE 5  // Define the size of the matrices


void addMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {  // Loop through each row
        for (int j = 0; j < SIZE; j++) {  // Loop through each column
            result[i][j] = m1[i][j] + m2[i][j];  // Sum corresponding elements
        }
    }
}


void multiplyMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]) {
    // Initialize the result matrix to 0
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = 0;
        }
    }
    
    // Perform matrix multiplication
    for (int i = 0; i < SIZE; i++) {  // Loop through rows of m1
        for (int j = 0; j < SIZE; j++) {  // Loop through columns of m2
            for (int k = 0; k < SIZE; k++) {  // Loop through columns of m1 / rows of m2
                result[i][j] += m1[i][k] * m2[k][j];  // Accumulate the product
            }
        }
    }
}


void transposeMatrix(int matrix[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {  // Loop through each row
        for (int j = 0; j < SIZE; j++) {  // Loop through each column
            result[j][i] = matrix[i][j];  // Swap row and column indices
        }
    }
}

// Function to print a matrix
void printMatrix(int matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {  // Loop through each row
        for (int j = 0; j < SIZE; j++) {  // Loop through each column
            printf("%4d ", matrix[i][j]);  // Print each element with spacing
        }
        printf("\n");  
    }
}


int main() {
    int m1[SIZE][SIZE];  // First input matrix
    int m2[SIZE][SIZE];  // Second input matrix
    int result[SIZE][SIZE];  // Matrix to store results

    // Input the first matrix
    printf("Enter elements of the first matrix (%dx%d):\n", SIZE, SIZE);
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf("%d", &m1[i][j]);  // Read element from user
        }
    }

    // Input the second matrix
    printf("Enter elements of the second matrix (%dx%d):\n", SIZE, SIZE);
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf("%d", &m2[i][j]);  // Read element from user
        }
    }

    // Perform and display matrix addition
    printf("\nMatrix Addition:\n");
    addMatrices(m1, m2, result); 
    printMatrix(result); 

    printf("\nMatrix Multiplication:\n");
    multiplyMatrices(m1, m2, result);  
    printMatrix(result); 

    
    printf("\nTranspose of the First Matrix:\n");
    transposeMatrix(m1, result); 
    printMatrix(result); 

    return 0;  
}
