/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicorodr <nicorodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 14:27:07 by nicorodr          #+#    #+#             */
/*   Updated: 2026/02/24 15:18:32 by nicorodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Empuja todo a la pila B hasta que solo queden 3 nodos en la A */
void	push_init(t_node **stack_a, t_node **stack_b)
{
	int	size;

	size = stack_size(*stack_a);
	while (size > 3)
	{
		pb(stack_a, stack_b);
		size--;
	}
}

/* Devuelve el valor absoluto de un número (si es -5, devuelve 5).
   Nos sirve para sumar la cantidad real de movimientos. */
int	is_negative(int nbr)
{
	if (nbr < 0)
		return (nbr * -1);
	else
		return (nbr);
}

/* Ejecuta los movimientos óptimos para el nodo elegido */
void	cheap_moves(t_node **stack_a, t_node **stack_b, int cost_a, int cost_b)
{
	if (cost_a > 0 && cost_b > 0)
		rot_both(stack_a, stack_b, &cost_a, &cost_b);
	else if (cost_a < 0 && cost_b < 0)
		rev_rot_both(stack_a, stack_b, &cost_a, &cost_b);
	rot_a(stack_a, &cost_a);
	rot_b(stack_b, &cost_b);
	pa(stack_a, stack_b);
}
