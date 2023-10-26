//
// Created by Marley on 25/10/2023.
//

#include "level_lists.h"
#include <stdio.h>

t_d_list createList(int nb_max_head) {

    t_d_list my_ht_list;

    for (int i = 0; i < nb_max_head; i++) {
        my_ht_list.head_array[i] = NULL;
    }

    return my_ht_list;
}


void insertCellHead(t_d_list *level_list, int val, int cell_levels) {
    t_d_cell *new_cell;
    new_cell = createCell(val, cell_levels);

    for (int i = 0; i < cell_levels; i++) {

        if (level_list->head_array[i] == NULL) {
            new_cell->pointer_array[i] = NULL;
            level_list->head_array[i] = new_cell;
        } else {
            new_cell->pointer_array[i] = level_list->head_array[i];
            level_list->head_array[i] = new_cell;
        }
    }
}


void printSpecLevelList(t_d_list level_list, int level) {

    t_d_cell *temp = level_list.head_array[level-1];

    printf("[list head_%d @-]", level);

    while (temp != NULL) {
        printf("-->[ %d|@-]", temp->value);
        temp = temp->pointer_array[level-1];
    }

    printf("--> NULL\n");
}


void printEntireList(t_d_list level_list, int max_level) {

    for (int i = 0; i < max_level; i++) {
        t_d_cell *temp = level_list.head_array[i];

        printf("[list head_%d @-]", i+1);

        while (temp != NULL) {
            printf("-->[ %d|@-]", temp->value);
            temp = temp->pointer_array[i];
        }

        printf("--> NULL\n");
    }
}
