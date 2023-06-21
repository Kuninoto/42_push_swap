/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_case.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:44:56 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/12/09 18:35:24 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	special_case(t_stack *a)
{
	if (a->storage[BOTTOM] < a->storage[1]
		&& a->storage[BOTTOM] < a->storage[2] && a->storage[1] < a->storage[2])
	{
		ft_putendl_fd("sa", STDOUT_FILENO);
		ft_putendl_fd("rra", STDOUT_FILENO);
	}
	else if (a->storage[BOTTOM] < a->storage[1]
		&& a->storage[BOTTOM] > a->storage[2] && a->storage[1] > a->storage[2])
	{
		ft_putendl_fd("rra", STDOUT_FILENO);
		ft_putendl_fd("sa", STDOUT_FILENO);
	}
	else if (a->storage[BOTTOM] < a->storage[1]
		&& a->storage[BOTTOM] < a->storage[2] && a->storage[1] > a->storage[2])
		ft_putendl_fd("rra", STDOUT_FILENO);
	else if (a->storage[BOTTOM] > a->storage[1]
		&& a->storage[BOTTOM] > a->storage[2] && a->storage[1] < a->storage[2])
		ft_putendl_fd("sa", STDOUT_FILENO);
	else if (a->storage[BOTTOM] > a->storage[1]
		&& a->storage[BOTTOM] < a->storage[2] && a->storage[1] < a->storage[2])
		ft_putendl_fd("ra", STDOUT_FILENO);
}
