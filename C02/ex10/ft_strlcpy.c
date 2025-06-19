/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamae <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 15:27:11 by ttamae            #+#    #+#             */
/*   Updated: 2025/06/04 15:27:14 by ttamae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		count++;
		str++;
	}
	return (count);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{	
	unsigned int	i;
	unsigned int	str_len;

	str_len = ft_strlen(src);
	i = 0;
	if (size == 0)
		return (str_len);
	while (src[i] && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (str_len);
}

/*int	main(void)
{
	int size = 7;
	char	dest[size];
	char	*src = "Ola, mundo!";
	int count;

	ft_strlcpy(dest, src, size);
	count = ft_strlen(src);

	printf("%s\n", dest);
	printf("%d\n", count);
	printf("Buffer destino: %lu caracteres\n", sizeof(dest));

	return (0);
}*/