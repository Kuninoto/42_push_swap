/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_instructions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:53:35 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/12/08 01:50:57 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
}
