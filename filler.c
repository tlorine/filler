/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorine <tlorine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 18:55:47 by tlorine           #+#    #+#             */
/*   Updated: 2019/10/22 18:55:48 by tlorine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

game_info *init_new_game()
{
	game_info *new_game;
	char *line;

	line = NULL;
	while (1)
	{
		get_next_line(0, &line);
		if ((ft_strstr(line, "$$$")) != NULL)
		{
			new_game = (game_info *)malloc(sizeof(game_info));
			new_game->player = ((ft_strstr(line, "p1")) == NULL ? 2 : 1);
			line = ft_strdel(&line);
			get_next_line(0, &line);
			new_game->map_y = ft_atoi(line + 8);
			new_game->map_x = ft_atoi(line + (new_game->map_y == 100 ? 11 : 10));
			line = ft_strdel(&line);
			line = NULL;
			return (new_game);
		}
	}
}

int main()
{
	game_info *ginf;
	step *stp;
	char *line;
	int start;

	line = NULL;
	ginf = init_new_game();
	start = 1;
	while(1)
	{
		if (start == 1 || (line != NULL && (ft_strstr(line, "Plateau ")) != NULL))
		{
			start = 0;
			line = ft_strdel(&line);
			stp = create_step(ginf);
			if (ginf->player == 1)
			{
				stp->player = O;
				stp->enemy = X;
			}
			else
			{
				stp->player = X;
				stp->enemy = O;
			}
			track_enemy(stp, ginf);
			start = attack_enemy(stp, ginf);
			delete_step(&stp);
		}
		else
			line = ft_strdel(&line);
		if (start == -1)
			break;
		get_next_line(0, &line);
	}
	return (0);
}