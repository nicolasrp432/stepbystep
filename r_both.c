/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_both.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicorodr <nicorodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 15:13:19 by nicorodr          #+#    #+#             */
/*   Updated: 2026/02/24 15:14:52 by nicorodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Hace 'rr' (rotar ambas arriba) mientras ambos costes sean positivos */
void	rot_both(t_node **stack_a, t_node **stack_b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		rr(stack_a, stack_b);
	}
}


/* Hace 'rrr' (rotar ambas abajo) mientras ambos costes sean negativos */
void	rev_rot_both(t_node **stack_a, t_node **stack_b, int *cost_a,
	int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		rrr(stack_a, stack_b);
	}
}
