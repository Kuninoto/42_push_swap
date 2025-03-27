/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:40:58 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/12/08 00:56:12 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max(t_stack *stack)
{
	int	max;
	int	i;

	max = stack->storage[BOTTOM];
	i = 0;
	while (i < stack->top)
	{
		if (stack->storage[i] > max)
			max = stack->storage[i];
		i += 1;
	}
	return (max);
}
