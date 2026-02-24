/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicorodr <nicorodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 12:56:20 by nicorodr          #+#    #+#             */
/*   Updated: 2026/02/24 15:24:17 by nicorodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_node **stack_a)
{
	if ((*stack_a)->data > (*stack_a)->next->data)
		sa(stack_a);
}

void	sort_three(t_node **stack_a)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->data;
	second = (*stack_a)->next->data;
	third = (*stack_a)->next->next->data;
	if (first > second && second < third && first < third)
		sa(stack_a);
	else if (first > second && second > third)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (first > second && second < third && first > third)
		ra(stack_a);
	else if (first < second && second > third && first < third)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (first < second && second > third && first > third)
		rra(stack_a);
}

void	sort_four(t_node **stack_a, t_node **stack_b)
{
	int	min;

	min = find_min(*stack_a);
	bring_min_to_top(stack_a, min);
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
}

void	sort_five(t_node **stack_a, t_node **stack_b)
{
	int	min1;
	int	min2;

	min1 = find_min(*stack_a);
	bring_min_to_top(stack_a, min1);
	pb(stack_a, stack_b);
	min2 = find_min(*stack_a);
	bring_min_to_top(stack_a, min2);
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	sort_big(t_node **stack_a, t_node **stack_b)
{
	int	min;

	index_stack(*stack_a);
	push_init(stack_a, stack_b);
	sort_three(stack_a);
	while (*stack_b)
	{
		set_target(stack_a, stack_b);
		costs(stack_a, stack_b);
		short_move(stack_a, stack_b);
	}
	min = find_min(*stack_a);
	bring_min_to_top(stack_a, min);
}
