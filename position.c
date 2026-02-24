/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicorodr <nicorodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 14:42:28 by nicorodr          #+#    #+#             */
/*   Updated: 2026/02/24 14:46:47 by nicorodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 1. Asigna a cada nodo su posición actual en la pila (0, 1, 2, 3...) */
void	set_position(t_node **stack)
{
	t_node	*tmp;
	int		i;

	i = 0;
	tmp = *stack;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}

/* 2. Busca la posición del número más pequeño en la Pila A
(Regla de Excepción) */
static int	find_min_position(t_node *stack_a)
{
	int		min_index;
	int		min_pos;
	t_node	*tmp;

	tmp = stack_a;
	min_index = INT_MAX;
	min_pos = 0;
	while (tmp)
	{
		if (tmp->index < min_index)
		{
			min_index = tmp->index;
			min_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (min_pos);
}

/* 3. Busca la posición del número inmediatamente superior (Regla Principal) */
static int	find_target_position(t_node *stack_a, int b_index)
{
	int		min_diff;
	int		target_pos;
	t_node	*tmp;

	min_diff = INT_MAX;
	target_pos = -1;
	tmp = stack_a;
	while (tmp)
	{
		if (tmp->index > b_index && (tmp->index - b_index) < min_diff)
		{
			min_diff = tmp->index - b_index;
			target_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (target_pos);
}

void	set_target(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp_b;
	int		target_pos;

	set_position(stack_a);
	set_position(stack_b);
	tmp_b = *stack_b;
	while (tmp_b)
	{
		target_pos = find_target_position(*stack_a, tmp_b->index);
		if (target_pos == -1)
			target_pos = find_min_position(*stack_a);
		tmp_b->target = target_pos;
		tmp_b = tmp_b->next;
	}
}
