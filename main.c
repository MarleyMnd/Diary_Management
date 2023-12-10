#include "level_lists.h"
#include "color_management.h"
#include <stdio.h>
#include <math.h>
#include <unistd.h>

int main() {
    // Choose maximum depth of the list + make sure it is greater than 0 and smaller than 15
    int max_list_level = 0;
    while (max_list_level <= 0) {
        printf("Enter the max number of levels of the list (1-15 max. recommended):");
        scanf("%d", &max_list_level);
    }

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

    // Display the values and the levels of the cells if the user wants
    int display_arrays;
    printf("Display arrays (value / level) ? ");
    AccentuationColor();
    printf("(Y:1/N:0)\n");
    NormalColor();
    scanf("%d", &display_arrays);
    if (display_arrays == 1) {
        printf("\n");
        display_array_values(values, NumberOfCells);
        display_array_levels(number_levels_cell, NumberOfCells);
        printf("\n");
    }

    printf("\n");

    // Create + insert the first cell of the list
    insertCellHead(&level_list, /*value*/ values[0]+1, /*number of levels of the cell*/ number_levels_cell[0]+1);

    printf("Head inserted.\n");

    for (int i = 1; i < NumberOfCells; i++) {
        insertCellAscendingOrder(&level_list, /*value*/ values[i]+1, /*number of level of the cell*/ number_levels_cell[i]+1, max_list_level);
    }
    printf("Insertion finished.\n\n");

    // Choose the format of the list to display (none, aligned, not aligned)
    int print_option;
    printf("Formats : \n");
    AccentuationColor();
    printf("0. ");
    NormalColor();
    printf("Do not display the list \n");
    AccentuationColor();
    printf("1. ");
    NormalColor();
    printf("Aligned \n");
    AccentuationColor();
    printf("2. ");
    NormalColor();
    printf("Not aligned\n");
    scanf("%d", &print_option);
    printf("\n");

    if (print_option == 0) {
        printf("List not displayed.\n");
    } else if (print_option == 1) {
        printAlignedList(level_list, max_list_level);
    } else if (print_option == 2) {
        printEntireList(level_list, max_list_level);
    } else {
        printf("Wrong option.\n");
        printf("Default: List not displayed.\n");
    }

    printf("\n");

    int ValueToFind;
    printf("Enter the value to find :");
    scanf("%d", &ValueToFind);

    // Choose the number of searches to perform
    int nb_search1, nb_search2, nb_search3;
    printf("Number of searches to perform (first, second, third attempt) :\n");
    scanf("%d %d %d", &nb_search1, &nb_search2, &nb_search3);

    // First attempt
    test_dichotomy(level_list, ValueToFind, max_list_level, nb_search1);
    test_simple_search(level_list, ValueToFind, nb_search1);

    // Second attempt
    test_dichotomy(level_list, ValueToFind, max_list_level, nb_search2);
    test_simple_search(level_list, ValueToFind, nb_search2);

    // Third attempt
    test_dichotomy(level_list, ValueToFind, max_list_level, nb_search3);
    test_simple_search(level_list, ValueToFind, nb_search3);

    return 0;
}