/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorine <tlorine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 18:55:55 by tlorine           #+#    #+#             */
/*   Updated: 2019/10/29 16:09:57 by tlorine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "lib/libft.h"
# include <fcntl.h>

# define O -1
# define X -2
# define POINT -3
# define END_AR -4

# define FREE_S(inf) free(inf), inf = NULL

typedef struct		s_figure
{
	int				x;
	int				y;
	char			ch;
	struct s_figure	*next;
}					t_figure;

typedef struct		s_coords
{
	int				x;
	int				y;
	int				poz;
}					t_coords;

typedef struct		s_step
{
	int				**map_num;
	int				figure_width;
	int				figure_height;
	int				player;
	int				enemy;
	t_figure		*figure;
}					t_step;

typedef struct		s_game_info
{
	int				player;
	int				map_x;
	int				map_y;
}					t_game_info;

typedef struct		s_nm
{
	int				x;
	int				y;
	char			*line;
	int				**map_num;
}					t_nm;

t_step				*create_step(t_game_info *ginf);
void				delete_step(t_step **st);
void				track_enemy(t_step *stp, t_game_info *gf);
int					attack_enemy(t_step *stp, t_game_info *gf);

#endif
