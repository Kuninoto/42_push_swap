/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:09:05 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/11/30 20:34:24 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//	MISSING DO NOTHING CONDITION

// Swap the first 2 elements of stack a
void	sa(t_stack *a)
{
	int	temp;

	temp = a->int_list[a->top - 1];
	a->int_list[a->top - 1] = a->int_list[a->top];
	a->int_list[a->top] = temp;
}

// Swap the first 2 elements of stack b
void	sb(t_stack *b)
{
	int	temp;

	temp = b->int_list[b->top + 1];
	b->int_list[b->top + 1] = b->int_list[b->top];
	b->int_list[b->top] = temp;
}

// sa + sb
void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
}

void	pa(t_stack *a, t_stack *b)
{
	push(a, pop(b));
}

void	pb(t_stack *a, t_stack *b)
{
	push(b, pop(a));
}
