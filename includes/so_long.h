/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima <vlima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:41:48 by vlima             #+#    #+#             */
/*   Updated: 2023/06/29 15:21:02 by vlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <fcntl.h>
# include <limits.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# define PX 64

typedef struct s_map
{
	int			x;
	int			y;
	char		**map;
	int			p_pos_y;
	int			p_pos_x;
	int			map_is_rectangular;
	int			map_is_enclosed;
	int			map_1_exit;
	int			map_1_start_pos;
	int			map_is_only_01pce;
	int			map_has_colectibles;
	int			number_of_c;
	int			map_goal_exit;
	int			map_goal_c;
}				t_map;

typedef struct s_sprite
{
	void		*wall;
	void		*collectible;
	void		*player;
	void		*path;
	void		*exit;
}				t_sprite;

typedef struct s_window
{
	void		*mlx_begin;
	void		*mlx_window;
	t_sprite	*sprite;
	int			nbr_moves;
	t_map		*map;
}				t_window;

int				error(char *str);
int				check_arg(int ac, char **av);
int				open_image(t_window *window);
int				close_handler(t_window *window);
int				free_mlx(t_window *window);
size_t			ft_count_map_lines(char **map);
t_map			*free_t_map(t_map *map_set);
int				map_checklist(char **map, t_map *map_set);
char			**map_blank(int y, int x);
void			map_goal_possible(t_map *map_set, char **map_canvas,
					int p_pos_y, int p_pos_x);
int				key_handler(int keycode, t_window *window);
t_map			*map_init(char *argv);
int				map_has_colectibles(char **map, t_map *map_set);
int				map_is_only_01pce(char **map, t_map *map_set);
int				end_game(t_window *window, int y, int x);
void			image_selection(t_window *window, int height, int width);
void			add_images_to_game(t_window *window);	
char			**free_map(char **map, int y);
#endif