/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamae <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 20:44:37 by ttamae            #+#    #+#             */
/*   Updated: 2025/05/29 20:44:39 by ttamae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

char	*ft_strcpy(char *dest, char *str)
{
	char	*start;

	start = dest;
	while (*str)
	{
		*dest = *str;
		str++;
		dest++;
	}
	*dest = '\0';
	return (start);
}

/*int	ft_lenstr(char *str)
{
	int	count;

	count = 0;
	while (str[count])
	{
		count++;
	}
	return (count + 1);
}

int	main(void)
{
	char	*x = "Hello";
	int	len = ft_lenstr(x);
	char	dest[len];

	ft_strcpy(dest, x);
	printf("%s\n", dest);
	return (0);
}*/