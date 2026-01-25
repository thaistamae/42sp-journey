/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamae <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 14:12:09 by ttamae            #+#    #+#             */
/*   Updated: 2025/12/26 14:12:11 by ttamae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>
# include <sys/types.h>
# include "../libft/libft.h"
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

int			is_number(char	*argv);
int			is_empty_or_spaces(char	*str);
int			has_duplicates(t_stack *a);
int			is_ordered(t_stack *a);
int			parse_and_fill_stack(t_stack	**a, char	**argv);
int			stack_size(t_stack *stack);
void		free_split(char	**split);
void		sa(t_stack	**a);
void		sb(t_stack	**b);
void		ss(t_stack	**a, t_stack **b);
void		pa(t_stack **stack_a, t_stack **stack_b);
void		pb(t_stack **stack_b, t_stack **stack_a);
void		ra(t_stack **stack_a);
void		rb(t_stack **stack_b);
void		rr(t_stack **stack_a, t_stack **stack_b);
void		rra(t_stack **stack_a);
void		rrb(t_stack **stack_b);
void		rrr(t_stack **stack_a, t_stack **stack_b);
void		index_stack(t_stack *a);
void		sort_two(t_stack **a);
void		sort_three(t_stack **a);
void		sort_four(t_stack **a, t_stack **b);
void		sort_five(t_stack **a, t_stack **b);
void		free_stack(t_stack **stack);
void		radix_sort(t_stack **a, t_stack **b);
long		ft_atol(const char *nptr);

#endif
