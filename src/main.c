/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima <vlima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:00:16 by vlima             #+#    #+#             */
/*   Updated: 2023/05/18 12:19:46 by vlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	start_game(t_window *window)
{
	window->mlx_begin = mlx_init();
	if (!window->mlx_begin)
		return (free_mlx(window));
	window->mlx_window = mlx_new_window(window->mlx_begin, (window->map->x - 1)
			* PX, window->map->y * PX, "so_long");
	if (!window->mlx_window)
		return (free_mlx(window));
	if (!open_image(window))
		return (free_mlx(window));
	add_images_to_game(window);
	mlx_hook(window->mlx_window, 17, 1L << 17, close_handler, window);
	mlx_hook(window->mlx_window, 2, 1L << 0, key_handler, window);
	mlx_loop(window->mlx_begin);
	return (0);
}

int	main(int ac, char **av)
{
	t_window	*window;

	if (!check_arg(ac, av))
		return (0);
	window = (t_window *)ft_calloc(1, sizeof(t_window));
	if (!window)
		return (0);
	window->map = map_init(av[1]);
	if (!window->map)
	{
		free(window);
		return (0);
	}
	start_game(window);
}
