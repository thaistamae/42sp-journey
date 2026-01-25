/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamae <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 14:56:51 by ttamae            #+#    #+#             */
/*   Updated: 2026/01/18 14:56:53 by ttamae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	read_map(t_game *game, char *file)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_exit("File error");
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (line[0] == '\n')
		{
			free(line);
			error_exit("Map has empty line");
		}		
		game->map[i] = ft_strtrim(line, "\r\n");
		free(line);
		if (!game->map[i])
			error_exit("Malloc failed");
		i++;
		line = get_next_line(fd);
	}
	game->map[i] = NULL;
	close(fd);
}

static void	validate_map(t_game *game)
{
	game->width = ft_strlen(game->map[0]);
	if (!validate_ret(game->map, game->height))
		error_exit("Map not rectangular");
	if (!validate_chars(game->map, game->height))
		error_exit("Invalid characters");
	if (!validate_elements(game->map, game->height))
		error_exit("Invalid elements");
	if (!validate_walls(game->map, game->height))
		error_exit("Invalid walls");
	validate_path_map(game);
}

void	parse_and_validate(t_game *game, char *file)
{
	game->height = count_lines(file);
	game->map = malloc(sizeof(char *) * (game->height + 1));
	if (!game->map)
		error_exit("Malloc failed");
	read_map(game, file);
	validate_map(game);
}
