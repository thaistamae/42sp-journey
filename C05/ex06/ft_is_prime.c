/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamae <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 10:19:47 by ttamae            #+#    #+#             */
/*   Updated: 2025/06/16 10:19:48 by ttamae           ###   ########.fr       */
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

/*int main(void)
{
	printf("%d\n", ft_is_prime(4));
}*/
