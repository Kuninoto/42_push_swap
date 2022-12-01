/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:53:35 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/11/30 21:20:00 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_stack *a)
{
	int	save_first;
	int	i;

	save_first = a->int_list[a->top];
	i = a->top;
	while (i > 0)
	{
		a->int_list[i] = a->int_list[i - 1];
		i--;
	}
	a->int_list[i] = save_first;
}

void	rb(t_stack *b)
{
	int	save_first;
	int	i;

	save_first = b->int_list[b->top];
	i = b->top;
	while (i > 0)
	{
		b->int_list[i] = b->int_list[i - 1];
		i--;
	}
	b->int_list[i] = save_first;
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
}

void	rra(t_stack *a)
{
	int	save_last;
	int	i;

	save_last = a->int_list[0];
	i = 0;
	while (i < a->top)
	{
		a->int_list[i] = a->int_list[i + 1];
		i++;
	}
	a->int_list[i] = save_last;
}

void	rrb(t_stack *b)
{
	int	save_last;
	int	i;

	save_last = b->int_list[0];
	i = 0;
	while (i < b->top)
	{
		b->int_list[i] = b->int_list[i + 1];
		i++;
	}
	b->int_list[i] = save_last;
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
}
