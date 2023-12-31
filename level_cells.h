//
// Created by Marley on 25/10/2023.
//

#ifndef DIARY_MANAGEMENT_PROJECT_LEVEL_CELLS_H
#define DIARY_MANAGEMENT_PROJECT_LEVEL_CELLS_H

#define MAX_SIZE 30

/*
 *
 * CELL STRUCTURE
 * ARGUMENTS : value | pointer array
 */
typedef struct s_d_cell
{
    int value;
    struct s_d_cell *pointer_array[MAX_SIZE];
} t_d_cell;

t_d_cell *createCell(int, int);

int *initialize_array_values(int);

void display_array_values(int*, int);

int *initialize_array_levels(int);

void display_array_levels(int*, int);

#endif //DIARY_MANAGEMENT_PROJECT_LEVEL_CELLS_H