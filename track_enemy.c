/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   track_enemy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorine <tlorine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 18:56:11 by tlorine           #+#    #+#             */
/*   Updated: 2019/10/22 18:56:12 by tlorine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void mark_track(int x, int y, int **map, int c)
{
	if (x > 0 && map[y][x - 1] == POINT)
		map[y][x - 1] = c;
	if (map[y][x + 1] != END_AR && map[y][x + 1] == POINT)
		map[y][x + 1] = c;
	if (y > 0 && map)
	{
		if (map[y - 1][x] == POINT)
			map[y - 1][x] = c;
		if (x > 0 && map[y - 1][x -1] == POINT)
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

void get_direction(int **map, int hang)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (hang > 0)
	{
		while(map[y])
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
	while(map[y])
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

int **num_map(char **map_ch, game_info *gf)
{
	int x;
	int y;
	int **map_num;

	y = 0;
	x = 0;
	map_num = (int **)malloc(sizeof(int *) * (gf->map_y + 1));
	while(map_ch[y])
	{
		map_num[y] = (int *)malloc(sizeof(int) * (ft_strlen(map_ch[y]) + 1));
		while (map_ch[y][x] != '\0')
		{
			if (map_ch[y][x] == 'X' || map_ch[y][x] == 'x')
				map_num[y][x] = X;
			else if (map_ch[y][x] == 'O' || map_ch[y][x] == 'o')
				map_num[y][x] = O;
			else
				map_num[y][x] = POINT;
			x++;
		}
		map_num[y][x] = END_AR;
		y++;
		x = 0;
	}
	map_num[y] = NULL;
	return (map_num);
}
void track_enemy(step *stp, game_info *gf)
{
	int enemy;
	int x;
	int y;

	x = 0;
	y = 0;
	enemy = gf->player == 1 ? X : O;
	stp->map_num = num_map(stp->map, gf);
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
	//test
	// int fd = open("test.txt", O_RDWR | O_TRUNC);
	// y = 0;
	// x = 0;
	// while (stp->map_num[y] != NULL)
	// {
	// 	while (stp->map_num[y][x] != END_AR)
	// 	{
	// 		ft_putnbr_fd(stp->map_num[y][x], fd);
	// 		ft_putchar_fd(' ', fd);
	// 		x++;
	// 	}
	// 	ft_putnbr_fd(stp->map_num[y][x], fd);
	// 	ft_putchar_fd('\n', fd);
	// 	y++;
	// 	x = 0;
	// }
	// close(fd);
}