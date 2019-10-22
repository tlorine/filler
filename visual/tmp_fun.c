#include "filler_vis.h"

void write_game(step_list *list)
{
    int y;

    y = 0;
    while (list)
    {
        ft_putendl("\n--------------------------");
        while (list->map[y])
        {
            ft_putendl(list->map[y]);
            y++;
        }
        ft_putendl("--------------------------\n\n\n");
        y = 0;
        list = list->next;
    }
}

void write_game_back(step_list *list)
{
    int y;

    y = 0;
    while(list->next)
        list = list->next;
    while (list)
    {
        ft_putendl("\n--------------------------");
        while (list->map[y])
        {
            ft_putendl(list->map[y]);
            y++;
        }
        ft_putendl("--------------------------\n\n\n");
        y = 0;
        list = list->back;
    }
}