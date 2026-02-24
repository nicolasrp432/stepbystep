/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicorodr <nicorodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 13:47:50 by nicorodr          #+#    #+#             */
/*   Updated: 2026/02/24 14:26:27 by nicorodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Busca y devuelve el VALOR más pequeño de la pila */
int	find_min(t_node *stack)
{
	int	min;

	min = stack->data;
	while (stack)
	{
		if (stack->data < min)
			min = stack->data;
		stack = stack->next;
	}
	return (min);
}

/* Sube el número 'min' a la cima usando el camino más corto */
void	bring_min_to_top(t_node **stack_a, int min)
{
	t_node	*tmp;
	int		pos;
	int		size;

	tmp = *stack_a;
	pos = 0;
	while (tmp->data != min)
	{
		pos++;
		tmp = tmp->next;
	}
	size = stack_size(*stack_a);
	if (pos <= size / 2)
	{
		while ((*stack_a)->data != min)
			ra(stack_a);
	}
	else
	{
		while ((*stack_a)->data != min)
			rra(stack_a);
	}
}

/* Le asigna a cada nodo un 'index' del 0 al tamaño de la pila.
   El número más pequeño de todos tendrá el index 0. */
void	index_stack(t_node *stack)
{
	t_node	*ptr1;
	t_node	*ptr2;
	int		index;

	ptr1 = stack;
	while (ptr1)
	{
		index = 0;
		ptr2 = stack;
		while (ptr2)
		{
			if (ptr2->data < ptr1->data)
				index++;
			ptr2 = ptr2->next;
		}
		ptr1->index = index;
		ptr1 = ptr1->next;
	}
}
