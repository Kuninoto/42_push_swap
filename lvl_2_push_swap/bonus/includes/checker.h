/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 01:12:58 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/12/07 03:34:21 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../../libft/libft.h"
# define STACK_SIZE argc - 1

int			*parse_input(int argc, char **argv);

// STACK ----------------------------------

typedef struct s_stack {
	int	stack_size;
	int	*int_list;
	int	top;
}				t_stack;

// STACK INITIALIZERS ---------------------
t_stack		*init_b(int arr_len);
t_stack		*init_a(int *int_arr, int arr_len);

// STACK UTILS ----------------------------

// Checks if the stack passed as parameter is empty
bool		isempty(t_stack *stack);
// Checks if the stack passed as parameter is full
bool		isfull(t_stack *stack);
// Pushes the parameter value to the top of the stack
void		push(t_stack *stack, int value);
// Pops and returns the top element from the stack 
int			pop(t_stack *stack);

// INSTRUCTIONS ---------------------------
// SWAP -----------------------------------

// Swaps the first 2 elements of stack a
void		sa(t_stack *a);
// Swaps the first 2 elements of stack b
void		sb(t_stack *b);
// Swaps the first 2 elements of stack a and b
void		ss(t_stack *a, t_stack *b);

// PUSH -----------------------------------
// Pops the top element of stack b into stack a
void		pa(t_stack *a, t_stack *b);
// Pops the top element of stack a into stack b
void		pb(t_stack *a, t_stack *b);

// ROTATE ---------------------------------

// Shifts up all elements on stack a by 1
void		ra(t_stack *a);
// Shifts up all elements on stack b by 1
void		rb(t_stack *b);
// ra + rb
void		rr(t_stack *a, t_stack *b);
// Shifts down all elements on stack a by 1
void		rra(t_stack *a);
// Shifts down all elements on stack b by 1
void		rrb(t_stack *b);
// ra + rb
void		rrr(t_stack *a, t_stack *b);

// UTILS ----------------------------------------

// Frees both integer arrays and stack structures
void		free_stacks(t_stack *a, t_stack *b);
// Prints an error message on stderror and exits on failure
void		handle_error(void);
void		insertion_sort(int *int_list, int stack_size);

// VECTOR ---------------------------------------

typedef struct s_vector {
	size_t	count;		// Number of elements currently on the vector
	size_t	capacity;	// Maximum capacity of the vector
	char	**storage;
}				t_vector;

// VECTOR UTILS ---------------------------------

// Generates a new, empty vector with the capacity of 1 
t_vector	*vec_new(void);
// Push an instruction to the vector
void		vec_push(t_vector *vector, char	*instruction);
// Pops an instruction from the vector
char		*vec_pop(t_vector *vector);
// Frees vector and returns a new one that has the double capacity
t_vector	*vec_realloc(t_vector *vector);
// Free a vector and all its inside fields
void		free_vec(t_vector *vector);

#endif