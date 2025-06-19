/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamae <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 12:58:25 by ttamae            #+#    #+#             */
/*   Updated: 2025/06/03 12:58:30 by ttamae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	char			*start;
	unsigned int	count;

	start = dest;
	count = 0;
	while (*src && count < n)
	{	
		*dest = *src;
		src++;
		dest++;
		count++;
	}
	while (count < n)
	{
		*dest = '\0';
		dest++;
		count++;
	}
	return (start);
}

/*unsigned int	ft_lenstr(char *str)
{
	int	count;

	count = 0;
	while (str[count])
	{
		count++;
	}
	return (count);
}

int	main(void)
{
	char	*x = "Hello";
	unsigned int	len = ft_lenstr(x);
	unsigned int size = 3;

	if(size < len)
	{
		len = size;
	}
	printf("%d\n", len);
	char	dest[len];

	ft_strncpy(dest, x, size);
	printf("Conteúdo de dest em decimal:\n");
	for (unsigned int i = 0; i < size; i++)
	{
		printf("dest[%d] = %d\n", i, (unsigned char)dest[i]);
	}
	printf("%s\n", dest);
	return (0);
}*/