/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:32:52 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/12/09 18:16:07 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_smaller_top(t_stack *a, t_stack *b, int mid_point)
{
	while (a->storage[a->top] < mid_point)
		pb(a, b);
}

void	move_smaller_bottom(t_stack *a, t_stack *b, int mid_point)
{
	while (a->storage[BOTTOM] < mid_point)
	{
		rra(a, true);
		pb(a, b);
	}
}

void	finish_moving(t_stack *a, t_stack *b, int mid_point, int nr_chunks)
{
	while ((a->top - 1) > (b->top / nr_chunks))
	{
		if (a->storage[a->top] < mid_point)
			pb(a, b);
		else
			ra(a, true);
	}
}

bool	ismaxpoint_on_top_half(t_stack *b, int max_point)
{
	int	i;

	i = b->top;
	while (i > (b->top / 2))
	{
		if (b->storage[i] == max_point)
			return (true);
		i -= 1;
	}
	return (false);
}

void	move_bigger_top(t_stack *b, t_stack *a, int max_point)
{
	if (ismaxpoint_on_top_half(b, max_point))
	{
		while (b->storage[b->top] < max_point)
			rb(b, true);
		pa(a, b);
	}
	else
	{
		while (b->storage[b->top] < max_point)
			rrb(b, true);
		pa(a, b);
	}
}
