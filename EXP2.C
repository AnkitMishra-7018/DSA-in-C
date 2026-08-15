#include <stdio.h>

#define MAX 10

void inputMatrix(int mat[][MAX], int rows, int cols, const char *name) {
    printf("Enter elements of matrix %s (%d x %d):\n", name, rows, cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            scanf("%d", &mat[i][j]);
}

void displayMatrix(int mat[][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            printf("%d\t", mat[i][j]);
        printf("\n");
    }
}

// a) Matrix multiplication: A(r1 x c1) * B(r2 x c2), valid only if c1 == r2
void multiplyMatrix(int A[][MAX], int r1, int c1, int B[][MAX], int r2, int c2, int result[][MAX]) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < c1; k++)
                result[i][j] += A[i][k] * B[k][j];
        }
    }
}

// b) Difference of sum of two diagonal elements (only meaningful for square matrix)
int diagonalDifference(int mat[][MAX], int n) {
    int primaryDiagSum = 0, secondaryDiagSum = 0;
    for (int i = 0; i < n; i++) {
        primaryDiagSum += mat[i][i];
        secondaryDiagSum += mat[i][n - 1 - i];
    }
    int diff = primaryDiagSum - secondaryDiagSum;
    return (diff < 0) ? -diff : diff;  // absolute difference
}

int main() {
    int A[MAX][MAX], B[MAX][MAX], result[MAX][MAX];
    int r1, c1, r2, c2;
    int choice;

    while (1) {
        printf("\n----- 2D MATRIX OPERATIONS MENU -----\n");
        printf("1. Multiply two matrices\n");
        printf("2. Difference of sum of diagonals (single square matrix)\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter rows and columns of matrix A: ");
                scanf("%d %d", &r1, &c1);
                inputMatrix(A, r1, c1, "A");

                printf("Enter rows and columns of matrix B: ");
                scanf("%d %d", &r2, &c2);
                inputMatrix(B, r2, c2, "B");

                if (c1 != r2) {
                    printf("Matrix multiplication not possible. ");
                    printf("Columns of A (%d) must equal rows of B (%d).\n", c1, r2);
                    break;
                }

                multiplyMatrix(A, r1, c1, B, r2, c2, result);

                printf("\nMatrix A:\n");
                displayMatrix(A, r1, c1);
                printf("\nMatrix B:\n");
                displayMatrix(B, r2, c2);
                printf("\nResultant Matrix (A x B):\n");
                displayMatrix(result, r1, c2);
                break;

            case 2: {
                int n;
                printf("Enter order (n) of square matrix: ");
                scanf("%d", &n);
                if (n <= 0 || n > MAX) {
                    printf("Invalid size.\n");
                    break;
                }
                inputMatrix(A, n, n, "A");

                printf("\nMatrix A:\n");
                displayMatrix(A, n, n);

                int diff = diagonalDifference(A, n);
                printf("Absolute difference between sum of diagonals = %d\n", diff);
                break;
            }

            case 3:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}