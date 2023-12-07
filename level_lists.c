//
// Created by Marley on 25/10/2023.
//

#include "level_lists.h"
#include "color_management.h"
#include <stdio.h>

/*
 *
 * CREATE A LIST with a number of heads
 * PARAMETERS : number of heads
 */
t_d_list createList(int nb_max_head) {

    t_d_list my_ht_list;

    for (int i = 0; i < nb_max_head; i++) {
        my_ht_list.head_array[i] = NULL;
    }

    return my_ht_list;
}

/*
 *
 * INSERT A CELL AT THE HEAD OF THE LIST
 * PARAMETERS : list | value | number of levels of the cell
 */
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

/*
 *
 * INSERT A CELL IN ASCENDING ORDER
 * PARAMETERS : list | value | number of levels of the cell | number of levels of the list
 */
void insertCellAscendingOrder(t_d_list *level_list, int val, int level_cell, int list_levels) {

    // Error management
    if (level_cell > list_levels) {
        ErrorColor();
        printf("\n /!\\ Error: nb level of the cell (%d) > nb level of the list (%d)  -->  cannot insert the cell\n\n", level_cell, list_levels);
        NormalColor();
        return;
    }

    t_d_cell *new_cell;
    new_cell = createCell(val, level_cell);

    for (int i = 0; i < level_cell; i++) {

        if (level_list->head_array[i] == NULL) {
            new_cell->pointer_array[0] = NULL;
            level_list->head_array[i] = new_cell;
        } else {
            t_d_cell *temp;
            temp = level_list->head_array[i];

            while (temp->pointer_array[i] != NULL && temp->pointer_array[i]->value < val) {
                temp = temp->pointer_array[i];
            }

            if (temp->value < val) {
                new_cell->pointer_array[i] = temp->pointer_array[i];
                temp->pointer_array[i] = new_cell;
            } else {
                new_cell->pointer_array[i] = temp;
                level_list->head_array[i] = new_cell;
            }
        }
    }
}

/*
 *
 * PRINT A SPECIFIC LEVEL OF THE LIST
 * PARAMETERS : list | level to print
 */
void printSpecLevelList(t_d_list level_list, int level) {

    t_d_cell *temp = level_list.head_array[level-1];

    printf("[list head_%d @-]", level);

    while (temp != NULL) {
        printf("-->[ %d|@-]", temp->value);
        temp = temp->pointer_array[level-1];
    }

    printf("--> NULL\n");
}

/*
 *
 * PRINT THE ENTIRE LIST
 * PARAMETERS : list | number of levels of the list
 */
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


/*
 *
 * SIMPLE DICHOTOMIC SEARCH (first level only)
 * PARAMETERS : list | value to search | number of cells of the list
 */
int simple_dichotomic_search(t_d_list level_list, int val, int number_cells) {
    t_d_cell *temp = level_list.head_array[0];

    while (temp != NULL) {
        if (temp->value == val) {
            return 1;
        }

        if (temp->value < val) {
            temp = temp->pointer_array[0];
        } else {
            return 0;
        }
    }

    return 0;
}

/*
 *
 * DICHOTOMIC SEARCH
 * PARAMETERS : list | value to search | number of levels of the list | number of cells of the list
 */
int dichotomic_search(t_d_list level_list, int val, int max_level, int number_cells) {
    int level = max_level - 1;
    t_d_cell *temp = level_list.head_array[level];

    for (int i = 0; i < number_cells && temp != NULL; i++) {
        if (temp->value == val) {
            return 1;
        }

        while (temp->pointer_array[level] != NULL && temp->pointer_array[level]->value < val) {
            temp = temp->pointer_array[level];
        }

        level--;

        if (level < 0) {
            return 0;
        }

        temp = temp->pointer_array[level];
    }

    return 0;
}
