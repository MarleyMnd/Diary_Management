//
// Created by Marley on 25/10/2023.
//

#ifndef DIARY_MANAGEMENT_PROJECT_LEVEL_LISTS_H
#define DIARY_MANAGEMENT_PROJECT_LEVEL_LISTS_H

#include "level_cells.h"
#define MAX_SIZE 50

typedef struct s_d_list
{
    t_d_cell *head_array[MAX_SIZE];
} t_d_list;

t_d_list createList(int);

void insertCellHead(t_d_list *, int, int);

void printEntireList(t_d_list level_list, int max_level);

void printSpecLevelList(t_d_list, int);

void insertCellAscendingOrder(t_d_list *, int, int, int);

#endif //DIARY_MANAGEMENT_PROJECT_LEVEL_LISTS_H