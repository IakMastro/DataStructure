#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int main() {
    int arr[SIZE];
    int max_poss, min_poss;

    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 101;
    }

    for (int i = 0; i < SIZE; i++) {
        printf("array[%d] = %d\n", i, arr[i]);
    }

    max_poss = 0;
    min_poss = 0;
    for (int i = 0; i < SIZE; i++) {
        if (arr[i] > arr[max_poss])
            max_poss = i;

        if (arr[i] < arr[min_poss])
            min_poss = i;
    }


    printf("MAX: array[%d] = %d\n", max_poss, arr[max_poss]);
    printf("MIN: array[%d] = %d\n", min_poss, arr[min_poss]);

    return 0;
}
