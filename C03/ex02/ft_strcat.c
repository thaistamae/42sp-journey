/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamae <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 12:48:19 by ttamae            #+#    #+#             */
/*   Updated: 2025/06/04 12:48:21 by ttamae           ###   ########.fr       */
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

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	dest_len;

	i = 0;
	dest_len = str_len(dest);
	while (src[i])
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
	printf("%s\n", string1);
	ft_strcat(string1, string2);
	printf("%s\n", string1);

	return (0);
}*/