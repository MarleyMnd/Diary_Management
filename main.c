#include "level_lists.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "timer.h"
#include "windows.h"

/*
 * Test with random values
 */
// int main() {
//     // MAX LEVEL = 9 /!\ do not exceed
//     int max_list_level;
//     printf("Enter the max number of levels of the list :");
//     scanf("%d", &max_list_level);
//     printf("\n");
//
//     int NumberOfCells = pow(2,max_list_level) - 1;
//
//     t_d_list level_list = createList(max_list_level);
//
//     srand(time(NULL));
//     int values[1000] = {};
//     for (int i = 0; i < NumberOfCells; i++) {
//         values[i] = rand() % 100;
//     }
//     printf("Values of the list :");
//     for (int i = 0; i < NumberOfCells; i++) {
//         printf("[%d]  ", values[i]);
//     }
//     printf("\n\n");
//
//     srand(time(NULL));
//     int number_levels_first_cell = rand() % max_list_level + 1;
//     insertCellHead(&level_list, /*value*/ values[0], /*number of levels of the cell*/ number_levels_first_cell);
//
//     int j = 1;
//     int number_levels_cell[1000] = {};
//     for (int i = 0; i < NumberOfCells; i++) {
//         number_levels_cell[i] = rand() % max_list_level + 1;
//     }
//     printf("Number of levels of the cells :");
//     for (int i = 0; i < NumberOfCells; i++) {
//         printf("[%d]  ", number_levels_cell[i]);
//     }
//     printf("\n\n");
//     for (int i = 1; i < NumberOfCells; i++) {
//         insertCellAscendingOrder(&level_list, /*value*/ values[j], /*number of level of the cell*/ number_levels_cell[i], max_list_level);
//         j++;
//     }
//
//     printEntireList(level_list, max_list_level);
//
//     int is_found = dichotomic_search(level_list, 51, max_list_level, NumberOfCells);
//     if (is_found == 1) {
//         printf("\n\nThe value is found\n");
//     } else {
//         printf("\n\nThe value is not found\n");
//     }
//
//     return 0;
// }


/*
 * Test with predefined values
 */
int main() {
    int max_list_level;
    printf("Enter the max number of levels of the list :");
    scanf("%d", &max_list_level);

    int NumberOfCells = pow(2,max_list_level) - 1;
    printf("Number of cells : %d\n\n", NumberOfCells);

    t_d_list level_list = createList(max_list_level);

    int values[100] = {};
    srand(time(NULL));
    for (int i = 0; i < NumberOfCells; i++) {
        values[i] = rand() % 100;
    }
    printf("Values of the list :");
    for (int i = 0; i < NumberOfCells; i++) {
        printf("[%d]  ", values[i]);
    }
    printf("\n\n");

    int number_levels_first_cell = 5;
    insertCellHead(&level_list, /*value*/ values[0], /*number of levels of the cell*/ number_levels_first_cell);

    int number_levels_cell[100] = {};
    srand(time(NULL));
    for (int i = 0; i < NumberOfCells; i++) {
        number_levels_cell[i] = rand() % max_list_level + 1;
    }
    printf("Number of levels of the cells :");
    for (int i = 0; i < NumberOfCells; i++) {
        printf("[%d]  ", number_levels_cell[i]);
    }
    printf("\n\n");

    int j = 1;
    for (int i = 1; i < NumberOfCells; i++) {
        insertCellAscendingOrder(&level_list, /*value*/ values[j], /*number of level of the cell*/ number_levels_cell[i], max_list_level);
        j++;
    }
    printEntireList(level_list, max_list_level);

    startTimer();
    int is_found = dichotomic_search(level_list, 4, max_list_level, NumberOfCells);
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
    int is_found2 = simple_dichotomic_search(level_list, 55, NumberOfCells);
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