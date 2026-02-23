/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicorodr <nicorodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 12:31:04 by nicorodr          #+#    #+#             */
/*   Updated: 2026/02/23 15:56:50 by nicorodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdint.h>
# include <limits.h>

typedef struct s_node
{
	int				data;
	int				index;
	int				pos;
	int				target;
	int				cost_a;
	int				cost_b;
	struct s_node	*next;
}	t_node;

// Funciones de validación y utils (utils.c / lists_utils.c)
int		is_valid_arg(char *str);
long	ft_atol(char *str);
int		is_duplicate(t_node *stack, int value);
void	error_exit(t_node **stack_a, t_node **stack_b);
t_node	*parse_args(int argc, char **argv, int i);
void	free_stack(t_node **stack);
int		is_sorted(t_node *stack);

// Funciones de listas (lists_utils.c)
t_node	*ft_new_node(int data);
t_node	*ft_lstlast(t_node *lst);
void	ft_lstadd(t_node **stack, t_node *new);

// Funciones de split y main
char	**ft_split(const char *s, char c);
void	free_split(char **str);
void	one_arg(t_node **stack_a, char **argv);

// Operaciones
void	sa(t_node **stack_a);
void	sb(t_node **stack_b);
void	ss(t_node **stack_a, t_node **stack_b);
void	pa(t_node **stack_a, t_node **stack_b);
void	pb(t_node **stack_a, t_node **stack_b);

#endif