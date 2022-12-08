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

#include "../../includes/checker.h"

void	ra(t_stack *a)
{
	int	save_first;
	int	i;

	if (isempty(a))
		return ;
	save_first = a->int_list[a->top];
	i = a->top;
	while (i > 0)
	{
		a->int_list[i] = a->int_list[i - 1];
		i--;
	}
	a->int_list[0] = save_first;
}

void	rb(t_stack *b)
{
	int	save_first;
	int	i;

	if (isempty(b))
		return ;
	save_first = b->int_list[b->top];
	i = b->top;
	while (i > 0)
	{
		b->int_list[i] = b->int_list[i - 1];
		i--;
	}
	b->int_list[0] = save_first;
}

void	rra(t_stack *a)
{
	int	save_last;
	int	i;

	if (isempty(a))
		return ;
	save_last = a->int_list[0];
	i = 0;
	while (i < a->top)
	{
		a->int_list[i] = a->int_list[i + 1];
		i++;
	}
	a->int_list[a->top] = save_last;
}

void	rrb(t_stack *b)
{
	int	save_last;
	int	i;

	if (isempty(b))
		return ;
	save_last = b->int_list[0];
	i = 0;
	while (i < b->top)
	{
		b->int_list[i] = b->int_list[i + 1];
		i++;
	}
	b->int_list[b->top] = save_last;
}
