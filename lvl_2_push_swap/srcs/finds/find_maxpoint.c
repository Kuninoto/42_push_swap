/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_maxpoint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:20:27 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/12/06 17:34:07 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	find_maxpoint(t_stack *stack)
{
	int	i;
	int	max;

	i = 0;
	max = stack->int_list[0];
	while (i < stack->top)
	{
		if (max < stack->int_list[i])
			max = stack->int_list[i];
		i++;
	}
	return (max);
}