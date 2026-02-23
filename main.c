/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicorodr <nicorodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 13:46:55 by nicorodr          #+#    #+#             */
/*   Updated: 2026/02/23 15:10:50 by nicorodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	one_arg(t_node **stack_a, char **argv)
{
	int		count;
	char	**split;

	count = 0;
	split = ft_split(argv[1], ' ');

	while (split[count])
		count++;
	*stack_a = parse_args(count, split, 0);
	free_split(split);
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	if (argc == 2)
		one_arg(&stack_a, argv);
	else
		stack_a = parse_args(argc, argv, 1);
	if (!stack_a)
		error_exit(&stack_a, NULL);
	if (is_sorted(stack_a))
	{
		free_stack(&stack_a);
		return (0);
	}

	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}

void	free_split(char **str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
