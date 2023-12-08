//
// Created by Marley on 25/10/2023.
//

#include "level_lists.h"
#include "color_management.h"
#include <stdio.h>
#include <math.h>

/*
 *
 * CREATE A LIST with a number of heads
 * PARAMETERS : number of heads
 */
t_d_list createList(int nb_max_head) {

    t_d_list my_ht_list;

    // Initialize the array containing the heads (1 per level)
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
    // Create a temporary pointer of type cell
    t_d_cell *new_cell;
    new_cell = createCell(val, cell_levels);

    // Insert the cell at the head of the list taking into account the number of levels
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

    // Create a temporary pointer of type cell
    t_d_cell *new_cell = createCell(val, level_cell);

    // For each level of the cell, we associate the pointer of the previous cell to the new cell
    for (int i = 0; i < level_cell; i++) {
        t_d_cell **current_head = &(level_list->head_array[i]);

        // As long as we did not reach the right position, we move forward in the list
        while (*current_head != NULL && (*current_head)->value < val) {
            current_head = &((*current_head)->pointer_array[i]);
        }

        // Inserting the cell
        new_cell->pointer_array[i] = *current_head;
        *current_head = new_cell;
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

    // Display the value of each cell of the level until the end of the list
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

    // Display the value of each cell of each level until the end of the list, for each level
    for (int i = 0; i < max_level; i++) {

        printSpecLevelList(level_list, i+1);

        /*t_d_cell *temp = level_list.head_array[i];

        // Display the beginning of level i
        printf("[list head_%d @-]", i+1);

        // Display the values
        while (temp != NULL) {
            printf("-->[ %d|@-]", temp->value);
            temp = temp->pointer_array[i];
        }

        // Display the end of level i
        printf("--> NULL\n");*/
    }
}


/*
 *
 * SIMPLE SEARCH (first level only)
 * PARAMETERS : list | value to search | number of cells of the list
 */
int simple_search(t_d_list level_list, int val, int number_cells) {
    t_d_cell *temp = level_list.head_array[0];

    while (temp != NULL) {
        if (temp->value == val) {           // The value is found
            return 1;
        } else if (temp->value < val) {     // Did not reach the value yet (still smaller)
            temp = temp->pointer_array[0];
        } else {                            // Value not found in the list
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

        while (temp->pointer_array[level] != NULL && temp->value < val) {
            temp = temp->pointer_array[level];
        }


        if (temp->value == val) {
            return 1;
        }

        level--;
        temp = level_list.head_array[level];

        if (level < 0) {
            return 0;
        }

        temp = temp->pointer_array[level];
    }

    return 0;
}


void printAlignedList(t_d_list level_list, int max_level) {
    int tot_values = pow(2, max_level-1)-1;
    for (int level = 0; level < max_level; level++) {
        t_d_cell *temp = level_list.head_array[level];
        t_d_cell *temp0 = level_list.head_array[0];

        printf("[list head_%d @-]", level + 1);
        int j = 0;
        while (temp != NULL) {
            while (level != 0 && temp->value != temp0->value){
                temp0 = temp0->pointer_array[0];
                printf("----------");
            }
            printf("-->[ %d|@-]", temp->value);
            temp = temp->pointer_array[level];
            temp0 = temp0->pointer_array[0];
            j++;
        }
        if (j <= tot_values){
            for (int k = j; k <= tot_values; k++){
                printf("----------");
            }
        }
        printf("--> NULL\n");
    }
}