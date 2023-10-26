#include "level_lists.h"

int main() {
    int max_list_level = 10;
    t_d_list level_list = createList(max_list_level);

    insertCellHead(&level_list, /*value*/ 10, /*nb levels cell*/ 4);
    insertCellHead(&level_list, /*value*/ 20, /*nb levels cell*/ 3);
    insertCellHead(&level_list, /*value*/ 30, /*nb levels cell*/ 2);
    insertCellHead(&level_list, /*value*/ 40, /*nb levels cell*/ 1);

    printList(level_list, max_list_level);

    return 0;
}