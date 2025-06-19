/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamae <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 12:47:41 by ttamae            #+#    #+#             */
/*   Updated: 2025/06/04 12:47:43 by ttamae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] > s2[i] || s1[i] < s2[i])
		{
			return (s1[i] - s2[i]);
		}	
		i++;
	}
	return (0);
}

/*int	main(void)
{
	char *string1 = "Ola";
	char *string2 = "Olar";
	ft_strcmp(string1, string2);
	printf("%d\n", ft_strcmp(string1, string2));
	return (0);
}*/