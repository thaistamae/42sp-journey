/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamae <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 14:56:42 by ttamae            #+#    #+#             */
/*   Updated: 2026/01/18 14:56:43 by ttamae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_counter	count_chars(char **map, int line_num)
{
	t_counter	count;
	int			i;
	size_t		j;
	char		c;

	count.counter_p = 0;
	count.counter_e = 0;
	count.counter_c = 0;
	i = 0;
	while (i < line_num)
	{
		j = 0;
		while (j < ft_strlen(map[i]))
		{
			c = map[i][j];
			count_char(&count, c);
			j++;
		}
		i++;
	}
	return (count);
}

int	validate_elements(char **map, int line_num)
{
	t_counter	count;

	count = count_chars(map, line_num);
	if (count.counter_p != 1)
		return (0);
	if (count.counter_e != 1)
		return (0);
	if (count.counter_c < 1)
		return (0);
	return (1);
}

int	validate_ret(char **map, int line_num)
{
	size_t	fst_line_size;
	int		i;

	if (line_num == 0)
		return (1);
	fst_line_size = ft_strlen(map[0]);
	i = 1;
	while (i < line_num)
	{
		if (ft_strlen(map[i]) != fst_line_size)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	validate_chars(char **map, int line_num)
{
	const char	valid_char[] = "10PCE";
	int			i;
	int			j;
	int			k;

	i = 0;
	while (i < line_num)
	{
		j = 0;
		while (map[i][j])
		{
			k = 0;
			while (valid_char[k] && map[i][j] != valid_char[k])
				k++;
			if (!valid_char[k])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	validate_walls(char **map, int line_num)
{
	int	i;
	int	j;
	int	width;

	if (line_num < 3)
		return (0);
	width = ft_strlen(map[0]);
	i = 0;
	while (i < width)
	{
		if (map[0][i] != '1' || map[line_num - 1][i] != '1')
			return (0);
		i++;
	}
	j = 1;
	while (j < line_num - 1)
	{
		if (map[j][0] != '1' || map[j][width - 1] != '1')
			return (0);
		j++;
	}
	return (1);
}
