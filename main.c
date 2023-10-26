#include "level_lists.h"
#include <stdio.h>

int main() {
    int max_list_level = 10;
    t_d_list level_list = createList(max_list_level);

    insertCellHead(&level_list, /*value*/ 40, /*nb levels cell*/ 4);
    insertCellHead(&level_list, /*value*/ 30, /*nb levels cell*/ 3);
    insertCellHead(&level_list, /*value*/ 20, /*nb levels cell*/ 2);
    insertCellHead(&level_list, /*value*/ 10, /*nb levels cell*/ 1);

    insertCellAscendingOrder(&level_list, /*value*/ 25, /*number of level of the cell*/ 2,/*nb levels of list*/ max_list_level);

    printEntireList(level_list, max_list_level);

    printf("\n");

    printSpecLevelList(level_list, 1);

    return 0;
}