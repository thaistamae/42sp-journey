/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamae <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 13:10:35 by ttamae            #+#    #+#             */
/*   Updated: 2025/06/04 13:10:40 by ttamae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	is_alphanumeric(char c)
{
	return ((c >= 'A' && c <= 'Z')
		|| (c >= 'a' && c <= 'z')
		|| (c >= '0' && c <= '9'));
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	new_word;

	i = 0;
	new_word = 1;
	while (str[i])
	{	
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			if (new_word)
				str[i] -= 32;
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{
			if (!new_word)
				str[i] += 32;
		}
		if (is_alphanumeric(str[i]))
			new_word = 0;
		else
			new_word = 1;
		i++;
	}
	return (str);
}

/*int main(void)
{
	char word[] = "Oi, tudo bem? 42palavras quarenta-e-duas; cinquenta+e+um";
	
	ft_strcapitalize(word);
	printf("%s\n", ft_strcapitalize(word));
	return 0;
}*/