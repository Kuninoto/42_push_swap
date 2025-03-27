/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_instructions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:09:05 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/12/08 01:49:26 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sa(t_stack *a)
{
	int	temp;

	if (is_empty(a) || a->top == 0)
		return ;
	temp = a->storage[a->top - 1];
	a->storage[a->top - 1] = a->storage[a->top];
	a->storage[a->top] = temp;
}

void	sb(t_stack *b)
{
	int	temp;

	if (is_empty(b) || b->top == 0)
		return ;
	temp = b->storage[b->top - 1];
	b->storage[b->top - 1] = b->storage[b->top];
	b->storage[b->top] = temp;
}

void	pa(t_stack *a, t_stack *b)
{
	if (is_empty(b))
		return ;
	push(a, pop(b));
}

void	pb(t_stack *a, t_stack *b)
{
	if (is_empty(a))
		return ;
	push(b, pop(a));
}
 