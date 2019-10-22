/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorine <tlorine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 18:55:55 by tlorine           #+#    #+#             */
/*   Updated: 2019/10/22 18:55:56 by tlorine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
#define FILLER_H

#include "libft/libft.h"
#include <fcntl.h>

#define O -1
#define X -2
#define POINT -3
#define END_AR -4

typedef struct t_figure
{
    int x;
    int y;
    char ch;
    struct t_figure *next;
}               figure;

typedef struct t_coords
{
    int x;
    int y;
    int poz;
}               coords;

typedef struct t_step
{
    char	**map;
	int		**map_num;
    int		figure_width;
    int		figure_height;
	int 	player;
	int 	enemy;
    figure  *figure;
}              step;

typedef struct t_game_info
{
    int player;
    int map_x;
    int map_y;
}              game_info;

step *create_step(game_info *ginf);
void	delete_step(step **st);
void track_enemy(step *stp, game_info *gf);
int attack_enemy(step *stp, game_info *gf);

#endif