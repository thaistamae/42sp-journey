/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamae <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 16:05:22 by ttamae            #+#    #+#             */
/*   Updated: 2025/12/26 16:05:26 by ttamae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	is_number(char	*argv)
{
	int	i;

	i = 0;
	if (argv[i] == '-' || argv[i] == '+')
		i++;
	if (!argv[i])
		return (0);
	while (argv[i])
	{
		if (argv[i] < '0' || argv[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	is_empty_or_spaces(char	*str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '\0')
		return (1);
	return (0);
}

int	has_duplicates(t_stack *a)
{
	t_stack	*current;
	t_stack	*check;

	current = a;
	while (current)
	{
		check = current -> next;
		while (check)
		{
			if (current -> value == check -> value)
				return (1);
			check = check->next;
		}
		current = current->next;
	}
	return (0);
}

int	is_ordered(t_stack *a)
{
	if (!a || !a->next)
		return (1);
	while (a -> next)
	{
		if (a->value > (a->next->value))
			return (0);
		a = a-> next;
	}
	return (1);
}
