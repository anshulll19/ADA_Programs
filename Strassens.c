#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int **alloc_matrix(int n) {
    int **mat = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
        mat[i] = (int *)malloc(n * sizeof(int));
    return mat;
}

void free_matrix(int **mat, int n) {
    for (int i = 0; i < n; i++)
        free(mat[i]);
    free(mat);
}

void fill_matrix(int **mat, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            mat[i][j] = rand() % 10;
}

void add_matrix(int **A, int **B, int **C, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

void sub_matrix(int **A, int **B, int **C, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
}

void multiply_iterative(int **A, int **B, int **C, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
}

// Strassen Algorithm
void strassen(int **A, int **B, int **C, int n) {
    if (n <= 2) {
        multiply_iterative(A, B, C, n);
        return;
    }

    int k = n / 2;
    int **A11 = alloc_matrix(k), **A12 = alloc_matrix(k),
        **A21 = alloc_matrix(k), **A22 = alloc_matrix(k);
    int **B11 = alloc_matrix(k), **B12 = alloc_matrix(k),
        **B21 = alloc_matrix(k), **B22 = alloc_matrix(k);
    int **C11 = alloc_matrix(k), **C12 = alloc_matrix(k),
        **C21 = alloc_matrix(k), **C22 = alloc_matrix(k);
    int **M1 = alloc_matrix(k), **M2 = alloc_matrix(k), **M3 = alloc_matrix(k),
        **M4 = alloc_matrix(k), **M5 = alloc_matrix(k), **M6 = alloc_matrix(k),
        **M7 = alloc_matrix(k);
    int **T1 = alloc_matrix(k), **T2 = alloc_matrix(k);

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + k];
            A21[i][j] = A[i + k][j];
            A22[i][j] = A[i + k][j + k];
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + k];
            B21[i][j] = B[i + k][j];
            B22[i][j] = B[i + k][j + k];
        }
    }

    add_matrix(A11, A22, T1, k); add_matrix(B11, B22, T2, k); strassen(T1, T2, M1, k);
    add_matrix(A21, A22, T1, k); strassen(T1, B11, M2, k);
    sub_matrix(B12, B22, T2, k); strassen(A11, T2, M3, k);
    sub_matrix(B21, B11, T2, k); strassen(A22, T2, M4, k);
    add_matrix(A11, A12, T1, k); strassen(T1, B22, M5, k);
    sub_matrix(A21, A11, T1, k); add_matrix(B11, B12, T2, k); strassen(T1, T2, M6, k);
    sub_matrix(A12, A22, T1, k); add_matrix(B21, B22, T2, k); strassen(T1, T2, M7, k);

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            C11[i][j] = M1[i][j] + M4[i][j] - M5[i][j] + M7[i][j];
            C12[i][j] = M3[i][j] +
