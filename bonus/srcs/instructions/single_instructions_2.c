/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_instructions_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 01:50:20 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/12/08 01:51:26 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ra(t_stack *a)
{
	int	save_first;
	int	i;

	if (is_empty(a))
		return ;
	save_first = a->storage[a->top];
	i = a->top;
	while (i > 0)
	{
		a->storage[i] = a->storage[i - 1];
		i -= 1;
	}
	a->storage[0] = save_first;
}

void	rb(t_stack *b)
{
	int	save_first;
	int	i;

	if (is_empty(b))
		return ;
	save_first = b->storage[b->top];
	i = b->top;
	while (i > 0)
	{
		b->storage[i] = b->storage[i - 1];
		i -= 1;
	}
	b->storage[0] = save_first;
}

void	rra(t_stack *a)
{
	int	save_last;
	int	i;

	if (is_empty(a))
		return ;
	save_last = a->storage[0];
	i = 0;
	while (i < a->top)
	{
		a->storage[i] = a->storage[i + 1];
		i += 1;
	}
	a->storage[a->top] = save_last;
}

void	rrb(t_stack *b)
{
	int	save_last;
	int	i;

	if (is_empty(b))
		return ;
	save_last = b->storage[0];
	i = 0;
	while (i < b->top)
	{
		b->storage[i] = b->storage[i + 1];
		i += 1;
	}
	b->storage[b->top] = save_last;
}
