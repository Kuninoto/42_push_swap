/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 01:12:58 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/12/07 21:41:23 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../../libft/libft.h"

int		*parse_input(int argc, char **argv);

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

// STACK UTILS ----------------------------

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

// Frees both integer arrays and stack structures
void	free_stacks(t_stack *a, t_stack *b);
// Prints an error message on stderror and exits on failure
void	handle_error(void);
void	insertion_sort(int *int_list, int stack_size);

// VECTOR ---------------------------------------

typedef struct s_vector {
	size_t	count;
	size_t	capacity;
	char	**storage;
}				t_vector;

// VECTOR UTILS ---------------------------------

// Returns an empty vector with the capacity of 1
static inline t_vector	vec_new(void)
{
	return ((t_vector){
		.count = 0,
		.capacity = 1,
		.storage = malloc(sizeof(char *))
	});
}

// Push an instruction to the vector
void	vec_push(t_vector *vector, char	*instruction);
// Pops an instruction from the vector
char	*vec_pop(t_vector *vector);
// Doubles vector storage capacity
void	vec_realloc(t_vector *vector);
// Free a vector and all its inside fields
void	free_vec(t_vector *vector);

#endif