/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamae <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 10:20:00 by ttamae            #+#    #+#             */
/*   Updated: 2025/06/16 10:20:01 by ttamae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_is_prime(int nb)
{
	int	number;

	number = 2;
	if (nb <= 0 || nb == 1)
	{
		return (0);
	}
	while (number < nb)
	{
		if (nb % number == 0)
		{
			return (0);
		}
		number++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (ft_is_prime(nb))
	{
		return (nb);
	}
	while (!ft_is_prime(nb))
	{
		nb++;
	}
	return (nb);
}

/*int	main(void)
{
	int number = 12;
	printf("%d\n", ft_find_next_prime(number));
}*/