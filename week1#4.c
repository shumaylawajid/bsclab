#include <stdio.h>

void add_matrices(int a[2][2], int b[2][2], int result[2][2]) {
    int i, j;
    for (i = 0; i < 2; i++)
        for (j = 0; j < 2; j++)
            result[i][j] = a[i][j] + b[i][j];
}

void subtract_matrices(int a[2][2], int b[2][2], int result[2][2]) {
    int i, j;
    for (i = 0; i < 2; i++)
        for (j = 0; j < 2; j++)
            result[i][j] = a[i][j] - b[i][j];
}

void multiply_matrices(int a[2][3], int b[3][2], int result[2][2]) {
    int i, j, k;
    for (i = 0; i < 2; i++)
        for (j = 0; j < 2; j++) {
            result[i][j] = 0;
            for (k = 0; k < 3; k++)
                result[i][j] += a[i][k] * b[k][j];
        }
}

void transpose_matrix(int a[3][2], int result[2][3]) {
    int i, j;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 2; j++)
            result[j][i] = a[i][j];
}

void print_matrix(int rows, int cols, int matrix[10][10]) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}

int main() {
    int A[2][2] = {{1, 2}, {3, 4}};
    int B[2][2] = {{5, 6}, {7, 8}};
    int Zero[2][2] = {{0, 0}, {0, 0}};
    int Result[2][2];

    printf("Addition:\n");
    add_matrices(A, B, Result);
    print_matrix(2, 2, Result);

    printf("\nAddition with Zero Matrix:\n");
    add_matrices(A, Zero, Result);
    print_matrix(2, 2, Result);

    printf("\nSubtraction:\n");
    subtract_matrices(B, A, Result);
    print_matrix(2, 2, Result);

    printf("\nMultiplication (2x3 × 3x2):\n");
    int M1[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int M2[3][2] = {{7, 8}, {9, 10}, {11, 12}};
    multiply_matrices(M1, M2, Result);
    print_matrix(2, 2, Result);

    printf("\nTranspose (3x2 ? 2x3):\n");
    int T[3][2] = {{1, 2}, {3, 4}, {5, 6}};
    int T_result[2][3];
    transpose_matrix(T, T_result);
    print_matrix(2, 3, T_result);

    return 0;
}

