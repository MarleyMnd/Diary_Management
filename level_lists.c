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

void insertCellHead(t_d_list *level_list, int val, int cell_levels, int insertion_level) {
    t_d_cell *new_cell;
    new_cell = createCell(val, cell_levels);

    if (level_list->head_array[insertion_level - 1] == NULL) {
        level_list->head_array[insertion_level - 1] = new_cell;
    } else {
        t_d_cell *temp = level_list->head_array[insertion_level - 1];
        level_list->head_array[insertion_level - 1] = new_cell;
        new_cell->pointer_array[insertion_level - 1] = temp;
    }
}

void printList(t_d_list level_list, int max_level) {

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