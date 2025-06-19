/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamae <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:23:41 by ttamae            #+#    #+#             */
/*   Updated: 2025/06/17 17:23:42 by ttamae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	count;
	int	i;

	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	count = max - min;
	i = 0;
	*range = malloc(count * sizeof(int));
	if (!*range)
	{
		return (0);
	}
	while (i < count)
	{
		(*range)[i] = min + i;
		i++;
	}
	return (count);
}

// #include <stdio.h>
// int main(void)
// {
// 	int *array;
// 	int size = ft_ultimate_range(&array, 2, 3);

// 	printf("%d\n", size);
// }