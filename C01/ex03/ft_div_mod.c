/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamae <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:49:45 by ttamae            #+#    #+#             */
/*   Updated: 2025/05/29 14:49:50 by ttamae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

/*int	main(void)
{
	int	x;
	int	y;
	int	div;
	int	mod;

	x = 13;
	y = 5;
	printf("Antes: x = %d, y = %d\n", x, y);
	ft_div_mod(x, y, &div, &mod);
	printf("Depois: divisão = %d, resto = %d\n", div, mod);
	return (0);
}*/