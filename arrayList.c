#include <stdio.h>
#include <stdlib.h>
#include "arrayList.h"

arrayList* createArrayList(int size) {
    arrayList* al = (arrayList*)malloc(sizeof(arrayList));
    if (!al) {
        fprintf(stderr, "메모리 할당 실패\n");
        exit(EXIT_FAILURE);
    }

    al->data = (elementArrayList*)malloc(sizeof(elementArrayList) * size);
    if (!al->data) {
        fprintf(stderr, "메모리 할당 실패\n");
        free(al);
        exit(EXIT_FAILURE);
    }

    al->size = 0;
    al->capacity = size;

    return al;
}

void destroyArrayList(arrayList* al) {
    if (al) {
        free(al->data);
        free(al);
    }
}

int isEmptyArrayList(arrayList* al) {
    return al->size == 0;
}

int isFullArrayList(arrayList* al) {
    return al->size == al->capacity;
}

int sizeArrayList(arrayList* al) {
    return al->size;
}

int insertArrayList(arrayList* al, int pos, elementArrayList item) {
    if (pos < 0 || pos > al->size || item <= 0) {
        return 0;
    }

    if (isFullArrayList(al)) {
        al->capacity *= 2;
        al->data = (elementArrayList*)realloc(al->data, sizeof(elementArrayList) * al->capacity);
        if (al->data == NULL) {
            fprintf(stderr, "메모리 할당 실패\n");
            exit(EXIT_FAILURE);
        }
    }
    for (int i = al->size; i > pos; i--) {
        al->data[i] = al->data[i - 1];
    }

    al->data[pos] = item;
    al->size++;

    return 1;
}

elementArrayList deleteArrayList(arrayList* al, int pos) {
    if (pos < 0 || pos >= al->size) {
        return 0;
    }

    elementArrayList item = al->data[pos];

    for (int i = pos; i < al->size - 1; i++) {
        al->data[i] = al->data[i + 1];
    }

    al->size--;

    return item;
}

int initArrayList(arrayList* al) {
    while (!isEmptyArrayList(al)) {
        deleteArrayList(al, 0);
    }
    return 1;
}

elementArrayList getItemArrayList(arrayList* al, int pos) {
    if (pos < 0 || pos >= al->size) {
        fprintf(stderr, "메모리 할당 실패\n");
        exit(EXIT_FAILURE);
    }
    return al->data[pos];
}

int replaceItemArrayList(arrayList* al, int pos, elementArrayList item) {
    if (pos < 0 || pos >= al->size || item <= 0) {
        return 0;
    }

    al->data[pos] = item;
    return 1;
}

void printArrayList(arrayList* al) {
    printf("리스트: ");
    for (int i = 0; i < al->size; i++) {
        printf("%d ", al->data[i]);
    }
    printf("\n");
}
