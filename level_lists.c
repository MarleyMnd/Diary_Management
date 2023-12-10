//
// Created by Marley on 25/10/2023.
//

#include "level_lists.h"
#include "color_management.h"
#include "timer.h"
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
    // Create a new cell
    t_d_cell *new_cell;
    new_cell = createCell(val, cell_levels);

    // Insert the cell at the head of the list taking into account the number of levels
    for (int i = 0; i < cell_levels; i++) {

        if (level_list->head_array[i] == NULL) {
            new_cell->pointer_array[i] = NULL;
            level_list->head_array[i] = new_cell;
        } else {
            // Condition above always reached if the list is empty (i.e. if the head is NULL)
            // Unnecessary else statement
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

    // Error management (condition never achieved anyway)
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

    // Display the number of the level
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
    }
}

/*
 *
 * PRINT THE ENTIRE LIST ALIGNED
 * PARAMETERS : list | number of levels of the list
 */
void printAlignedList(t_d_list level_list, int max_level) {
    // Determine the number of cells in the list
    int tot_values = pow(2, max_level-1) - 1;

    for (int level = 0; level < max_level; level++) {

        // Initialize the temporary pointers
        // First pointer at the head of the current level
        t_d_cell *temp = level_list.head_array[level];
        // Second pointer at the head of the first level
        t_d_cell *temp0 = level_list.head_array[0];

        printf("[list head_%d @-]", level + 1);
        int j = 0;
        while (temp != NULL) {

            // As long as the value pointed by the first pointer is not the same as the value pointed by the second
            // pointer, we print dashes to align the values
            while (level != 0 && temp->value != temp0->value){
                temp0 = temp0->pointer_array[0];
                printf("----------");
            }

            // When values are equal, we print the value
            printf("-->[ %d|@-]", temp->value);
            temp = temp->pointer_array[level];
            temp0 = temp0->pointer_array[0];
            j++;
        }

        // Final alignment
        if (j <= tot_values){
            for (int k = j; k <= tot_values; k++){
                printf("----------");
            }
        }

        printf("--> NULL\n");
    }
}


/*
 *
 * SIMPLE SEARCH (first level only)
 * PARAMETERS : list | value to search | number of cells of the list
 */
int simple_search(t_d_list level_list, int val) {
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
int dichotomic_search(t_d_list level_list, int val, int max_level) {
    // Start the search at the deepest level
    int level = max_level - 1;
    t_d_cell *temp = level_list.head_array[level];

    // We iterate over the cells of the list until the value is found or until we reach the end of the list
    while (temp->value != val && level >= 0) {

        // Check the relation between the value pointed by the pointer and the value we are looking for
        // Either the value is before the cell pointed by the pointer in the list, or after
        if (temp->value < val) {

            // Check if the next cell of the level above is greater than the value we are looking for
            if (temp->pointer_array[level-1]->value > val) {
                // If so, we go up one level (if the value is the value we're looking for, the while loop would have already stopped)
                level--;
            } else {
                // Else, we go to the next cell of the level above
                temp = temp->pointer_array[--level];
            }
        } else {
            // The value is before the cell pointed by the pointer in the list : we go to the head of the level above
            temp = level_list.head_array[--level];
        }
    }

    // Either the value is found, or we reached the end of the seeking process
    if (temp->value == val) {
        return 1;
    } else if (temp->pointer_array[level] == NULL || level < 0) {
        return 0;
    }
    return -2;
}

/*
 *
 * TEST DICHOTOMY
 * PARAMETERS : list | value to search | number of levels of the list | number of searches
 */
void test_dichotomy(t_d_list level_list, int ValueToFind, int max_list_level, int nb_search) {
    int is_found;
    startTimer();
    for (int i = 0; i < nb_search; i++) {
        is_found = dichotomic_search(level_list, ValueToFind, max_list_level);
    }
    stopTimer();

    if (is_found == -2) {
        printf("\n\nDichotomic search : Error\n");
    } else if (is_found == 1){
        printf("\n\nDichotomic search : The value %d is found.\n", ValueToFind);
    } else {
        printf("\n\nDichotomic search : The value %d is not found.\n", ValueToFind);
    }
    printf("Time taken to search %d times: ", nb_search);

    AccentuationColor();
    displayTime();
    NormalColor();
}

/*
 *
 * TEST SIMPLE SEARCH
 * PARAMETERS : list | value to search | number of searches
 */
void test_simple_search(t_d_list level_list, int ValueToFind, int nb_search) {
    int is_found2;

    // Start the timer
    startTimer();

    for (int i = 0; i < nb_search; i++) {
        is_found2 = simple_search(level_list, ValueToFind);
    }

    // Stop the timer
    stopTimer();

    if (is_found2 == 1) {
        printf("\nLinear search : The value %d is found in first line.\n", ValueToFind);
    } else {
        printf("\nLinear search : The value %d is not found in first line.\n", ValueToFind);
    }
    printf("Time taken to search %d times: ", nb_search);

    // Display the time taken to perform the search
    AccentuationColor();
    displayTime();
    NormalColor();
}