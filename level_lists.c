//
// Created by Marley on 25/10/2023.
//

#include "level_lists.h"
#include <stdio.h>

t_d_list createList(int nb_head) {

    t_d_list my_ht_list;

    for (int i = 0; i < nb_head; i++) {
        my_ht_list.head_array[i] = NULL;
    }

    return my_ht_list;
}