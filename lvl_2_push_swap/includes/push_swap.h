/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:59:25 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/12/09 18:49:08 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

// STACK ----------------------------------

typedef struct s_stack {
	int	stack_size;
	int	*storage;
	int	top;
}				t_stack;

# define BOTTOM 0

// Initializes stack a
static inline t_stack	init_stack(int arr_len)
{
	return ((t_stack){
		.stack_size = arr_len,
		.storage = malloc(arr_len * sizeof(int)),
		.top = -1
	});
}

// STACK UTILS ---------------------------------------

// Fills stack a with input values
void	fill_a(t_stack *a, int argc, char **argv);

// Checks if stack is empty
bool	is_empty(t_stack *stack);

// Checks if stack is full
bool	is_full(t_stack *stack);

// Checks if stack is sorted
bool	is_sorted(t_stack *stack);

// Finds the max value within the stack
int		max(t_stack *stack);

// Pushes A value to the top of the stack
void	push(t_stack *stack, int value);

// Pops and returns the top element from the stack 
int		pop(t_stack *stack);

// INSTRUCTIONS --------------------------------------
// SWAP ----------------------------------------------

// Swaps the first 2 elements of stack a
void	sa(t_stack *a, bool print_instruction);
// Swaps the first 2 elements of stack b
void	sb(t_stack *b, bool print_instruction);
// sa + sb
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

// CHECKS ------------------------------------

bool	ok_sa(t_stack *a);
bool	ok_sb(t_stack *b);

bool	ok_ra(t_stack *a);
bool	ok_rb(t_stack *b);

bool	ok_rra(t_stack *a);
bool	ok_rrb(t_stack *b);

bool	ok_ss(t_stack *a, t_stack *b);
bool	ok_rr(t_stack *a, t_stack *b);
bool	ok_rrr(t_stack *a, t_stack *b);

// SPECIAL CASES -------------------------------------
void	special_case(t_stack *a);

// MOVES -------------------------------------------------------------------

/*
Starting by the top of stack a
moves every number smaller than mid_point to stack b
*/
void	move_smaller_top(t_stack *a, t_stack *b, int mid_point);
/*
Starting by the bottom of stack a
moves every number smaller than mid_point to stack b
*/
void	move_smaller_bottom(t_stack *a, t_stack *b, int mid_point);

void	finish_moving(t_stack *a, t_stack *b, int mid_point, int nr_chunks);
bool	ismaxpoint_on_top_half(t_stack *b, int max_point);
void	move_bigger_top(t_stack *b, t_stack *a, int max_point);

// UTILS ----------------------------------------

// Frees both stack storages
void	free_stacks(t_stack *a, t_stack *b);

// Frees both stack storages if they're not NULL
// prints Error to STDERR and exit on EXIT_FAILURE
void	panic(t_stack *a, t_stack *b);

void	insertion_sort(int *storage, int stack_size);
void	midpoint_sort(t_stack *a, t_stack *b);
void	radix_sort(t_stack *a, t_stack *b);

#endif // PUSH_SWAP_H