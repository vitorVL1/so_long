/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima <vlima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 16:04:51 by vlima             #+#    #+#             */
/*   Updated: 2023/05/02 15:52:13 by vlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error(char *str)
{
	perror(str);
	exit(1);
}

size_t	ft_count_map_lines(char **map)
{
	size_t	i;

	i = 0;
	while (map[i])
	{
		i++;
	}
	return (i);
}
