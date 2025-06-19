/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamae <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 10:19:27 by ttamae            #+#    #+#             */
/*   Updated: 2025/06/16 10:19:27 by ttamae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_sqrt(int nb)
{
	int	number;

	number = 1;
	while (number <= nb)
	{
		if (number * number == nb)
		{
			return (number);
		}
		else
		{
			number++;
		}
	}
	return (0);
}

/*int main(void)
{
	printf("%d\n", ft_sqrt(9));	
}*/