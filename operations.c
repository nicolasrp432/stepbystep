/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicorodr <nicorodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:37:54 by nicorodr          #+#    #+#             */
/*   Updated: 2026/02/24 14:49:11 by nicorodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 2. Lee, valida y guarda los números en la pila */
t_node	*parse_args(int argc, char **argv, int i)
{
	t_node	*stack_a;
	t_node	*new;
	long	nb;

	stack_a = NULL;
	while (i < argc)
	{
		if (!is_valid_arg(argv[i]))
			error_exit(&stack_a, NULL);
		nb = ft_atol(argv[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			error_exit(&stack_a, NULL);
		if (is_duplicate(stack_a, (int)nb))
			error_exit(&stack_a, NULL);
		new = ft_new_node((int)nb);
		if (!new)
			error_exit(&stack_a, NULL);
		ft_lstadd(&stack_a, new);
		i++;
	}
	return (stack_a);
}

/* 3. Libera la memoria de la lista enlazada entera */
void	free_stack(t_node **stack)
{
	t_node	*tmp;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}
