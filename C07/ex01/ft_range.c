/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamae <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:23:18 by ttamae            #+#    #+#             */
/*   Updated: 2025/06/17 17:23:19 by ttamae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	count;
	int	*a;
	int	i;

	if (min >= max)
	{
		return (0);
	}
	i = 0;
	count = max - min;
	a = malloc(count * sizeof(int));
	if (!a)
		return (0);
	while (i < count)
	{
		a[i] = min + i;
		i++;
	}
	return (a);
}

// #include <stdio.h>
// int main(void)
// {
// 	int min;
// 	int max;
// 	int i;

// 	min = -4;
// 	max = 4;
// 	for (i = 0; i < (max - min); i++) 
// 	{
// 		printf("%d\n", ft_range(min, max)[i]);
// 	}
// }