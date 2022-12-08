/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:59:25 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/12/08 01:39:10 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

// STACK ----------------------------------

typedef struct s_stack {
	int	stack_size;
	int	*int_list;
	int	top;
}				t_stack;

// STACK INITIALIZERS ---------------------

// Initializes stack a
static inline t_stack	init_a(int arr_len)
{
	return ((t_stack){
		.stack_size = arr_len,
		.int_list = malloc(arr_len * sizeof(int)),
		.top = -1
	});
}

// Initializes stack b
static inline t_stack	init_b(int arr_len)
{
	return ((t_stack){
		.stack_size = arr_len,
		.int_list = malloc(arr_len * sizeof(int)),
		.top = -1
	});
}

int		*parse_input(int argc, char **argv, t_stack *a, t_stack *b);

// STACK UTILS ---------------------------------------

// Fills stack a with input values
void	fill_a(t_stack *a, int *int_arr, int arr_len);
// Checks if the stack passed as parameter is empty
bool	isempty(t_stack *stack);
// Checks if the stack passed as parameter is full
bool	isfull(t_stack *stack);
// Pushes the parameter value to the top of the stack
void	push(t_stack *stack, int value);
// Pops and returns the top element from the stack 
int		pop(t_stack *stack);

// INSTRUCTIONS --------------------------------------
// SWAP ----------------------------------------------

// Swaps the first 2 elements of stack a
void	sa(t_stack *a, bool print_instruction);
// Swaps the first 2 elements of stack b
void	sb(t_stack *b, bool print_instruction);
// Swaps the first 2 elements of stack a and b
void	ss(t_stack *a, t_stack *b);

// PUSH -----------------------------------

// Pops the top element of stack b into stack a
void	pa(t_stack *a, t_stack *b);
// Pops the top element of stack a into stack b
void	pb(t_stack *a, t_stack *b);

// ROTATE ---------------------------------

// Shifts up all elements on stack a by 1
void	ra(t_stack *a, bool print_instruction);
// Shifts up all elements on stack b by 1
void	rb(t_stack *b, bool print_instruction);
// ra + rb
void	rr(t_stack *a, t_stack *b);
// Shifts down all elements on stack a by 1
void	rra(t_stack *a, bool print_instruction);
// Shifts down all elements on stack b by 1
void	rrb(t_stack *b, bool print_instruction);
// ra + rb
void	rrr(t_stack *a, t_stack *b);

// SPECIAL CASES -------------------------------------
void	special_case(t_stack *a, t_stack *b);

// FINDS ---------------------------------------------
int		find_midpoint(t_stack *stack, int chunk_start);
int		find_maxpoint(t_stack *stack);

// MOVES -------------------------------------------------------------------

/* 
Enters by the top of stack a and 
moves every number smaller than mid_point to stack b
*/
void	move_smaller_top(t_stack *a, t_stack *b, int mid_point);
void	move_smaller_bottom(t_stack *a, t_stack *b, int mid_point);
void	finish_moving(t_stack *a, t_stack *b, int mid_point, int nr_chunks);
bool	ismaxpoint_on_top_half(t_stack *b, int max_point);
void	move_bigger_top(t_stack *b, t_stack *a, int max_point);

// UTILS ----------------------------------------

// Frees both integer arrays inside stack a and b
void	free_arrays(t_stack *a, t_stack *b);
// Prints an error message on stderror and exits on failure
void	handle_error(void);
void	insertion_sort(int *int_list, int stack_size);

#endif