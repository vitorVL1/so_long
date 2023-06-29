/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima <vlima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 14:49:49 by vlima             #+#    #+#             */
/*   Updated: 2023/06/29 15:18:59 by vlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**free_map(char **map, int y)
{
	int	i;

	i = 0;
	while (i < y)
	{
		free(map[i]);
		i++;
	}
	free(map);
	map = NULL;
	return (map);
}

t_map	*free_t_map(t_map *map_set)
{
	free_map(map_set->map, map_set->y);
	free(map_set);
	map_set = NULL;
	ft_printf("Error\nMap is misconfigured\n");
	return (map_set);
}

int	free_mlx(t_window *window)
{
	free_map(window->map->map, window->map->y);
	if (window->mlx_begin && window->mlx_window)
	{
		mlx_clear_window(window->mlx_begin, window->mlx_window);
		mlx_destroy_image(window->mlx_begin, window->sprite->wall);
		mlx_destroy_image(window->mlx_begin, window->sprite->collectible);
		mlx_destroy_image(window->mlx_begin, window->sprite->player);
		mlx_destroy_image(window->mlx_begin, window->sprite->path);
		mlx_destroy_image(window->mlx_begin, window->sprite->exit);
		mlx_destroy_window(window->mlx_begin, window->mlx_window);
	}
	free(window->sprite);
	free(window->map);
	free(window->mlx_begin);
	free(window);
	exit(0);
}

int	close_handler(t_window *window)
{
	free_map(window->map->map, window->map->y);
	mlx_destroy_image(window->mlx_begin, window->sprite->wall);
	mlx_destroy_image(window->mlx_begin, window->sprite->collectible);
	mlx_destroy_image(window->mlx_begin, window->sprite->player);
	mlx_destroy_image(window->mlx_begin, window->sprite->path);
	mlx_destroy_image(window->mlx_begin, window->sprite->exit);
	mlx_clear_window(window->mlx_begin, window->mlx_window);
	mlx_destroy_window(window->mlx_begin, window->mlx_window);
	mlx_destroy_display(window->mlx_begin);
	free(window->sprite);
	free(window->map);
	free(window->mlx_begin);
	free(window);
	exit(0);
	return (1);
}

int	end_game(t_window *window, int y, int x)
{
	if (window->map->map[y][x] == 'C')
		window->map->number_of_c--;
	else if (window->map->map[y][x] == 'E' && window->map->number_of_c > 0)
		return (0);
	else if (window->map->map[y][x] == 'E' && window->map->number_of_c == 0)
	{
		ft_printf("You won!! Game ended in %d moves\n", window->nbr_moves);
		close_handler(window);
	}
	return (1);
}
