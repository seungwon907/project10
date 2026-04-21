#ifndef SPARSE_MATRIX_H
#define SPARSE_MATRIX_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100 

typedef struct {
    int row;
    int col;
    int value;
} SparseElement;

typedef struct {
    SparseElement* data;
    int size;
} SparseMatrix;

SparseMatrix* createSparseMatrix(int nonZeroCount);
void destroySparseMatrix(SparseMatrix* matrix);
void printSparseMatrix(SparseMatrix* matrix);
SparseMatrix* transposeSparseMatrix(SparseMatrix* matrix, int* moveCount);

#endif
#pragma once
