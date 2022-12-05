/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:59:25 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/12/05 01:43:02 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

# define STACK_SIZE argc - 1

void	handle_error(void *to_free);
int		*parse_input(int argc, char **argv);

typedef struct s_stack {
	int stack_size;
	int	*int_list;
	int	top;
}				t_stack;

t_stack *init_b(int arr_len);
t_stack *init_a(int *int_arr, int arr_len);

// STACK UTILS
bool	isempty(t_stack *stack);
bool	isfull(t_stack *stack);
void	push(t_stack *stack, int value);
int		pop(t_stack *stack);

// INSTRUCTIONS

// SWAP
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);

// PUSH
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);

// ROTATE
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

int		find_midpoint(t_stack *stack, int chunk_start);
void	insertion_sort(int *int_list, int stack_size);

#endif