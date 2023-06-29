/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima <vlima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:27:08 by vlima             #+#    #+#             */
/*   Updated: 2023/06/29 15:12:45 by vlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_name(char *str)
{
	size_t	i;

	i = ft_strlen(str) - 1;
	if (str[i] != 'r' || str[i - 1] != 'e' || str[i - 2] != 'b' || str[i
			- 3] != '.')
		return (1);
	if (str[0] != 'm' || str[1] != 'a' || str[2] != 'p' || str[3] != 's'
		|| str[4] != '/')
		return (1);
	return (0);
}

int	check_arg(int ac, char **av)
{
	int	fd;

	if (ac != 2)
	{
		error("error: invalid args");
	}
	else if (ac == 2 && check_name(av[1]))
	{
		error("error: Wrong map name. Map name should be maps/<map_name>.ber");
		return (0);
	}
	else
	{
		fd = open(av[1], O_RDONLY);
		if (fd < 0)
		{
			error("errror: problems opn the file");
			return (0);
		}
		close(fd);
	}
	return (1);
}
