#include "filler_vis.h"

char **free_map(char **map, int height)
{
    while (height != -1)
    {
        map[height] = ft_strdel(&map[height]);
        height--;
    }
    free(map);
    map = NULL;
    return (map);
}

void free_list(step_list** list, int height)
{
    step_list *tmp;

    while (*list)
    {
        tmp = (*list)->next;
        (*list)->map = free_map((*list)->map, height);
        FREE_ELEM(*list);
        *list = tmp;
    }
}

char **create_map(int height)
{
    char *line;
    char **map;
    int i;

    i = 0;
    map = (char **)malloc(sizeof(char *) * (height + 1));
    while (i < height)
    {
        if (get_next_line(0, &line) != 1)
        {
            free_map(map, i - 1);
            return(NULL);
        }
        map[i] = ft_strdup(line + 4);
        line = ft_strdel(&line);
        i++;
    }
    map[i] = NULL;
    return (map);
}

int add_step(step_list** list, int height)
{
    step_list *new_elem;
    step_list *tmp;

    tmp = *list;
    if (*list == NULL)
    {
        new_elem = (step_list *)malloc(sizeof(step_list));
        if(!(new_elem->map = create_map(height)))
        {
            FREE_ELEM(new_elem);
            return(0);
        }
        new_elem->next = NULL;
        new_elem->back = NULL;
        new_elem->height = height;
        *list = new_elem;
        return (1);
    }
    while (tmp->next)
        tmp = tmp->next;
    new_elem = (step_list *)malloc(sizeof(step_list));
    if(!(new_elem->map = create_map(height)))
    {
        FREE_ELEM(new_elem);
        return(0);
    }
    new_elem->height = height;
    new_elem->back = tmp;
    new_elem->next = NULL;
    tmp->next = new_elem;
    return (1);
}

step_list *create_list_step(void)
{
    char *line;
    step_list *list;
    int height;

    height = 0;
    list = NULL;
    line = NULL;
    while (1)
    {
        if (get_next_line(0, &line) != 1)
        {
            free_list(&list, height);
            exit(5);
        }
        else if(line != NULL && ft_strstr(line, "Plateau"))
        {
            height = ft_atoi(line + 8);
            line = ft_strdel(&line);
            if(get_next_line(0, &line) != 1 || add_step(&list, height) != 1)
            {
                free_list(&list, height);
                line = ft_strdel(&line);
                exit(2);
            }
        }
        else if (line != NULL && ft_strstr(line, "fin:"))
        {
            line = ft_strdel(&line);
            break;
        }
        line = ft_strdel(&line);
    }
    return (list);
}