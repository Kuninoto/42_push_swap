/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 19:39:38 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/12/02 14:13:21 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	isempty(t_stack *stack)
{
	if (stack->top == -1)
		return (true);
	else
		return (false);
} 

bool	isfull(t_stack *stack)
{
	if (stack->top == stack->stack_size)
		return true;
	else
		return false;
}

void	push(t_stack *stack, int value)
{
	if (!isfull(stack))
	{
		stack->top++;
		stack->int_list[stack->top] = value;
	}
	else 
		return;
}

int		pop(t_stack *stack)
{
	int		popped_value;

	if (!isempty(stack))
	{
		popped_value = stack->int_list[stack->top];
		stack->top--;
		return (popped_value);
	}
	else
		ft_printf("Can't pop from an empty stack\n");
	exit(EXIT_FAILURE);
}