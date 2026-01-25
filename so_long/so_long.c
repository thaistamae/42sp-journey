/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamae <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 15:02:45 by ttamae            #+#    #+#             */
/*   Updated: 2026/01/18 15:02:53 by ttamae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	validate_extension(const char *file_name)
{
	const char	*ext;
	size_t		l_nam;
	size_t		l_ext;

	ext = ".ber";
	l_nam = ft_strlen(file_name);
	l_ext = ft_strlen(ext);
	if (l_nam < l_ext)
		return (0);
	return (ft_strncmp(file_name + l_nam - l_ext, ext, l_ext) == 0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		error_exit("Usage: ./so_long map.ber");
	if (!validate_extension(argv[1]))
		error_exit("Invalid file extension");
	ft_bzero(&game, sizeof(t_game));
	parse_and_validate(&game, argv[1]);
	find_player_position(&game);
	count_collectibles(&game);
	game.moves = 0;
	init_mlx(&game);
	load_images(&game);
	render_map(&game);
	mlx_key_hook(game.win, handle_key, &game);
	mlx_hook(game.win, 17, 0, close_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
