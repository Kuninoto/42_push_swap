/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_instructions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:09:05 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/12/08 01:46:57 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	if (isempty(b))
		return ;
	push(a, pop(b));
	write(STDOUT_FILENO, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	if (isempty(a))
		return ;
	push(b, pop(a));
	write(STDOUT_FILENO, "pb\n", 3);
}

void	sa(t_stack *a, bool print_instruction)
{
	int	temp;

	if (isempty(a) || a->top == 0)
		return ;
	temp = a->int_list[a->top - 1];
	a->int_list[a->top - 1] = a->int_list[a->top];
	a->int_list[a->top] = temp;
	if (print_instruction)
		write(STDOUT_FILENO, "sa\n", 3);
}

void	sb(t_stack *b, bool print_instruction)
{
	int	temp;

	if (isempty(b) || b->top == 0)
		return ;
	temp = b->int_list[b->top - 1];
	b->int_list[b->top - 1] = b->int_list[b->top];
	b->int_list[b->top] = temp;
	if (print_instruction)
		write(STDOUT_FILENO, "sb\n", 3);
}
