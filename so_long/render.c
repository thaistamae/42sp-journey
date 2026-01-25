/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamae <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 14:57:00 by ttamae            #+#    #+#             */
/*   Updated: 2026/01/18 14:57:02 by ttamae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_tile(t_game *g, char c, int x, int y)
{
	mlx_put_image_to_window(g->mlx, g->win,
		g->img_floor, x * TILE_SIZE, y * TILE_SIZE);
	if (c == '1')
		mlx_put_image_to_window(g->mlx, g->win,
			g->img_wall, x * TILE_SIZE, y * TILE_SIZE);
	else if (c == 'P')
		mlx_put_image_to_window(g->mlx, g->win,
			g->img_player, x * TILE_SIZE, y * TILE_SIZE);
	else if (c == 'E')
		mlx_put_image_to_window(g->mlx, g->win,
			g->img_exit, x * TILE_SIZE, y * TILE_SIZE);
	else if (c == 'C')
		mlx_put_image_to_window(g->mlx, g->win,
			g->img_collect, x * TILE_SIZE, y * TILE_SIZE);
}

void	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		error_exit("MLX init failed");
	game->win = mlx_new_window(
			game->mlx,
			game->width * TILE_SIZE,
			game->height * TILE_SIZE,
			"so_long"
			);
	if (!game->win)
		error_exit("Window creation failed");
}

void	load_images(t_game *game)
{
	int	size;

	size = TILE_SIZE;
	game->img_wall = mlx_xpm_file_to_image(
			game->mlx, "textures/wall.xpm", &size, &size);
	game->img_floor = mlx_xpm_file_to_image(
			game->mlx, "textures/floor.xpm", &size, &size);
	game->img_player = mlx_xpm_file_to_image(
			game->mlx, "textures/player.xpm", &size, &size);
	game->img_exit = mlx_xpm_file_to_image(
			game->mlx, "textures/exit.xpm", &size, &size);
	game->img_collect = mlx_xpm_file_to_image(
			game->mlx, "textures/collect.xpm", &size, &size);
	if (!game->img_wall || !game->img_floor || !game->img_player
		|| !game->img_exit || !game->img_collect)
		error_exit("Image loading failed");
}

void	render_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			put_tile(game, game->map[y][x], x, y);
			x++;
		}
		y++;
	}
}
