//
// Created by Marley on 25/10/2023.
//

#include <stdio.h>
#include <malloc.h>
#include "level_cells.h"

/*
 *
 * CREATE A CELL with a value and a number of levels
 * PARAMETERS : value | number of levels
 */
t_d_cell *createCell(int val, int levels) {

    t_d_cell *new_cell;
    new_cell = (t_d_cell*) malloc(1*sizeof(t_d_cell));

    new_cell->value = val;

    for (int i = 0; i < levels; i++) {
        new_cell->pointer_array[i] = NULL;
    }

    return new_cell;
}

/*
 *
 * INITIALIZE ARRAY OF VALUES
 * PARAMETERS : number of cells
 */
int *initialize_array_values(int NumberOfCells) {
    int *values;
    values = (int*) malloc(NumberOfCells*sizeof(int));

    for (int i = 0; i < NumberOfCells; i++) {
        values[i] = i;
    }
    return values;
}

/*
 *
 * DISPLAY ARRAY OF VALUES
 * PARAMETERS : array of values | number of cells
 */
void display_array_values(int *values, int NumberOfCells) {
    printf("Values of the list :");
    for (int i = 0; i < NumberOfCells; i++) {
        printf("[%d]  ", values[i]+1);
    }
}

/*
 *
 * INITIALIZE ARRAY OF LEVELS
 * PARAMETERS : number of cells
 */
int *initialize_array_levels(int NumberOfCells) {
    int *number_levels_cell;
    number_levels_cell = (int *) malloc(NumberOfCells * sizeof(int));

    // Start by filling the array with 0s
    for (int i = 0; i < NumberOfCells; i++) {
        number_levels_cell[i] = 0;
    }

    // Start by adding 1 to each index % 2 = 0, then add 2 to each index % 4 = 0, then add 4 to each index % 8 = 0, etc.
    for (int k = 2; k <= NumberOfCells / 2 + 1; k = k * 2) {
        for (int i = k - 1; i <= NumberOfCells - k; i = i + k) {
            if (i % 2 == 1) {
                number_levels_cell[i]++;
            }
        }
    }

    return number_levels_cell;
}

/*
 *
 * DISPLAY ARRAY OF LEVELS
 * PARAMETERS : array of levels | number of cells
 */
void display_array_levels(int *number_levels_cell, int NumberOfCells) {
    printf("\n\nLevels :");
    for (int i = 0; i < NumberOfCells; i++) {
        printf("[%d]  ", number_levels_cell[i]);
    }
}