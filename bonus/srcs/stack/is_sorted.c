/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 19:39:38 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/12/07 03:39:27 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

bool	is_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->top)
	{
		if (stack->storage[i] < stack->storage[i + 1])
			return (false);
		i += 1;
	}
	return (true);
}
