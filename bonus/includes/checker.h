/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 01:12:58 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/12/08 02:09:30 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../../libft/libft.h"

// STACK ----------------------------------

typedef struct s_stack {
	int	stack_size;
	int	*storage;
	int	top;
}				t_stack;

// STACK INITIALIZERS ---------------------

// Initializes stack a
static inline t_stack	init_a(int arr_len)
{
	return ((t_stack){
		.stack_size = arr_len,
		.storage = malloc(arr_len * sizeof(int)),
		.top = -1
	});
}

// Initializes stack b
static inline t_stack	init_b(int arr_len)
{
	return ((t_stack){
		.stack_size = arr_len,
		.storage = malloc(arr_len * sizeof(int)),
		.top = -1
	});
}

int		*parse_input(t_stack *a, int argc, char **argv);

// STACK UTILS ----------------------------

// Fills stack a with input values
void	fill_a(t_stack *a, int *int_arr, int arr_len);

// Checks if the stack passed as parameter is empty
bool	is_empty(t_stack *stack);

// Checks if the stack passed as parameter is full
bool	is_full(t_stack *stack);

// Checks if the stack is sorted from the smallest (on top)
// to the biggest at the bottom
bool	is_sorted(t_stack *stack);

// Pushes the parameter value to the top of the stack
void	push(t_stack *stack, int value);

// Pops and returns the top element from the stack 
int		pop(t_stack *stack);

// INSTRUCTIONS ---------------------------
// SWAP -----------------------------------

// Swaps the first 2 elements of stack a
void	sa(t_stack *a);
// Swaps the first 2 elements of stack b
void	sb(t_stack *b);
// Swaps the first 2 elements of stack a and b
void	ss(t_stack *a, t_stack *b);

// PUSH ---------------------------------------

// Pops the top element of stack b into stack a
void	pa(t_stack *a, t_stack *b);
// Pops the top element of stack a into stack b
void	pb(t_stack *a, t_stack *b);

// ROTATE ---------------------------------

// Shifts up all elements on stack a by 1
void	ra(t_stack *a);
// Shifts up all elements on stack b by 1
void	rb(t_stack *b);
// ra + rb
void	rr(t_stack *a, t_stack *b);
// Shifts down all elements on stack a by 1
void	rra(t_stack *a);
// Shifts down all elements on stack b by 1
void	rrb(t_stack *b);
// ra + rb
void	rrr(t_stack *a, t_stack *b);

// UTILS ----------------------------------------

// Frees integer array inside a and b  
void	free_stacks(t_stack *a, t_stack *b);
void	insertion_sort(int *storage, int stack_size);

// Frees both stack storages, prints "Error" to STDERR
// and returns EXIT_FAILURE
void	panic(t_stack *a, t_stack *b);

#endif // CHECKER_H