/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamae <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:22:54 by ttamae            #+#    #+#             */
/*   Updated: 2025/06/17 17:22:57 by ttamae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *src)
{
	int	count;

	count = 0;
	while (*src)
	{
		count++;
		src++;
	}
	return (count);
}

char	*ft_strdup(char *src)
{
	char	*s;
	int		strlen;
	int		i;

	strlen = ft_strlen(src) + 1;
	i = 0;
	s = malloc((strlen) * sizeof(char));
	if (!s)
		return (0);
	while (src[i])
	{
		s[i] = src[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char *teste = "copia";
// 	printf("%s\n", ft_strdup(teste));
// }
