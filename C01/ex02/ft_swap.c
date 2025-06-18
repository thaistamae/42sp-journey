/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamae <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:42:51 by ttamae            #+#    #+#             */
/*   Updated: 2025/05/29 14:42:57 by ttamae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	save_a;
	int	save_b;

	save_a = *a;
	save_b = *b;
	*a = save_b;
	*b = save_a;
}

/*int	main(void)
{
	int	x;
	int	y;

	x = 65;
	y = 66;
	printf("Antes da troca: x = %d, y = %d\n", x, y);
	ft_swap(&x, &y);
	printf("Depois da troca: x = %d, y = %d\n", x, y);
	return (0);
}*/
