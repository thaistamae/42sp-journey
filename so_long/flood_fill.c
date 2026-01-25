/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamae <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 14:56:18 by ttamae            #+#    #+#             */
/*   Updated: 2026/01/18 14:56:20 by ttamae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	flood_fill(t_fill *f, int x, int y)
{
	if (x < 0 || y < 0 || x >= f->height || y >= f->width)
		return ;
	if (f->map[x][y] == '1' || f->map[x][y] == 'V')
		return ;
	f->map[x][y] = 'V';
	flood_fill(f, x - 1, y);
	flood_fill(f, x + 1, y);
	flood_fill(f, x, y - 1);
	flood_fill(f, x, y + 1);
}

static void	find_player(char **map, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				*x = i;
				*y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

static int	validate_path(char **map, int height, int width)
{
	t_fill	f;
	int		x;
	int		y;

	f.map = map;
	f.height = height;
	f.width = width;
	find_player(map, &x, &y);
	flood_fill(&f, x, y);
	x = 0;
	while (x < height)
	{
		y = 0;
		while (y < width)
		{
			if (map[x][y] == 'C' || map[x][y] == 'E')
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}

void	validate_path_map(t_game *game)
{
	char	**tmp;

	tmp = copy_map(game->map, game->height);
	if (!tmp)
		error_exit("Malloc failed");
	if (!validate_path(tmp, game->height, game->width))
	{
		free_map(tmp);
		error_exit("Invalid path");
	}
	free_map(tmp);
}
