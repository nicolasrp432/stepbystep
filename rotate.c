/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasrp <nicolasrp@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 23:35:19 by nicolasrp         #+#    #+#             */
/*   Updated: 2026/02/23 23:35:23 by nicolasrp        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Función estática para rotar hacia arriba (el primero pasa al final) */
static void	rotate(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	// Si está vacía o solo tiene 1 nodo, no hacemos nada
	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = ft_lstlast(*stack); // Usamos tu función de utils_list.c
	
	*stack = first->next;      // El segundo nodo es la nueva cabeza
	first->next = NULL;        // El primer nodo ahora será el último
	last->next = first;        // El antiguo último se engancha al antiguo primero
}

void	ra(t_node **stack_a)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
}

void	rb(t_node **stack_b)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
}