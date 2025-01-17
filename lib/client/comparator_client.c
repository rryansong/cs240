//
// Created by haoyu on 11/1/22.
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "comparator.h"


void stringLenComparator_demo() {
    char *ss[3] = {"abc\n", "ab\n", "a\n"};
    for (int i = 0; i < 3; ++i) {
        printf(ss[i]);
    }
//    ss[0] = ss[1];
    qsort(ss, 3, sizeof(char *), stringLenComparator);
    for (int i = 0; i < 3; ++i) {
        printf(ss[i]);
    }
}

void intComparator_demo() {
    int a = 12, b = 11, l = 10;
    printf("a > b: %d\n", intComparator(&a, &b));
    int arr[l];
    randIntArray(arr, l, 100);
    print_IntArray(arr, l);
    qsort(arr, l, sizeof(int), intComparator);
    print_IntArray(arr, l);
}

int index_comparator(void *const a, void *const b) {
    return ((int *) a)[1] - ((int *) b)[1];
}

void sortIndex_demo() {
    int l = 5;
    int arr[l];
    for (int i = 0; i < l; ++i) {
        arr[i] = i;
    }
    print_IntArray(arr, l);
    randIntArray(arr, l, 100);
    print_IntArray(arr, l);

    int aux[l][2];
    for (int i = 0; i < l; ++i) {
        aux[i][0] = i;
        aux[i][1] = arr[i];
    }
    qsort(aux, l, 2 * sizeof(int), index_comparator);
    int aux2[2][l];
    for (int i = 0; i < l; ++i) {
        for (int j = 0; j < 2; ++j) {
            aux2[j][i] = aux[i][j];
        }
    }
    printf("\n");
    print_IntArray(aux2[0], l);
    print_IntArray(aux2[1], l);

}

int main() {
    intComparator_demo();
    stringLenComparator_demo();
    sortIndex_demo();
    time(NULL);
    printf("Hours since January 1, 1970 = %ld\n", time(NULL) / 3600);
    srand(time(NULL));
    printf("%d\n", rand());
    printf("%d\n", RAND_MAX);

}