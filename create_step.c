/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_step.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorine <tlorine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 18:55:31 by tlorine           #+#    #+#             */
/*   Updated: 2019/10/29 15:37:33 by tlorine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		create_new_elem(t_figure **fg, int y, int x, char ch)
{
	t_figure *tmp;

	tmp = *fg;
	if (tmp == NULL)
	{
		*fg = (t_figure *)malloc(sizeof(t_figure));
		(*fg)->x = x;
		(*fg)->y = y;
		(*fg)->ch = ch;
		(*fg)->next = NULL;
		return ;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = (t_figure *)malloc(sizeof(t_figure));
	tmp = tmp->next;
	tmp->x = x;
	tmp->y = y;
	tmp->ch = ch;
	tmp->next = NULL;
}

t_figure	*create_figur(t_step *st)
{
	t_figure	*fg;
	char		*line;
	int			y;
	int			i;

	fg = NULL;
	y = 0;
	i = 0;
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

t_figure	*figure_init(t_step *st)
{
	char	*line;

	while (get_next_line(0, &line))
	{
		if (ft_strstr(line, "Piece") != NULL)
			break ;
		line = ft_strdel(&line);
	}
	st->figure_height = ft_atoi(line + 6);
	st->figure_width = ft_atoi(line + (st->figure_height >= 10 ? 8 : 7));
	line = ft_strdel(&line);
	return (create_figur(st));
}

int			**num_map(t_game_info *gf)
{
	t_nm nm;

	nm.y = 0;
	nm.x = 0;
	nm.line = NULL;
	nm.map_num = (int **)malloc(sizeof(int *) * (gf->map_y + 1));
	while (nm.y < gf->map_y)
	{
		get_next_line(0, &nm.line);
		nm.map_num[nm.y] = (int *)malloc(sizeof(int) * (gf->map_x + 1));
		while (nm.line[nm.x + 4] != '\0')
		{
			if (nm.line[nm.x + 4] == 'X' || nm.line[nm.x + 4] == 'x')
				nm.map_num[nm.y][nm.x] = X;
			else
				nm.map_num[nm.y][nm.x] = nm.line[nm.x + 4] == '.' ? POINT : O;
			nm.x++;
		}
		nm.map_num[nm.y][nm.x] = END_AR;
		nm.line = ft_strdel(&nm.line);
		nm.y++;
		nm.x = 0;
	}
	nm.map_num[nm.y] = NULL;
	return (nm.map_num);
}

t_step		*create_step(t_game_info *ginf)
{
	int		i;
	char	*line;
	t_step	*new_step;

	i = 0;
	new_step = (t_step *)malloc(sizeof(t_step));
	get_next_line(0, &line);
	line = ft_strdel(&line);
	new_step->map_num = num_map(ginf);
	new_step->figure = figure_init(new_step);
	return (new_step);
}
