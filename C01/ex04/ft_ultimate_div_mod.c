/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamae <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 18:39:21 by ttamae            #+#    #+#             */
/*   Updated: 2025/05/29 18:39:23 by ttamae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	division;
	int	mod;

	division = *a / *b;
	mod = *a % *b;
	*a = division;
	*b = mod;
}

/*int	main(void)
{
	int	x;
	int	y;

	x = 13;
	y = 5;
	printf("Antes: x = %d, y = %d\n", x, y);
	ft_ultimate_div_mod(&x, &y);
	printf("Depois: x = %d, y = %d\n", x, y);
	return (0);
}*/