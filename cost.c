/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicorodr <nicorodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 14:59:29 by nicorodr          #+#    #+#             */
/*   Updated: 2026/02/24 15:17:12 by nicorodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 1. Calcula el coste de mover un nodo de B a la cima,
 y su Target de A a la cima */
void	costs(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp_b;
	int		size_a;
	int		size_b;

	tmp_b = *stack_b;
	size_a = stack_size(*stack_a);
	size_b = stack_size(*stack_b);
	while (tmp_b)
	{
		tmp_b->cost_b = tmp_b->pos;
		if (tmp_b->pos > size_b / 2)
			tmp_b->cost_b = (size_b - tmp_b->pos) * -1;
		tmp_b->cost_a = tmp_b->target;
		if (tmp_b->target > size_a / 2)
			tmp_b->cost_a = (size_a - tmp_b->target) * -1;
		tmp_b = tmp_b->next;
	}
}

/* 2. Ejecuta los movimientos necesarios en A según el coste */
void	rot_a(t_node **stack_a, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			ra(stack_a);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			rra(stack_a);
			(*cost)++;
		}
	}
}

/* 3. Ejecuta los movimientos necesarios en B según el coste */
void	rot_b(t_node **stack_b, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			rb(stack_b);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			rrb(stack_b);
			(*cost)++;
		}
	}
}

/* Busca el nodo en B con el coste total menor
y manda ejecutar sus movimientos */
void	short_move(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;
	int		cheap;
	int		cost_a;
	int		cost_b;

	tmp = *stack_b;
	cheap = INT_MAX;
	while (tmp)
	{
		if (is_negative(tmp->cost_a) + is_negative(tmp->cost_b) < cheap)
		{
			cheap = is_negative(tmp->cost_a) + is_negative(tmp->cost_b);
			cost_a = tmp->cost_a;
			cost_b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	cheap_moves(stack_a, stack_b, cost_a, cost_b);
}
