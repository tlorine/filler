/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_step.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorine <tlorine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 18:55:39 by tlorine           #+#    #+#             */
/*   Updated: 2019/10/29 15:37:39 by tlorine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int				**delete_map(int **map_num)
{
	int i;

	i = 0;
	while (map_num[i] != NULL)
		i++;
	i--;
	while (i != -1)
	{
		free(map_num[i]);
		map_num[i] = NULL;
		i--;
	}
	free(map_num);
	map_num = NULL;
	return (map_num);
}

void			delete_step(t_step **st)
{
	t_figure	*tmp;
	int			i;

	i = 0;
	while (((*st)->figure) != NULL)
	{
		tmp = (*st)->figure->next;
		free((*st)->figure);
		(*st)->figure = NULL;
		(*st)->figure = tmp;
	}
	(*st)->map_num = delete_map((*st)->map_num);
	free(*st);
	*st = NULL;
	return ;
}
