/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamae <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 16:25:05 by ttamae            #+#    #+#             */
/*   Updated: 2025/12/26 16:25:06 by ttamae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	swap(t_stack	**s)
{
	t_stack	*first;
	t_stack	*second;

	if (!s || !*s || !(*s)->next)
		return ;
	first = *s;
	second = (*s)->next;
	first->next = second->next;
	second->next = first;
	*s = second;
}

void	sa(t_stack	**a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack	**b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack	**a, t_stack **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
