/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaraiva <csaraiva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 13:32:33 by marcosda          #+#    #+#             */
/*   Updated: 2025/06/01 17:34:20 by csaraiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

int	valid(int x, int y)
{	
	if (x <= 0 || y <= 0)
	{
		write (1, "Insira dois numeros inteiros e maiores que 0", 45);
		return (0);
	}	
	return (1);
}

void	rush(int x, int y)
{	
	int	larg;
	int	alt;

	if ((valid(x, y) == 0))
		return ;
	alt = 1;
	while (alt <= y)
	{
		larg = 1;
		while (larg <= x)
		{
			if ((larg == 1 && (alt == 1 || alt == y)))
				ft_putchar('A');
			else if ((larg == x && (alt == 1 || alt == y)))
				ft_putchar('C');
			else if ((larg != x && alt != y && alt != 1 && larg != 1))
				ft_putchar(' ');
			else
				ft_putchar('B');
			larg++;
		}
		alt++;
		ft_putchar('\n');
	}
}
