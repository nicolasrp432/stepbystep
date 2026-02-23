/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasrp <nicolasrp@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 23:36:31 by nicolasrp         #+#    #+#             */
/*   Updated: 2026/02/23 23:37:20 by nicolasrp        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Función estática para rotar hacia abajo (el último pasa al principio) */
static void	rev_rotate(t_node **stack)
{
	t_node	*last;
	t_node	*second_last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
		
	// Buscamos el penúltimo nodo
	second_last = *stack;
	while (second_last->next->next != NULL)
		second_last = second_last->next;
		
	last = second_last->next; // El último nodo
	
	second_last->next = NULL; // El penúltimo ahora es el último
	last->next = *stack;      // El último ahora apunta al primero
	*stack = last;            // La pila ahora empieza por el que era el último
}

void	rra(t_node **stack_a)
{
	rev_rotate(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_node **stack_b)
{
	rev_rotate(stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	write(1, "rrr\n", 4);
}
