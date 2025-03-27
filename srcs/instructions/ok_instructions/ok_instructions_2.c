/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ok_instructions_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:46:37 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/12/08 20:55:40 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ok_rra(t_stack *a)
{
	if (is_empty(a))
		return (false);
	if (a->storage[BOTTOM] < a->storage[a->top])
		return (true);
	else
		return (false);
}

bool	ok_rrb(t_stack *b)
{
	if (is_empty(b))
		return (false);
	if (b->storage[BOTTOM] < b->storage[b->top])
		return (true);
	else
		return (false);
}

bool	ok_rrr(t_stack *a, t_stack *b)
{
	if (ok_rra(a) && ok_rra(b))
		return (true);
	else
		return (false);
}

bool	ok_ss(t_stack *a, t_stack *b)
{
	if (ok_sa(a) && ok_sb(b))
		return (true);
	else
		return (false);
}

bool	ok_rr(t_stack *a, t_stack *b)
{
	if (ok_ra(a) && ok_rb(b))
		return (true);
	else
		return (false);
}
