/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamae <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 20:15:27 by ttamae            #+#    #+#             */
/*   Updated: 2025/05/29 20:15:32 by ttamae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	*start;
	int	*end;
	int	temp;

	start = tab;
	end = tab + size - 1;
	while (start < end)
	{
		temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;
	}
}

/*int	ft_intlen(int *nbr)
{
	int	count;

	count = 0;
	while (*nbr)
	{
		count++;
		nbr++;
	}
	return (count);
}

int	main(void)
{
	int	nbr[] =	{1, 7, 3, 4, 5};
	int	size = ft_intlen(nbr);

	printf("%d\n", size);
	ft_rev_int_tab(nbr, size);
	for	(int i = 0; i < size; i++)
	{
        printf("numeros[%d] = %d\n", i, nbr[i]);
    }
	return (0);
}*/