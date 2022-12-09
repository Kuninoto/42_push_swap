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

#include "../includes/push_swap.h"
/*
	2 1 0 sa rra
	3 1 2 rra 
	2 1 3 sa
*/

void	special_case(t_stack *a, t_stack *b)
{
	if (a->int_list[0] < a->int_list[1] && a->int_list[0]
		< a->int_list[2] && a->int_list[1] < a->int_list[2])
	{
		write(STDOUT_FILENO, "sa\n", 3);
		write(STDOUT_FILENO, "rra\n", 4);
	}
	else if (a->int_list[0] < a->int_list[1] && a->int_list[0]
		> a->int_list[2] && a->int_list[1] > a->int_list[2])
	{
		write(STDOUT_FILENO, "rra\n", 4);
		write(STDOUT_FILENO, "sa\n", 3);
	}
	else if (a->int_list[0] < a->int_list[1] && a->int_list[0]
		< a->int_list[2] && a->int_list[1] > a->int_list[2])
		write(STDOUT_FILENO, "rra\n", 4);
	else if (a->int_list[0] > a->int_list[1] && a->int_list[0]
		> a->int_list[2] && a->int_list[1] < a->int_list[2])
		write(STDOUT_FILENO, "sa\n", 3);
	else if (a->int_list[0] > a->int_list[1] && a->int_list[0]
		< a->int_list[2] && a->int_list[1] < a->int_list[2])
		write(STDOUT_FILENO, "ra\n", 3);
	free_arrays(a, b);
	exit(EXIT_SUCCESS);
}
