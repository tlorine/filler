/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attack_enemy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorine <tlorine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 18:55:24 by tlorine           #+#    #+#             */
/*   Updated: 2019/10/22 18:55:25 by tlorine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	init_cor(coords *cor, step *stp, game_info *gf)
{
	int y;
	int x;

	y = 0;
	x = 0;
	cor->x = -1;
    cor->y = -1;
	while (stp->map_num[y] && stp->map_num[y][x] != stp->player)
	{
		x = 0;
		while (stp->map_num[y][x] != END_AR && stp->map_num[y][x] != stp->player)
			x++;
		y++;
	}
	if (gf->map_y / 2 < y)
		cor->poz = 2;
	else
		cor->poz = 1;
}

int	chech_valid(int x, int y, step *stp)
{
	figure *tmp;
	int i;

	i = 0;
	tmp = stp->figure;
	while (tmp)
	{
		if (stp->map_num[y + tmp->y] == NULL)
			return (0);
		if (stp->map_num[y + tmp->y][x + tmp->x] == END_AR)
			return (0);
		if(tmp->ch == '*' && stp->map_num[tmp->y + y][tmp->x + x] == stp->enemy)
			return (0);
		tmp = tmp->next;
	}
	tmp = stp->figure;
	while (tmp)
	{
		if(tmp->ch == '*' && stp->map_num[tmp->y + y][tmp->x + x] == stp->player)
			i++;
		tmp = tmp->next;
	}
	return ((i == 1 ? 1 : 0));
}

int	impact_strength(int x, int y, step *stp)
{
	figure *tmp;
	int power;

	power = 0;
	tmp = stp->figure;
	if(chech_valid(x, y, stp) == 1)
	{
		while (tmp)
		{
			if (tmp->ch == '*' && stp->map_num[tmp->y + y][tmp->x + x] != stp->player)
					power = power + stp->map_num[tmp->y + y][tmp->x + x];
			tmp = tmp->next;
		}
		return (power);
	}
	return (-1);
}

int calculate_hit(int x, int y, step *stp, coords *cor)
{
	int power;
	int new_power;

	if (stp->map_num[y][x] == END_AR)
	{
		y++;
		x = 0;
		if (stp->map_num[y] == NULL)
			return (-1);
	}
	power = calculate_hit(x + 1, y, stp, cor);
	new_power = impact_strength(x, y, stp);
    if (((new_power > power && cor->poz == 1) || (new_power >= power && cor->poz == 2)) && new_power != -1)
	{
		cor->x = x;
		cor->y = y;
		return (new_power);
	}
	return (power);
}

int attack_enemy(step *stp, game_info *gf)
{
    coords *cor;
	cor = malloc(sizeof(cor));
	init_cor(cor, stp, gf);
    calculate_hit(0, 0, stp, cor);
	ft_putnbr(cor->y);
	ft_putchar(' ');
	ft_putnbr(cor->x);
	ft_putchar('\n');
	if (cor->x == -1 && cor->y == -1)
	{
		free(cor);
		cor = NULL;
		return (-1);
	}
	free(cor);
	cor = NULL;
	return (0);
}