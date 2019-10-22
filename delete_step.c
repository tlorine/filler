/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_step.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorine <tlorine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 18:55:39 by tlorine           #+#    #+#             */
/*   Updated: 2019/10/22 18:55:40 by tlorine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char **delete_map(char **map, int **map_num)
{
    int i;

    i = 0;
    while (map[i] != NULL)
        i++;
	i--;
    while (i != -1)
    {
       	map[i] = ft_strdel(&map[i]);
		free(map_num[i]);
		map_num[i] = NULL;
        i--;
    }
    free (map);
    map = NULL;
	free (map_num);
   	map_num = NULL;
    return (map);
}

void    delete_step(step **st)
{
    int i;
    figure *tmp;

    i = 0;
    while(((*st)->figure) != NULL)
    {
        tmp = (*st)->figure->next;
        free((*st)->figure);
        (*st)->figure = NULL;
        (*st)->figure = tmp;
    }
	(*st)->map = delete_map((*st)->map, (*st)->map_num);
	(*st)->map_num = NULL;
	free(*st);
	*st = NULL;
	return ;
}