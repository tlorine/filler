/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorine <tlorine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 21:07:07 by tlorine           #+#    #+#             */
/*   Updated: 2019/10/16 20:01:36 by tlorine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdel(char **as)
{
	if (as == NULL)
		return (NULL);
	free(*as);
	*as = NULL;
	return (*as);
}