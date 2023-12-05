#include "level_lists.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int max_list_level;
    printf("Enter the max number of levels of the list : ");
    scanf("%d", &max_list_level);
    printf("\n");

    int NumberOfCells;
    printf("Enter the number of cells of your level list : ");
    scanf("%d", &NumberOfCells);
    printf("\n");

    t_d_list level_list = createList(max_list_level);

    srand(time(NULL));
    int values[10] = {};
    for (int i = 0; i < NumberOfCells; i++) {
        values[i] = rand() % 100;
    }
    printf("Values :");
    for (int i = 0; i < NumberOfCells; i++) {
        printf("[%d]  ", values[i]);
    }
    printf("\n\n");

    srand(time(NULL));
    int number_levels_first_cell = rand() % max_list_level + 1;
    insertCellHead(&level_list, /*value*/ values[0], /*number of levels of the cell*/ number_levels_first_cell);

    int j = 1;
    for (int i = 1; i < NumberOfCells; i++) {
        insertCellAscendingOrder(&level_list, /*value*/ values[j], /*number of level of the cell*/ 2, max_list_level);
        j++;
    }

    printEntireList(level_list, max_list_level);

    printf("\n");

    return 0;
}
