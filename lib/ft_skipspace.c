/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skipspace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 22:24:57 by tlorine           #+#    #+#             */
/*   Updated: 2019/04/13 22:31:55 by tlorine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_skipspace(const char *str)
{
	int i;

	i = 0;
	while (str[i] == '\t' || str[i] == '\v' || str[i] == '\r'
			|| str[i] == ' ' || str[i] == '\n' || str[i] == '\f')
		i++;
	return (i);
}