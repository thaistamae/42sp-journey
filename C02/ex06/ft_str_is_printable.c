/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamae <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 11:24:40 by ttamae            #+#    #+#             */
/*   Updated: 2025/06/04 11:24:48 by ttamae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	if (*str == '\0')
		return (1);
	while (*str)
	{
		if ((*str >= 0 && *str <= 31) || (*str == 127))
			return (0);
		str++;
	}
	return (1);
}

/*int main(void)
{
	char *value = "\b";
	
	ft_str_is_printable(value);
	printf("%d\n", ft_str_is_printable(value));
	return 0;
}*/