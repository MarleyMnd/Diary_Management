#include "level_lists.h"
#include <stdio.h>
#include <math.h>
#include "timer.h"
#include <unistd.h>

/*
 * Test with predefined values
 */
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

    // Create an array of random values + display
    int values[3000] = {};
    for (int i = 0; i < NumberOfCells; i++) {
        values[i] = i;
    }

    // Change the seed of 'random' generation (based on time)
    sleep(1);

    // Create an array of random number for the levels for the cells + display
    int number_levels_cell[3000] = {};
    for (int i = 0; i < NumberOfCells; i++) {
        number_levels_cell[i] = 0;
    }
    for (int k = 2; k <= NumberOfCells/2 + 1; k = k*2) {
        for (int i = k - 1; i <= NumberOfCells-k; i=i+k) {
            if (i % 2 == 1 ) {
                number_levels_cell[i]++;
            }
        }
    }

    sleep(1);
    printf("Values of the list :");
    for (int i = 0; i < NumberOfCells; i++) {
        printf("[%d]  ", values[i]);
    }
    printf("\n\nLevels :");
    for (int i = 0; i < NumberOfCells; i++) {
        printf("[%d]  ", number_levels_cell[i]);
    }
    printf("\n\n");

    // Create the first cell of the list
    insertCellHead(&level_list, /*value*/ values[0]+1, /*number of levels of the cell*/ number_levels_cell[0]+1);

    printf("Head inserted.\n\n");

    // Change the seed of 'random' generation (based on time)
    sleep(1);

    int j = 1;
    for (int i = 1; i < NumberOfCells; i++) {
        insertCellAscendingOrder(&level_list, /*value*/ values[j], /*number of level of the cell*/ number_levels_cell[i]+1, max_list_level);
        j++;
    }
    printf("Insertion finished.\n\n");

    sleep(2);

    printEntireList(level_list, max_list_level);

    startTimer();
    int is_found = dichotomic_search(level_list, 8, max_list_level, NumberOfCells);
    sleep(1);
    stopTimer();

    if (is_found == 1) {
        printf("\n\nThe value is found.\n");
    } else {
        printf("\n\nThe value is not found.\n");
    }
    printf("Time taken: ");
    displayTime();

    startTimer();
    int is_found2 = simple_dichotomic_search(level_list, 12, NumberOfCells);
    sleep(1);
    stopTimer();

    if (is_found2 == 1) {
        printf("\nThe value is found in first line.\n");
    } else {
        printf("\nThe value is not found in first line.\n");
    }
    printf("Time taken: ");

    displayTime();

    return 0;

}
