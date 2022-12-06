/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:32:52 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/12/06 17:35:08 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// moves every number smaller than mid point to stack b
void	move_smaller_top(t_stack *a, t_stack *b, int mid_point)
{
	while (a->int_list[a->top] < mid_point)
		pb(a, b);
}

void	move_smaller_bottom(t_stack *a, t_stack *b, int mid_point)
{
	while (a->int_list[0] < mid_point)
	{
		rra(a);
		pb(a, b);
	}
}

void	finish_moving(t_stack *a, t_stack *b, int mid_point, int nr_chunks)
{
	while ((a->top - 1) > (b->top / nr_chunks))
	{
		if (a->int_list[a->top] < mid_point)
			pb(a, b);
		else
			ra(a);
	}
}

bool	ismaxpoint_on_top_half(t_stack *b, int max_point)
{
	int	i;

	i = b->top;
	while (i > (b->top / 2))
	{
		if (b->int_list[i] == max_point)
			return (true);
		i--;
	}
	return (false);
}

// finds b top, sends to a and reverses rb actions
void	move_bigger_top(t_stack *b, t_stack *a, int max_point)
{
	if (ismaxpoint_on_top_half(b, max_point))
	{
		while (b->int_list[b->top] < max_point)
			rb(b);
		pa(a, b);
	}
	else
	{
		while (b->int_list[b->top] < max_point)
			rrb(b);
		pa(a, b);
	}
}
