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

#include "../../../includes/push_swap.h"

bool	ok_sa(t_stack *a)
{
	if (isempty(a))
		return (false);
	if (a->int_list[a->top] > a->int_list[a->top - 1])
		return (true);
	else
		return (false);
}

bool	ok_sb(t_stack *b)
{
	if (isempty(b))
		return (false);
	if (b->int_list[b->top] > b->int_list[b->top - 1])
		return (true);
	else
		return (false);
}

bool	ok_ra(t_stack *a)
{
	if (isempty(a))
		return (false);
	if (a->int_list[a->top] > a->int_list[0])
		return (true);
	else
		return (false);
}

bool	ok_rb(t_stack *b)
{
	if (isempty(b))
		return (false);
	if (b->int_list[b->top] > b->int_list[0])
		return (true);
	else
		return (false);
}
