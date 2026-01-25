/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamae <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 14:16:06 by ttamae            #+#    #+#             */
/*   Updated: 2025/12/26 14:16:08 by ttamae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = stack_size(*stack_a);
	if (size <= 1)
		return ;
	if (size == 2)
		sort_two(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else if (size == 4)
		sort_four(stack_a, stack_b);
	else if (size == 5)
		sort_five(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	if (!parse_and_fill_stack(&a, argv))
		return (write(2, "Error\n", 6), 0);
	if (has_duplicates(a))
	{
		free_stack(&a);
		return (write(2, "Error\n", 6), 0);
	}
	if (is_ordered(a))
	{
		free_stack(&a);
		return (0);
	}
	index_stack(a);
	sort(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
