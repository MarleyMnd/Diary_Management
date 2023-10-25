#include <stdio.h>
#include "level_cells.h"
#include "level_lists.h"

int main() {

    t_d_list level_list;
    level_list = createList(2);

    t_d_cell *new_cell;

    new_cell = createCell(4, 3);

    return 0;
}
