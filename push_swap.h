/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicorodr <nicorodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 12:31:04 by nicorodr          #+#    #+#             */
/*   Updated: 2026/02/24 15:20:03 by nicorodr         ###   ########.fr       */
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
int		find_min(t_node *stack);
void	bring_min_to_top(t_node **stack_a, int min);

// Funciones de listas (lists_utils.c)
t_node	*ft_new_node(int data);
t_node	*ft_lstlast(t_node *lst);
void	ft_lstadd(t_node **stack, t_node *new);
int		stack_size(t_node *stack);

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
void	ra(t_node **stack_a);
void	rb(t_node **stack_b);
void	rr(t_node **stack_a, t_node **stack_b);
void	rra(t_node **stack_a);
void	rrb(t_node **stack_b);
void	rrr(t_node **stack_a, t_node **stack_b);

//Sorts
void	sort_two(t_node **stack_a);
void	sort_three(t_node **stack_a);
void	sort_four(t_node **stack_a, t_node **stack_b);
void	sort_five(t_node **stack_a, t_node **stack_b);
void	sort_stacks(t_node **stack_a, t_node **stack_b);

//Big Sorts
void	index_stack(t_node *stack);
void	push_init(t_node **stack_a, t_node **stack_b);
void	sort_big(t_node **stack_a, t_node **stack_b);
void	set_position(t_node **stack);
void	set_target(t_node **stack_a, t_node **stack_b);
void	costs(t_node **stack_a, t_node **stack_b);
void	rot_a(t_node **stack_a, int *cost);
void	rot_b(t_node **stack_b, int *cost);
int		is_negative(int nbr);
void	rot_both(t_node **stack_a, t_node **stack_b, int *cost_a, int *cost_b);
void	rev_rot_both(t_node **stack_a, t_node **stack_b,
			int *cost_a, int *cost_b);
void	short_move(t_node **stack_a, t_node **stack_b);
void	cheap_moves(t_node **stack_a, t_node **stack_b, int cost_a, int cost_b);

#endif