/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_case.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:44:56 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/12/06 18:19:54 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	special_case(t_stack *a)
{
	if (a->int_list[a->top] > a->int_list[0])
		rra(a);
	else if ((a->int_list[a->top] < a->int_list[0]))
		ra(a);
	exit(EXIT_SUCCESS);
}

// 3 1 2 rra
// 2 1 3 ra