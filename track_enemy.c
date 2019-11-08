/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   track_enemy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorine <tlorine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 18:56:11 by tlorine           #+#    #+#             */
/*   Updated: 2019/10/29 15:44:26 by tlorine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	mark_track(int x, int y, int **map, int c)
{
	if (x > 0 && map[y][x - 1] == POINT)
		map[y][x - 1] = c;
	if (map[y][x + 1] != END_AR && map[y][x + 1] == POINT)
		map[y][x + 1] = c;
	if (y > 0 && map)
	{
		if (map[y - 1][x] == POINT)
			map[y - 1][x] = c;
		if (x > 0 && map[y - 1][x - 1] == POINT)
			map[y - 1][x - 1] = c;
		if (map[y - 1][x + 1] != END_AR && map[y - 1][x + 1] == POINT)
			map[y - 1][x + 1] = c;
	}
	if (map[y + 1] != NULL)
	{
		if (map[y + 1][x] == POINT)
			map[y + 1][x] = c;
		if (x > 0 && map[y + 1][x - 1] == POINT)
			map[y + 1][x - 1] = c;
		if (map[y + 1][x + 1] != END_AR && map[y + 1][x + 1] == POINT)
			map[y + 1][x + 1] = c;
	}
}

void	fill_ar(int **map)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x] != END_AR)
		{
			if (map[y][x] == POINT)
				map[y][x] = 1;
			x++;
		}
		y++;
	}
}

void	get_direction(int **map, int hang)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (hang > 0)
	{
		while (map[y])
		{
			while (map[y][x] != END_AR)
			{
				if (map[y][x] == hang)
					mark_track(x, y, map, hang - 1);
				x++;
			}
			y++;
			x = 0;
		}
		hang--;
		y = 0;
	}
	fill_ar(map);
}

void	track_enemy(t_step *stp, t_game_info *gf)
{
	int	enemy;
	int	x;
	int	y;

	x = 0;
	y = 0;
	enemy = gf->player == 1 ? X : O;
	while (stp->map_num[y] && stp->map_num[y][x] != END_AR)
	{
		if (stp->map_num[y][x] != END_AR && (stp->map_num[y][x] == enemy))
			mark_track(x, y, stp->map_num, (gf->map_x + gf->map_y) * 2);
		x++;
		if (stp->map_num[y] && stp->map_num[y][x] == END_AR)
		{
			y++;
			x = 0;
		}
	}
	get_direction(stp->map_num, (gf->map_x + gf->map_y) * 2);
}
