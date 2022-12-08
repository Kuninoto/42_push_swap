/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_case.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:44:56 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/12/08 01:01:27 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
/*
	2 1 0 sa rra
	3 1 2 rra 
	2 1 3 sa
*/

void	special_case(t_stack *a, t_stack *b)
{
	if ((a->int_list[a->top] > a->int_list[0])
		&& (a->int_list[a->top] > a->int_list[a->top + 1]))
	{
		write(1, "sa\n", 3);
		write(1, "rra\n", 4);
	}
	else if (a->int_list[a->top] > a->int_list[0])
		write(1, "rra\n", 4);
	else if ((a->int_list[a->top] < a->int_list[0]))
		write(1, "ra\n", 3);
	free_arrays(a, b);
	exit(EXIT_SUCCESS);
}
