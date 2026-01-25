/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamae <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 12:50:00 by ttamae            #+#    #+#             */
/*   Updated: 2025/12/27 12:50:02 by ttamae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	get_min_pos(t_stack *a)
{
	int		pos;
	int		min_value;
	t_stack	*tmp;

	pos = 0;
	tmp = a;
	if (!a)
		return (-1);
	min_value = a->value;
	while (tmp)
	{
		if (tmp->value < min_value)
			min_value = tmp->value;
		tmp = tmp->next;
	}
	tmp = a;
	while (tmp && tmp->value != min_value)
	{
		pos++;
		tmp = tmp->next;
	}
	return (pos);
}

static void	bring_min_to_top(t_stack **a)
{
	int	pos;
	int	size;

	pos = get_min_pos(*a);
	size = stack_size(*a);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			ra(a);
	}
	else
	{
		while (pos++ < size)
			rra(a);
	}
}

void	sort_four(t_stack **a, t_stack **b)
{
	bring_min_to_top(a);
	pb(a, b);
	sort_three(a);
	pa(a, b);
}

void	sort_five(t_stack **a, t_stack **b)
{
	bring_min_to_top(a);
	pb(a, b);
	bring_min_to_top(a);
	pb(a, b);
	sort_three(a);
	pa(a, b);
	pa(a, b);
}
