/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:59:25 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/12/07 01:22:38 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

# define STACK_SIZE argc - 1

int		*parse_input(int argc, char **argv);

typedef struct s_stack {
	int stack_size;
	int	*int_list;
	int	top;
}				t_stack;

t_stack *init_b(int arr_len);
t_stack *init_a(int *int_arr, int arr_len);

// STACK UTILS ---------------------------------------
bool	isempty(t_stack *stack);
bool	isfull(t_stack *stack);
void	push(t_stack *stack, int value);
int		pop(t_stack *stack);


// INSTRUCTIONS --------------------------------------
// SWAP ----------------------------------------------
// Swap the first 2 elements of stack a
void	sa(t_stack *a);
// Swap the first 2 elements of stack b
void	sb(t_stack *b);
// sa + sb
void	ss(t_stack *a, t_stack *b);

// PUSH ----------------------------------------------
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);

// ROTATE --------------------------------------------
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

void	insertion_sort(int *int_list, int stack_size);

// SPECIAL CASES -------------------------------------
void	special_case(t_stack *a, t_stack *b);

// FINDS ---------------------------------------------
int		find_midpoint(t_stack *stack, int chunk_start);
int		find_maxpoint(t_stack *stack);

// MOVES -------------------------------------------------------------------
void	move_smaller_top(t_stack *a, t_stack *b, int mid_point);
void	move_smaller_bottom(t_stack *a, t_stack *b, int mid_point);
void	finish_moving(t_stack *a, t_stack *b, int mid_point, int nr_chunks);
bool	ismaxpoint_on_top_half(t_stack *b, int max_point);
void	move_bigger_top(t_stack *b, t_stack *a, int max_point);

// UTILS -----------------------------------
void	free_stacks(t_stack *a, t_stack *b);
void	handle_error(void);

#endif