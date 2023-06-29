/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima <vlima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:35:07 by vlima             #+#    #+#             */
/*   Updated: 2023/06/29 15:28:31 by vlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	number_of_c(char **map)
{
	int	i;
	int	j;
	int	count_colectibles;

	i = 0;
	count_colectibles = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
			{
				count_colectibles++;
			}
			j++;
		}
		i++;
	}
	return (count_colectibles);
}

int	ft_count_lines(char *argv)
{
	char	*line;
	int		fd1;
	int		i;

	fd1 = open(argv, O_RDONLY);
	i = 0;
	line = get_next_line(fd1);
	while (line != NULL)
	{
		i++;
		free(line);
		line = get_next_line(fd1);
	}
	free(line);
	close(fd1);
	return (i);
}

char	**map_blank(int y, int x)
{
	char	**map_blank;
	int		i;

	map_blank = (char **)ft_calloc(y, sizeof(char *));
	i = 0;
	while (i < y)
	{
		map_blank[i] = (char *)ft_calloc(x + 1, sizeof(char));
		i++;
	}
	return (map_blank);
}

char	**map_reader(char *argv)
{
	char	**map;
	int		number_of_lines;
	int		fd1;
	int		i;

	number_of_lines = ft_count_lines(argv);
	map = (char **)ft_calloc(number_of_lines + 1, sizeof(char *));
	if (!map)
		return (0);
	fd1 = open(argv, O_RDONLY);
	if (fd1 < 0 || fd1 > 4096)
		return (0);
	i = 0;
	while (i < number_of_lines)
	{
		map[i] = get_next_line(fd1);
		i++;
	}
	map[i] = NULL;
	close(fd1);
	return (map);
}

t_map	*map_init(char *argv)
{
	t_map	*map_set;
	char	**map_canvas;

	map_set = (t_map *)ft_calloc(1, sizeof(t_map));
	if (!map_set)
		return (0);
	map_set->map = map_reader(argv);
	if (!map_set->map)
	{
		free(map_set);
		free(map_set->map);
		return (0);
	}
	map_set->y = ft_count_lines(argv);
	map_set->x = ft_strlen(map_set->map[0]);
	if (!map_checklist(map_set->map, map_set))
		return (0);
	map_set->number_of_c = number_of_c(map_set->map);
	map_canvas = map_blank(map_set->y, map_set->x);
	map_goal_possible(map_set, map_canvas, map_set->p_pos_y, map_set->p_pos_x);
	free_map(map_canvas, map_set->y);
	if (!(map_set->map_goal_exit)
		|| !(map_set->map_goal_c == map_set->number_of_c))
		return (free_t_map(map_set));
	return (map_set);
}
