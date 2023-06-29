/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima <vlima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:27:48 by vlima             #+#    #+#             */
/*   Updated: 2023/06/29 15:04:17 by vlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_is_only_01pce(char **map, t_map *map_set)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (map[i][j])
	{
		j = 0;
		while (j <= ((size_t)map_set->x - 2))
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'P'
				&& map[i][j] != 'C' && map[i][j] != 'E')
				return (0);
			j++;
		}
		i++;
	}
	map_set->map_is_only_01pce = 1;
	return (1);
}

int	map_has_colectibles(char **map, t_map *map_set)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
			{
				map_set->map_has_colectibles = 1;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	map_goal_possible(t_map *map_set, char **map_canvas, int p_pos_y,
		int p_pos_x)
{
	if (!(p_pos_y >= 0 && p_pos_y < (map_set->y - 1) && p_pos_x >= 0
			&& p_pos_x < ((map_set->x) - 1)))
		return ;
	if (map_set->map[p_pos_y][p_pos_x] == '1')
		return ;
	if (map_canvas[p_pos_y][p_pos_x] == '1')
		return ;
	if (map_set->map[p_pos_y][p_pos_x] == 'E')
	{
		map_set->map_goal_exit = 1;
		return ;
	}
	if (map_set->map[p_pos_y][p_pos_x] == 'C'
		&& map_canvas[p_pos_y][p_pos_x] != '1')
		map_set->map_goal_c++;
	map_canvas[p_pos_y][p_pos_x] = '1';
	map_goal_possible(map_set, map_canvas, p_pos_y + 1, p_pos_x);
	map_goal_possible(map_set, map_canvas, p_pos_y, p_pos_x + 1);
	map_goal_possible(map_set, map_canvas, p_pos_y - 1, p_pos_x);
	map_goal_possible(map_set, map_canvas, p_pos_y, p_pos_x - 1);
	return ;
}
