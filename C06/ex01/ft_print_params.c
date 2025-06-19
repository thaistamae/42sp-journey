/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamae <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 14:24:38 by ttamae            #+#    #+#             */
/*   Updated: 2025/06/16 14:24:40 by ttamae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	argument;
	int	i;

	argument = 1;
	while (argument < argc)
	{
		i = 0;
		while (argv[argument][i])
		{
			write(1, &argv[argument][i], 1);
			i++;
		}
		write(1, "\n", 1);
		argument++;
	}
	return (0);
}
