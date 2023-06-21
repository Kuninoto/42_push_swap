/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 19:39:38 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/12/07 03:39:27 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_empty(t_stack *stack)
{
	if (stack->top == -1)
		return (true);
	else
		return (false);
}

bool	is_full(t_stack *stack)
{
	if (stack->top == (stack->stack_size - 1))
		return (true);
	else
		return (false);
}

void	push(t_stack *stack, int value)
{
	if (!is_full(stack))
	{
		stack->top += 1;
		stack->storage[stack->top] = value;
	}
}

int	pop(t_stack *stack)
{
	int	retrieved_value;

	retrieved_value = stack->storage[stack->top];
	stack->top -= 1;
	return (retrieved_value);
}
