/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamae <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 12:48:40 by ttamae            #+#    #+#             */
/*   Updated: 2025/06/04 12:48:42 by ttamae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	str_len(char *dest)
{
	int	count;

	count = 0;
	while (*dest)
	{	
		dest++;
		count++;
	}
	return (count);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	dest_len;

	i = 0;
	dest_len = str_len(dest);
	while (src[i] && i < nb)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest);
}

/*int main(void)
{
	char string1[50] = "Ola,";
	char string2[] = "mundo!";
	unsigned int max = 3;

	printf("%s\n", string1);
	ft_strncat(string1, string2, max);
	printf("%s\n", string1);

	return (0);
}*/