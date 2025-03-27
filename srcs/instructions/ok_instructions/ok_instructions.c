/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ok_instructions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:27:46 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/12/08 21:04:45 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ok_sa(t_stack *a)
{
	if (is_empty(a))
		return (false);
	if (a->storage[a->top] > a->storage[a->top - 1])
		return (true);
	else
		return (false);
}

bool	ok_sb(t_stack *b)
{
	if (is_empty(b))
		return (false);
	if (b->storage[b->top] > b->storage[b->top - 1])
		return (true);
	else
		return (false);
}

bool	ok_ra(t_stack *a)
{
	if (is_empty(a))
		return (false);
	if (a->storage[a->top] > a->storage[BOTTOM])
		return (true);
	else
		return (false);
}

bool	ok_rb(t_stack *b)
{
	if (is_empty(b))
		return (false);
	if (b->storage[b->top] > b->storage[BOTTOM])
		return (true);
	else
		return (false);
}
