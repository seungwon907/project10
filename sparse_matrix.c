#include "sparse_matrix.h"

SparseMatrix* createSparseMatrix(int nonZeroCount) {
    SparseMatrix* matrix = (SparseMatrix*)malloc(sizeof(SparseMatrix));
    if (!matrix) {
        fprintf(stderr, "메모리 할당 실패\n");
        exit(EXIT_FAILURE);
    }

    matrix->data = (SparseElement*)malloc(sizeof(SparseElement) * nonZeroCount);
    if (!matrix->data) {
        fprintf(stderr, "메모리 할당 실패\n");
        free(matrix);
        exit(EXIT_FAILURE);
    }

    matrix->size = nonZeroCount;

    srand(time(NULL));
    int count = 0;
    while (count < nonZeroCount) {
        int row = rand() % 10;
        int col = rand() % 10;
        int value = rand() % 100 + 1; 

        int exists = 0;
        for (int i = 0; i < count; i++) {
            if (matrix->data[i].row == row && matrix->data[i].col == col) {
                exists = 1;
                break;
            }
        }

        if (!exists) {
            matrix->data[count].row = row;
            matrix->data[count].col = col;
            matrix->data[count].value = value;
            count++;
        }
    }

    return matrix;
}

void destroySparseMatrix(SparseMatrix* matrix) {
    if (matrix) {
        free(matrix->data);
        free(matrix);
    }
}

void printSparseMatrix(SparseMatrix* matrix) {
    printf("희소 행렬:\n");
    for (int i = 0; i < matrix->size; i++) {
        printf("(%d, %d) = %d\n", matrix->data[i].row, matrix->data[i].col, matrix->data[i].value);
    }
}

SparseMatrix* transposeSparseMatrix(SparseMatrix* matrix, int* moveCount) {
    SparseMatrix* transposed = (SparseMatrix*)malloc(sizeof(SparseMatrix));
    if (!transposed) {
        fprintf(stderr, "메모리 할당 실패\n");
        exit(EXIT_FAILURE);
    }

    transposed->size = matrix->size;
    transposed->data = (SparseElement*)malloc(sizeof(SparseElement) * transposed->size);
    if (!transposed->data) {
        fprintf(stderr, "메모리 할당 실패\n");
        free(transposed);
        exit(EXIT_FAILURE);
    }

    *moveCount = 0; 

    for (int i = 0; i < matrix->size; i++) {
        transposed->data[i].row = matrix->data[i].col;
        transposed->data[i].col = matrix->data[i].row;
        transposed->data[i].value = matrix->data[i].value;
        (*moveCount) += 3; 
    }

    return transposed;
}
