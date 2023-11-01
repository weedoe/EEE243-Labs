/* Author:  OCdt Paterson  */

#include <stdio.h>
#include "petri.h"
int compareArrays(int a[EDGE_LENGTH][EDGE_LENGTH], int b[EDGE_LENGTH][EDGE_LENGTH]);
int main(void) {
    printf("Petri...\n");
    int dish[EDGE_LENGTH][EDGE_LENGTH] = {
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 1, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 1, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0}};
    int all_ones[EDGE_LENGTH][EDGE_LENGTH] = {
            {1, 1, 1, 1, 1, 1, 1, 1, 1},
            {1, 1, 1, 1, 1, 1, 1, 1, 1},
            {1, 1, 1, 1, 1, 1, 1, 1, 1},
            {1, 1, 1, 1, 1, 1, 1, 1, 1},
            {1, 1, 1, 1, 1, 1, 1, 1, 1},
            {1, 1, 1, 1, 1, 1, 1, 1, 1},
            {1, 1, 1, 1, 1, 1, 1, 1, 1},
            {1, 1, 1, 1, 1, 1, 1, 1, 1},
            {1, 1, 1, 1, 1, 1, 1, 1, 1}};
    int k = -1;
    while (1) {
        if(k == -1) {
            printf("Initial state:\n");
        }
        else {
            printf("Iteration %d:\n", k);
        }
        print_petri_dish(dish);
        spread_infection(dish);
        k++;
        printf("\n");
        if (compareArrays(dish, all_ones)) {
            printf("Iteration %d:\n", k);
            print_petri_dish(dish);
            break;
        }

    }
}
int compareArrays(int a[EDGE_LENGTH][EDGE_LENGTH],
                  int b[EDGE_LENGTH][EDGE_LENGTH]) {
    for (int i = 0; i < EDGE_LENGTH; i++) {
        for (int j = 0; j < EDGE_LENGTH; j++) {
            if (a[i][j] != b[i][j]) {
                return 0;
            }
        }
    }
    return 1;
}