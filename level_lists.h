//
// Created by Marley on 25/10/2023.
//

#ifndef DIARY_MANAGEMENT_PROJECT_LEVEL_LISTS_H
#define DIARY_MANAGEMENT_PROJECT_LEVEL_LISTS_H

#include "level_cells.h"

typedef struct s_d_list
{
    t_d_cell *head_array[MAX_SIZE];
} t_d_list;

t_d_list createList(int);

#endif //DIARY_MANAGEMENT_PROJECT_LEVEL_LISTS_H
