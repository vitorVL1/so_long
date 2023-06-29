/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima <vlima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 15:54:28 by vlima             #+#    #+#             */
/*   Updated: 2023/06/29 16:04:38 by vlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	open_image(t_window *window)
{
	int			x;
	int			y;
	t_sprite	*sprite_type;

	sprite_type = (t_sprite *)ft_calloc(1, sizeof(t_sprite));
	if (!sprite_type)
		return (0);
	x = PX;
	y = PX;
	sprite_type->wall = mlx_xpm_file_to_image(window->mlx_begin,
			"./textures/bushes_64x64-overlay.xpm", &x, &y);
	sprite_type->player = mlx_xpm_file_to_image(window->mlx_begin,
			"./textures/dog_64x64-overlay.xpm", &x, &y);
	sprite_type->exit = mlx_xpm_file_to_image(window->mlx_begin,
			"./textures/doghouse_64x64-overlay.xpm", &x, &y);
	sprite_type->collectible = mlx_xpm_file_to_image(window->mlx_begin,
			"./textures/bone_64x64-overlay.xpm", &x, &y);
	sprite_type->path = mlx_xpm_file_to_image(window->mlx_begin,
			"./textures/dirt_path_64x64.xpm", &x, &y);
	window->sprite = sprite_type;
	return (1);
}

void	image_selection(t_window *window, int height, int width)
{
	if (window->map->map[height][width] == '1')
		mlx_put_image_to_window(window->mlx_begin, window->mlx_window,
			window->sprite->wall, width * PX, height * PX);
	else if (window->map->map[height][width] == 'C')
		mlx_put_image_to_window(window->mlx_begin, window->mlx_window,
			window->sprite->collectible, width * PX, height * PX);
	else if (window->map->map[height][width] == 'P')
		mlx_put_image_to_window(window->mlx_begin, window->mlx_window,
			window->sprite->player, width * PX, height * PX);
	else if (window->map->map[height][width] == '0')
		mlx_put_image_to_window(window->mlx_begin, window->mlx_window,
			window->sprite->path, width * PX, height * PX);
	else if (window->map->map[height][width] == 'E')
		mlx_put_image_to_window(window->mlx_begin, window->mlx_window,
			window->sprite->exit, width * PX, height * PX);
}

void	add_images_to_game(t_window *window)
{
	int	height;
	int	width;	

	height = 0;
	while (height < window->map->y)
	{
		width = 0;
		while (width < window->map->x)
		{
			image_selection(window, height, width);
			width++;
		}
		height++;
	}
}
