#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include "arrayList.h"

void menu() {
    printf("메뉴:\n");
    printf("1. 추가\n");
    printf("2. 삭제\n");
    printf("3. 변경\n");
    printf("4. 출력\n");
    printf("5. 모두 삭제\n");
    printf("0. 종료\n");
}

int main() {
    arrayList* myArrayList = createArrayList(2);
    int choice, pos, value;

    do {
        menu();
        printf("선택: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: 
            printf("양의 정수와 위치 입력: ");
            scanf("%d %d", &value, &pos);
            if (insertArrayList(myArrayList, pos, value)) {
                printf("추가 성공\n");
            }
            else {
                printf("추가 실패: 잘못된 위치 또는 양의 정수가 아닙니다.\n");
            }
            break;

        case 2: 
            printf("삭제할 위치 입력: ");
            scanf("%d", &pos);
            if (deleteArrayList(myArrayList, pos)) {
                printf("삭제 성공\n");
            }
            else {
                printf("삭제 실패: 잘못된 위치입니다.\n");
            }
            break;

        case 3: 
            printf("양의 정수와 위치 입력: ");
            scanf("%d %d", &value, &pos);
            if (replaceItemArrayList(myArrayList, pos, value)) {
                printf("변경 성공\n");
            }
            else {
                printf("변경 실패: 잘못된 위치 또는 양의 정수가 아닙니다.\n");
            }
            break;

        case 4: 
            printArrayList(myArrayList);
            break;

        case 5: 
            initArrayList(myArrayList);
            printf("모두 삭제되었습니다.\n");
            break;

        case 0: 
            destroyArrayList(myArrayList);
            printf("프로그램 종료\n");
            break;

        default:
            printf("잘못된 선택입니다. 다시 시도하세요.\n");
        }
    } while (choice != 0);

    return 0;
}
