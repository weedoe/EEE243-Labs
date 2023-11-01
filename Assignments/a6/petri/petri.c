/* Author: OCdt Paterson  */

#include <stdio.h>
#include <stdlib.h>

#include "petri.h"

void print_petri_dish(int dish[][EDGE_LENGTH]) {
	for (int row = 0; row < EDGE_LENGTH; row++) {
        for (int col = 0; col < EDGE_LENGTH; col++) {
            printf("%d ", dish[row][col]);
        }
        printf("\n");
    }
}

bool are_adjacent_infected(int dish[][EDGE_LENGTH], int row, int col) {
	for(int i = row - 1; i <= row + 1; i++) {
        for(int j = col - 1; j <= col + 1; j++) {
            if(i >= 0 && i < EDGE_LENGTH && j >= 0 && j < EDGE_LENGTH) {
                if(dish[i][j] == 1) {
                    return true;
                }
            }
        }
    }
    return false;
}

void spread_infection(int dish[][EDGE_LENGTH]) {
	int new_dish[EDGE_LENGTH][EDGE_LENGTH];
    for(int row = 0; row < EDGE_LENGTH; row++) {
        for(int col = 0; col < EDGE_LENGTH; col++) {
            if(are_adjacent_infected(dish, row, col)) {
                new_dish[row][col] = 1;
            } else {
                new_dish[row][col] = 0;
            }
        }
    }
    for(int row = 0; row < EDGE_LENGTH; row++) {
        for(int col = 0; col < EDGE_LENGTH; col++) {
            dish[row][col] = new_dish[row][col];
        }
    }
}

