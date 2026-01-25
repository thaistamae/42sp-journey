/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamae <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 18:06:43 by ttamae            #+#    #+#             */
/*   Updated: 2025/12/26 18:06:45 by ttamae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	rotate(t_stack	**s)
{
	t_stack	*tmp;
	t_stack	*current;

	if (!s || !*s || !(*s)->next)
		return ;
	tmp = *s;
	*s = (*s)->next;
	current = *s;
	while (current->next)
		current = current->next;
	current->next = tmp;
	tmp->next = NULL;
}

void	ra(t_stack **stack_a)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
}

void	rb(t_stack **stack_b)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
}
