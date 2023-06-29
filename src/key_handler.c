/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima <vlima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:28:19 by vlima             #+#    #+#             */
/*   Updated: 2023/05/18 13:07:58 by vlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_right(t_window *window)
{
	int	y;
	int	x;

	y = window->map->p_pos_y;
	x = window->map->p_pos_x;
	if ((x + 1 < (window->map->x - 1)) && (window->map->map[y][x + 1] != '1'))
	{
		if (!(end_game(window, y, x + 1)))
			return ;
		window->map->p_pos_x++;
		window->map->map[y][x + 1] = 'P';
		window->map->map[y][x] = '0';
		image_selection(window, y, x);
		image_selection(window, y, x + 1);
		window->nbr_moves++;
		ft_printf("Total of moves:%d\n", window->nbr_moves);
	}
}

void	move_left(t_window *window)
{
	int	y;
	int	x;

	y = window->map->p_pos_y;
	x = window->map->p_pos_x;
	if ((x - 1 > 0) && (window->map->map[y][x - 1] != '1'))
	{
		if (!(end_game(window, y, x - 1)))
			return ;
		window->map->p_pos_x--;
		window->map->map[y][x - 1] = 'P';
		window->map->map[y][x] = '0';
		image_selection(window, y, x);
		image_selection(window, y, x - 1);
		window->nbr_moves++;
		ft_printf("Total of moves:%d\n", window->nbr_moves);
	}
}

void	move_down(t_window *window)
{
	int	y;
	int	x;

	y = window->map->p_pos_y;
	x = window->map->p_pos_x;
	if ((y + 1 < window->map->y) && (window->map->map[y + 1][x] != '1'))
	{
		if (!(end_game(window, y + 1, x)))
			return ;
		window->map->p_pos_y++;
		window->map->map[y + 1][x] = 'P';
		window->map->map[y][x] = '0';
		image_selection(window, y, x);
		image_selection(window, y + 1, x);
		window->nbr_moves++;
		ft_printf("Total of moves:%d\n", window->nbr_moves);
	}
}

void	move_up(t_window *window)
{
	int	y;
	int	x;

	y = window->map->p_pos_y;
	x = window->map->p_pos_x;
	if ((y - 1 > 0) && (window->map->map[y - 1][x] != '1'))
	{
		if (!(end_game(window, y - 1, x)))
			return ;
		window->map->p_pos_y--;
		window->map->map[y - 1][x] = 'P';
		window->map->map[y][x] = '0';
		image_selection(window, y, x);
		image_selection(window, y - 1, x);
		window->nbr_moves++;
		ft_printf("Total of moves:%d\n", window->nbr_moves);
	}
}

int	key_handler(int keycode, t_window *window)
{
	if (keycode == 65307)
		close_handler(window);
	if (keycode == 119)
		move_up(window);
	if (keycode == 115)
		move_down(window);
	if (keycode == 97)
		move_left(window);
	if (keycode == 100)
		move_right(window);
	return (1);
}
