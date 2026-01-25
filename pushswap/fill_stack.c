/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamae <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 16:07:20 by ttamae            #+#    #+#             */
/*   Updated: 2025/12/26 16:07:23 by ttamae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static t_stack	*stack_new(int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new -> value = value;
	new -> index = -1;
	new -> next = NULL;
	return (new);
}

static int	validate_arg(char	*argv)
{
	char	**lst;
	int		i;
	long	nb;

	i = 0;
	lst = ft_split(argv, ' ');
	if (!lst)
		return (0);
	if (is_empty_or_spaces(argv))
		return (free_split(lst), 0);
	while (lst[i])
	{
		if (!is_number(lst[i]))
			return (free_split(lst), 0);
		nb = ft_atol(lst[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			return (free_split(lst), 0);
		i++;
	}
	free_split(lst);
	return (1);
}

static void	stack_add_back(t_stack **a, t_stack *new)
{
	t_stack	*tmp;

	if (!a || !new)
		return ;
	if (!*a)
	{
		*a = new;
		return ;
	}
	tmp = *a;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

static int	fill_from_arg(t_stack **a, char *arg)
{
	char	**split;
	int		j;
	long	nb;

	if (!validate_arg(arg))
		return (0);
	split = ft_split(arg, ' ');
	if (!split)
		return (0);
	j = 0;
	while (split[j])
	{
		nb = ft_atol(split[j]);
		stack_add_back(a, stack_new((int)nb));
		j++;
	}
	free_split(split);
	return (1);
}

int	parse_and_fill_stack(t_stack **a, char **argv)
{
	int	i;

	i = 1;
	*a = NULL;
	while (argv[i])
	{
		if (!fill_from_arg(a, argv[i]))
		{
			free_stack(a);
			return (0);
		}
		i++;
	}
	return (1);
}
