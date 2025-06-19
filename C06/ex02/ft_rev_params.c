/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamae <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 14:24:52 by ttamae            #+#    #+#             */
/*   Updated: 2025/06/16 14:24:53 by ttamae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	argument;
	int	i;

	argument = argc - 1;
	while (argument > 0)
	{
		i = 0;
		while (argv[argument][i])
		{
			write(1, &argv[argument][i], 1);
			i++;
		}
		write(1, "\n", 1);
		argument--;
	}
	return (0);
}
