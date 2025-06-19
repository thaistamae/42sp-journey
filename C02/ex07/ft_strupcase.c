/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamae <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 11:25:56 by ttamae            #+#    #+#             */
/*   Updated: 2025/06/04 11:25:59 by ttamae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

char	*ft_strupcase(char *str)
{
	char	*start;

	start = str;
	while (*str)
	{	
		if (*str >= 'a' && *str <= 'z')
			*str = *str - 32;
		str++;
	}
	return (start);
}

/*int main(void)
{
	char word[] = "abcde";
	
	ft_strupcase(word);
	printf("%s\n", ft_strupcase(word));
	return 0;
}*/