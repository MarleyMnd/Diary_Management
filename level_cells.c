//
// Created by Marley on 25/10/2023.
//

#include <stdio.h>
#include <malloc.h>
#include "level_cells.h"

t_d_cell *createCell(int val, int levels) {

    t_d_cell *new_cell;

    new_cell = (t_d_cell*) malloc(1*sizeof(t_d_cell));
    new_cell->value = val;

    for (int i = 0; i < levels; i++) {
        new_cell->pointer_array[i] = NULL;
    }

    return new_cell;
}
