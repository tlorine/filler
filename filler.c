/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorine <tlorine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 18:55:47 by tlorine           #+#    #+#             */
/*   Updated: 2019/10/29 15:37:45 by tlorine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_game_info	*init_new_game(int *start, char **lm)
{
	t_game_info	*ngame;
	char		*line;

	line = NULL;
	*lm = NULL;
	*start = 1;
	while (1)
	{
		get_next_line(0, &line);
		if ((ft_strstr(line, "$$$")) != NULL)
		{
			ngame = (t_game_info *)malloc(sizeof(t_game_info));
			ngame->player = ((ft_strstr(line, "p1")) == NULL ? 2 : 1);
			line = ft_strdel(&line);
			get_next_line(0, &line);
			ngame->map_y = ft_atoi(line + 8);
			ngame->map_x = ft_atoi(line + (ngame->map_y == 100 ? 11 : 10));
			line = ft_strdel(&line);
			line = NULL;
			return (ngame);
		}
	}
}

int			main(void)
{
	t_game_info	*ginf;
	t_step		*stp;
	char		*line;
	int			str;

	ginf = init_new_game(&str, &line);
	while (1)
	{
		if (str == 1 || (line != NULL && (ft_strstr(line, "Plateau ")) != NULL))
		{
			str = 0;
			stp = create_step(ginf);
			stp->player = ginf->player == 1 ? O : X;
			stp->enemy = ginf->player == 1 ? X : O;
			track_enemy(stp, ginf);
			str = attack_enemy(stp, ginf);
			delete_step(&stp);
		}
		line = ft_strdel(&line);
		if (str == -1)
			break ;
		get_next_line(0, &line);
	}
	FREE_S(ginf);
	return (0);
}
