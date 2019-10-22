#ifndef FILLER_VIS_H
#define FILLER_VIS_H

#include "../libft/libft.h"
#include "stdlib.h"

#define FREE_ELEM(x) free(x), x = NULL

typedef struct l_step_list
{
    char **map;
    int height;
    struct l_step_list *next;
    struct l_step_list *back;
}               step_list;

void free_list(step_list** list, int height);
step_list *create_list_step(void);

/*
**  tmp_function
*/

void write_game(step_list *list);
void write_game_back(step_list *list);

#endif