/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:09:05 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/12/07 21:52:40 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

void	sa(t_stack *a)
{
	int	temp;

	if (isempty(a) || a->top == 0)
		return ;
	temp = a->int_list[a->top - 1];
	a->int_list[a->top - 1] = a->int_list[a->top];
	a->int_list[a->top] = temp;
}

void	sb(t_stack *b)
{
	int	temp;

	if (isempty(b) || b->top == 0)
		return ;
	temp = b->int_list[b->top - 1];
	b->int_list[b->top - 1] = b->int_list[b->top];
	b->int_list[b->top] = temp;
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
}

void	pa(t_stack *a, t_stack *b)
{
	if (isempty(b))
		return ;
	push(a, pop(b));
}

void	pb(t_stack *a, t_stack *b)
{
	if (isempty(a))
		return ;
	push(b, pop(a));
}
 