#include <stdio.h>
#include "sparse_matrix.h"

int main() {
    int nonZeroCount = 20;
    SparseMatrix* sparseMatrix = createSparseMatrix(nonZeroCount);

    printSparseMatrix(sparseMatrix);

    int moveCount = 0;
    SparseMatrix* transposedMatrix = transposeSparseMatrix(sparseMatrix, &moveCount);

    printf("\n전치 행렬:\n");
    printSparseMatrix(transposedMatrix);
    printf("데이터 이동 횟수: %d\n", moveCount);

    destroySparseMatrix(sparseMatrix);
    destroySparseMatrix(transposedMatrix);

    return 0;
}
