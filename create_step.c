/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_step.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorine <tlorine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 18:55:31 by tlorine           #+#    #+#             */
/*   Updated: 2019/10/22 18:55:33 by tlorine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void create_new_elem(figure **fg, int y, int x, char ch)
{
	figure *tmp;

	tmp = *fg;
	if (tmp == NULL)
	{
		*fg = (figure *)malloc(sizeof(figure));
		(*fg)->x = x;
		(*fg)->y = y;
		(*fg)->ch = ch;
		(*fg)->next = NULL;
		return ;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = (figure *)malloc(sizeof(figure));
	tmp = tmp->next;
	tmp->x = x;
	tmp->y = y;
	tmp->ch = ch;
	tmp->next = NULL;
}

figure *figure_init(step *st)
{
    char *line;
	int width;
	int height;
	int i;
	int y;
	char tmp;
	figure *fg;

	fg = NULL;
	while(get_next_line(0, &line))
	{
		if (ft_strstr(line, "Piece") != NULL)
			break;
		line = ft_strdel(&line);
	}
	st->figure_height = ft_atoi(line +  6);
	st->figure_width = ft_atoi(line + (st->figure_height >= 10 ? 8 : 7));
	line = ft_strdel(&line);
	y = 0;
    while (y < st->figure_height)
	{
		i = 0;
		get_next_line(0, &line);
        while (line[i] != '\0' && (line[0] == '.' || line[0] == '*'))
		{
			create_new_elem(&fg, y, i, line[i]);
			i++;
		}
		line = ft_strdel(&line);
		y++;
	}
	return (fg);
}

step *create_step(game_info *ginf)
{
	int i;
	char *line;
	step *new_step;

	i = 0;
	new_step = (step *)malloc(sizeof(step));
	new_step->map = (char **)malloc(sizeof(char *) * (ginf->map_y + 1));
	while (get_next_line(0, &line))
	{
		if((ft_strstr(line, "   0")) != NULL)
			break;
		line = ft_strdel(&line);
	}
	line = ft_strdel(&line);
	while (i < ginf->map_y)
	{
		get_next_line(0, &line);
		if (line[0] >= '0' && line[0] <= '9')
		{
			new_step->map[i] = ft_strdup(line + 4);
			line = ft_strdel(&line);
			i++;
		}
	}
	new_step->map[i] = NULL;
	new_step->figure = figure_init(new_step);
	return(new_step);
}
