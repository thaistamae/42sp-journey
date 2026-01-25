/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamae <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 14:56:08 by ttamae            #+#    #+#             */
/*   Updated: 2026/01/18 14:56:11 by ttamae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	exit_game(t_game *game)
{
	free_map(game->map);
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

static void	move_to_exit(t_game *game)
{
	if (game->collectibles == 0)
	{
		ft_printf("You won in %d moves!\n", game->moves);
		exit_game(game);
	}
}

static void	move_player(t_game *game, int dx, int dy)
{
	int		new_x;
	int		new_y;
	char	next;

	new_x = game->player_x + dx;
	new_y = game->player_y + dy;
	next = game->map[new_y][new_x];
	if (next == '1')
		return ;
	if (next == 'C')
		game->collectibles--;
	if (next == 'E' && game->collectibles == 0)
	{
		move_to_exit(game);
	}
	update_previous_tile(game);
	game->previous_tile = next;
	game->map[new_y][new_x] = 'P';
	game->player_x = new_x;
	game->player_y = new_y;
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
	render_map(game);
}

int	handle_key(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		exit_game(game);
	else if (keycode == KEY_W)
		move_player(game, 0, -1);
	else if (keycode == KEY_S)
		move_player(game, 0, 1);
	else if (keycode == KEY_A)
		move_player(game, -1, 0);
	else if (keycode == KEY_D)
		move_player(game, 1, 0);
	return (0);
}

int	close_game(t_game *game)
{
	free_game(game);
	exit(0);
}
