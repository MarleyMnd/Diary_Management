#include "level_lists.h"

int main() {
    int max_list_level = 5;
    t_d_list level_list = createList(max_list_level);

    insertCellHead(&level_list, /*value*/ 10, /*nb levels cell*/ 1, /*list level to insert in*/1);
    insertCellHead(&level_list, /*value*/ 20, /*nb levels cell*/ 1, /*list level to insert in*/1);
    insertCellHead(&level_list, /*value*/ 30, /*nb levels cell*/ 1, /*list level to insert in*/1);
    insertCellHead(&level_list, /*value*/ 40, /*nb levels cell*/ 1, /*list level to insert in*/1);

    insertCellHead(&level_list, /*value*/ 50, /*nb levels cell*/ 2, /*list level to insert in*/2);
    insertCellHead(&level_list, /*value*/ 60, /*nb levels cell*/ 2, /*list level to insert in*/2);

    insertCellHead(&level_list, /*value*/ 70, /*nb levels cell*/ 3, /*list level to insert in*/3);
    insertCellHead(&level_list, /*value*/ 80, /*nb levels cell*/ 3, /*list level to insert in*/3);
    insertCellHead(&level_list, /*value*/ 90, /*nb levels cell*/ 3, /*list level to insert in*/3);
    insertCellHead(&level_list, /*value*/ 100, /*nb levels cell*/ 3, /*list level to insert in*/3);
    insertCellHead(&level_list, /*value*/ 110, /*nb levels cell*/ 3, /*list level to insert in*/3);
    printList(level_list, max_list_level);

    return 0;
}
