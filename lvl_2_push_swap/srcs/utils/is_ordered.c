/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_ordered.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 23:51:54 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/12/08 23:52:05 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

bool	isordered(t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->top)
	{
		if (a->int_list[i] < a->int_list[i + 1])
			return (false);
		i++;
	}
	return (true);
}
