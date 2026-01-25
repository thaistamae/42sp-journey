/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamae <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 15:07:47 by ttamae            #+#    #+#             */
/*   Updated: 2026/01/18 15:07:49 by ttamae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"
# include "mlx.h"

# define TILE_SIZE 64
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

typedef struct s_counter
{
	int	counter_p;
	int	counter_e;
	int	counter_c;
}	t_counter;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	int		collectibles;
	int		moves;
	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_exit;
	void	*img_collect;
	char	previous_tile;
}	t_game;

typedef struct s_fill
{
	char	**map;
	int		height;
	int		width;
}	t_fill;

int		validate_elements(char **map, int line_num);
int		validate_ret(char **map, int line_num);
int		validate_chars(char **map, int line_num);
int		validate_walls(char **map, int line_num);
void	validate_path_map(t_game *game);
void	init_mlx(t_game *game);
int		handle_key(int keycode, t_game *game);
int		close_game(t_game *game);
void	parse_and_validate(t_game *game, char *file);
void	load_images(t_game *game);
void	render_map(t_game *game);
void	find_player_position(t_game *game);
void	count_collectibles(t_game *game);
char	**copy_map(char **map, int height);
void	free_map(char **map);
void	error_exit(char *msg);
void	free_game(t_game *game);
int		count_lines(char *file);
void	count_char(t_counter *count, char c);
void	update_previous_tile(t_game *game);

#endif
