/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicorodr <nicorodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:55:05 by nicorodr          #+#    #+#             */
/*   Updated: 2026/02/23 15:55:13 by nicorodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Función base estática para mover un nodo de src a dest */
static void	push(t_node **src, t_node **dest)
{
	t_node	*tmp;

	// Si la pila de origen está vacía, no hay nada que empujar
	if (!src || !*src)
		return ;

	tmp = *src;               // Guardamos el primer nodo de origen
	*src = (*src)->next;      // El origen ahora empieza en el segundo nodo

	tmp->next = *dest;        // El nodo extraído apunta al antiguo inicio de destino
	*dest = tmp;              // El destino ahora empieza con el nodo extraído
}

void	pa(t_node **stack_a, t_node **stack_b)
{
	push(stack_b, stack_a); // OJO: 'pa' coge de B y lo pone en A
	write(1, "pa\n", 3);
}

void	pb(t_node **stack_a, t_node **stack_b)
{
	push(stack_a, stack_b); // OJO: 'pb' coge de A y lo pone en B
	write(1, "pb\n", 3);
}