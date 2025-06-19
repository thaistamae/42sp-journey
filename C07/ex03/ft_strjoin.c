/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamae <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:23:58 by ttamae            #+#    #+#             */
/*   Updated: 2025/06/17 17:23:58 by ttamae           ###   ########.fr       */
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

char	*size_zero(int size)
{
	char	*str;

	str = malloc(1);
	str[0] = '\0';
	return (str);
}

void	copy_str(char *dest, int *j, char *src)
{
	int	k;

	k = 0;
	while (src[k])
	{
		dest[*j] = src[k];
		(*j)++;
		k++;
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*a;
	int		count_total;
	int		i;
	int		j;

	i = 0;
	j = 0;
	count_total = ft_strlen(sep) * (size - 1);
	if (size == 0)
		return (size_zero(size));
	while ((strs)[i] && i < size)
		count_total += ft_strlen((strs)[i++]);
	a = malloc((count_total + 1) * sizeof(char));
	i = 0;
	while ((strs)[i] && i < size)
	{
		copy_str(a, &j, strs[i]);
		if (i < size - 1)
			copy_str(a, &j, sep);
		i++;
	}
	a[j] = '\0';
	return (a);
}

// #include <stdio.h>
// int main(void)
// {
// 	char *strs[] = {"hello", "world", "42"};
// 	char *new;
// 	new = ft_strjoin(3, strs, "//");

// 	printf("%s\n", new);
// }