/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorine <tlorine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 18:56:17 by tlorine           #+#    #+#             */
/*   Updated: 2019/10/22 21:04:20 by tlorine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_vis.h"

int main()
{
    step_list *step_list;

    step_list = create_list_step();
    write_game_back(step_list);
    free_list(&step_list, step_list->height);
    return (0);
}