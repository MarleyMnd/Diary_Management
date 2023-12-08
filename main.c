#include "level_lists.h"
#include <stdio.h>
#include <math.h>
#include "timer.h"
#include <unistd.h>

int main() {
    // Choose maximum depth of the list
    int max_list_level;
    printf("Enter the max number of levels of the list :");
    scanf("%d", &max_list_level);

    // Determine the number of cells of the list
    int NumberOfCells = pow(2,max_list_level) - 1;
    printf("Number of cells : %d\n\n", NumberOfCells);

    // Create the list (empty)
    t_d_list level_list = createList(max_list_level);

    // Create an array of random values
    int *values = initialize_array_values(NumberOfCells);

    // Create an array of random number for the levels for the cells
    int *number_levels_cell = initialize_array_levels(NumberOfCells);

    sleep(1);

    // Display the values and the levels of the cells
    // display_array_values(values, NumberOfCells);
    // display_array_levels(number_levels_cell, NumberOfCells);

    printf("\n\n");

    // Create + insert the first cell of the list
    insertCellHead(&level_list, /*value*/ values[0]+1, /*number of levels of the cell*/ number_levels_cell[0]+1);

    printf("Head inserted.\n\n");

    for (int i = 1; i < NumberOfCells; i++) {
        insertCellAscendingOrder(&level_list, /*value*/ values[i]+1, /*number of level of the cell*/ number_levels_cell[i]+1, max_list_level);
    }
    printf("Insertion finished.\n\n");

    sleep(1);

    /*printf("Not aligned format :\n");
    printEntireList(level_list, max_list_level);

    printf("\n\n");

    printf("Aligned format :\n");
    printAlignedList(level_list, max_list_level);*/

    int ValueToFind;
    printf("Enter the value to find :");
    scanf("%d", &ValueToFind);

    int is_found;
    int nb_search = 10000;
    startTimer();
    for (int i = 0; i < nb_search; i++) {
        is_found = dichotomic_search(level_list, ValueToFind, max_list_level, NumberOfCells);
    }
    stopTimer();

    if (is_found == 1) {
        printf("\n\nDichotomic search : The value %d is found.\n", ValueToFind);
    } else {
        printf("\n\nDichotomic search : The value %d is not found.\n", ValueToFind);
    }
    printf("Time taken: ");
    displayTime();

    int is_found2;
    startTimer();
    for (int i = 0; i < nb_search; i++) {
        is_found2 = simple_search(level_list, ValueToFind, NumberOfCells);
    }
    stopTimer();

    if (is_found2 == 1) {
        printf("\nSimple search : The value %d is found in first line.\n", ValueToFind);
    } else {
        printf("\nSimple search : The value %d is not found in first line.\n", ValueToFind);
    }
    printf("Time taken: ");
    displayTime();

    return 0;

}