#include "level_lists.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main() {
    srand(time(NULL));

    int max_list_level;
    printf("Enter the max number of levels of the list : ");
    scanf("%d", &max_list_level);
    printf("\n");

    int NumberOfCells;
    printf("Enter the number of cells of your level list : ");
    scanf("%d", &NumberOfCells);
    printf("\n");

    t_d_list level_list = createList(max_list_level);

    int value_first_cell = rand() % 100;
    insertCellHead(&level_list, /*value*/ value_first_cell, /*number of levels of the cell*/ rand() % max_list_level);

    for (int i = 1; i < NumberOfCells; i++) {
        int value = rand() % 100;
        insertCellAscendingOrder(&level_list, /*value*/ value, /*number of level of the cell*/ rand() % max_list_level, max_list_level);
    }

    printEntireList(level_list, max_list_level);

    printf("\n");

    return 0;
}
