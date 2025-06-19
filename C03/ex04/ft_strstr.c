/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamae <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 12:50:49 by ttamae            #+#    #+#             */
/*   Updated: 2025/06/04 12:50:51 by ttamae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	char	*str_add;
	char	*find_add;

	if (*to_find == '\0')
		return (str);
	while (*str)
	{
		if (*str == *to_find)
		{
			str_add = str;
			find_add = to_find;
			while (*find_add && *str_add && *find_add == *str_add)
			{
				str_add++;
				find_add++;
			}
			if (*find_add == '\0')
			{
				return (str);
			}
		}		
		str++;
	}
	return (0);
}

/*int main(void)
{
	char str[] = "Este é um exemplo de string.";
    char sub[] = "exemplo";

    char *result = ft_strstr(str, sub);
    if (result)
    {
        printf("Substring encontrada: %s\n", result);
    }
    else
    {
        printf("Substring não encontrada.\n");
    }
	return (0);
}*/
