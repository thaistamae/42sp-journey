/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamae <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 10:17:40 by ttamae            #+#    #+#             */
/*   Updated: 2025/06/16 10:17:41 by ttamae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	total;

	total = 1;
	if (nb < 0)
	{
		return (0);
	}
	if (nb == 0 || nb == 1)
	{
		return (1);
	}
	while (nb > 0)
	{
		total = total * nb;
		nb--;
	}
	return (total);
}

/*int	main(void)
{
	int	nbr = 4;
	printf("%d\n", ft_iterative_factorial(nbr));
}*/
