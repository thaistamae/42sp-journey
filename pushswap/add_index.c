/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamae <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 18:27:41 by ttamae            #+#    #+#             */
/*   Updated: 2025/12/26 18:27:43 by ttamae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static t_stack	*get_min_unindexed(t_stack *a)
{
	t_stack	*min;

	min = NULL;
	while (a)
	{
		if (a->index == -1)
		{
			if (!min || a->value < min->value)
				min = a;
		}
		a = a->next;
	}
	return (min);
}

void	index_stack(t_stack *a)
{
	int		i;
	int		size;
	t_stack	*min;

	i = 0;
	size = stack_size(a);
	while (i < size)
	{
		min = get_min_unindexed(a);
		if (min)
			min->index = i;
		i++;
	}
}
